#version 440 core

struct Material 
{
    vec3 ambientColor;
    float ambientStrength;
    vec3 diffuseColor;
    vec3 specularColor;
    float shininess;
}; 

struct LightSource 
{
    vec3 position;	
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
    float focalStrength;
    float specularIntensity;
};

#define TOTAL_LIGHTS 4

in vec3 fragmentPosition;
in vec3 fragmentVertexNormal;
in vec2 fragmentTextureCoordinate;

out vec4 outFragmentColor;

uniform bool bUseTexture=false;
uniform bool bUseLighting=false;
uniform vec4 objectColor = vec4(1.0f);
uniform sampler2D objectTexture;
uniform vec3 viewPosition;
uniform vec2 UVscale = vec2(1.0f, 1.0f);
uniform LightSource lightSources[TOTAL_LIGHTS];
uniform Material material;

// function prototypes
vec3 CalcLightSource(LightSource light, vec3 lightNormal, vec3 vertexPosition, vec3 viewDirection);

void main()
{
   if(bUseLighting == true)
   {
      // properties
      vec3 lightNormal = normalize(fragmentVertexNormal);
      vec3 viewDirection = normalize(viewPosition - fragmentPosition);
      vec3 phongResult = vec3(0.0f);

      for(int i = 0; i < TOTAL_LIGHTS; i++)
      {
         phongResult += CalcLightSource(lightSources[i], lightNormal, fragmentPosition, viewDirection); 
      }   
    
      if(bUseTexture == true)
      {
         vec4 textureColor = texture(objectTexture, fragmentTextureCoordinate * UVscale);
         outFragmentColor = vec4(phongResult * textureColor.xyz, 1.0);
      }
      else
      {
         outFragmentColor = vec4(phongResult * objectColor.xyz, objectColor.w);
      }
   }
   else 
   {
      if(bUseTexture == true)
      {
         outFragmentColor = texture(objectTexture, fragmentTextureCoordinate * UVscale);
      }
      else
      {
         outFragmentColor = objectColor;
      }
   }
}

// calculates the color when using a directional light.
vec3 CalcLightSource(LightSource light, vec3 lightNormal, vec3 vertexPosition, vec3 viewDirection)
{
   vec3 ambient;
   vec3 diffuse;
   vec3 specular;

   //**Calculate Ambient lighting**
   ambient = light.ambientColor * (material.ambientColor * material.ambientStrength);

   //**Calculate Diffuse lighting**
   vec3 lightDirection = normalize(light.position - vertexPosition);
   float impact = max(dot(lightNormal, lightDirection), 0.0);
   diffuse = impact * light.diffuseColor * material.diffuseColor;

   //**Calculate Specular lighting (Blinn-Phong model)**
   vec3 halfDir = normalize(lightDirection + viewDirection);
   float specularComponent = pow(max(dot(lightNormal, halfDir), 0.0), material.shininess);
   specular = light.specularIntensity * specularComponent * material.specularColor * light.specularColor;

   //**Calculate Rim Lighting**
   float rim = 1.0 - max(dot(viewDirection, lightNormal), 0.0);
   rim = pow(rim, 2.0);
   vec3 rimLight = rim * light.specularColor * vec3(0.2, 0.2, 0.5);

   //**Apply attenuation**
   float distance = length(light.position - vertexPosition);
   float attenuation = 1.0 / (1.0 + 0.22 * distance + 0.20 * (distance * distance));
   diffuse *= attenuation;
   specular *= attenuation;
   rimLight *= attenuation;

   vec3 finalColor = ambient + diffuse + specular + rimLight;

   //**Gamma Correction**
   finalColor = pow(finalColor, vec3(1.0/2.2)); 

   return finalColor;
}
