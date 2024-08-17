///////////////////////////////////////////////////////////////////////////////
// shadermanager.cpp
// ============
// manage the loading and rendering of 3D scenes
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//	Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#include "SceneManager.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

#include <glm/gtx/transform.hpp>

// declaration of global variables
namespace
{
	const char* g_ModelName = "model";
	const char* g_ColorValueName = "objectColor";
	const char* g_TextureValueName = "objectTexture";
	const char* g_UseTextureName = "bUseTexture";
	const char* g_UseLightingName = "bUseLighting";
}

/***********************************************************
 *  SceneManager()
 *
 *  The constructor for the class
 ***********************************************************/
SceneManager::SceneManager(ShaderManager *pShaderManager)
{
	m_pShaderManager = pShaderManager;
	m_basicMeshes = new ShapeMeshes();
}

/***********************************************************
 *  ~SceneManager()
 *
 *  The destructor for the class
 ***********************************************************/
SceneManager::~SceneManager()
{
	m_pShaderManager = NULL;
	delete m_basicMeshes;
	m_basicMeshes = NULL;
}

/***********************************************************
 *  CreateGLTexture()
 *
 *  This method is used for loading textures from image files,
 *  configuring the texture mapping parameters in OpenGL,
 *  generating the mipmaps, and loading the read texture into
 *  the next available texture slot in memory.
 ***********************************************************/
bool SceneManager::CreateGLTexture(const char* filename, std::string tag)
{
	int width = 0;
	int height = 0;
	int colorChannels = 0;
	GLuint textureID = 0;

	// indicate to always flip images vertically when loaded
	stbi_set_flip_vertically_on_load(true);

	// try to parse the image data from the specified image file
	unsigned char* image = stbi_load(
		filename,
		&width,
		&height,
		&colorChannels,
		0);

	// if the image was successfully read from the image file
	if (image)
	{
		std::cout << "Successfully loaded image:" << filename << ", width:" << width << ", height:" << height << ", channels:" << colorChannels << std::endl;

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if the loaded image is in RGB format
		if (colorChannels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		// if the loaded image is in RGBA format - it supports transparency
		else if (colorChannels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		else
		{
			std::cout << "Not implemented to handle image with " << colorChannels << " channels" << std::endl;
			return false;
		}

		// generate the texture mipmaps for mapping textures to lower resolutions
		glGenerateMipmap(GL_TEXTURE_2D);

		// free the image data from local memory
		stbi_image_free(image);
		glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

		// register the loaded texture and associate it with the special tag string
		m_textureIDs[m_loadedTextures].ID = textureID;
		m_textureIDs[m_loadedTextures].tag = tag;
		m_loadedTextures++;

		return true;
	}

	std::cout << "Could not load image:" << filename << std::endl;

	// Error loading the image
	return false;
}

/***********************************************************
 *  BindGLTextures()
 *
 *  This method is used for binding the loaded textures to
 *  OpenGL texture memory slots.  There are up to 16 slots.
 ***********************************************************/
void SceneManager::BindGLTextures()
{
	for (int i = 0; i < m_loadedTextures; i++)
	{
		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[i].ID);
	}
}

/***********************************************************
 *  DestroyGLTextures()
 *
 *  This method is used for freeing the memory in all the
 *  used texture memory slots.
 ***********************************************************/
void SceneManager::DestroyGLTextures()
{
	for (int i = 0; i < m_loadedTextures; i++)
	{
		glGenTextures(1, &m_textureIDs[i].ID);
	}
}

/***********************************************************
 *  FindTextureID()
 *
 *  This method is used for getting an ID for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureID(std::string tag)
{
	int textureID = -1;
	int index = 0;
	bool bFound = false;

	while ((index < m_loadedTextures) && (bFound == false))
	{
		if (m_textureIDs[index].tag.compare(tag) == 0)
		{
			textureID = m_textureIDs[index].ID;
			bFound = true;
		}
		else
			index++;
	}

	return(textureID);
}

/***********************************************************
 *  FindTextureSlot()
 *
 *  This method is used for getting a slot index for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureSlot(std::string tag)
{
	int textureSlot = -1;
	int index = 0;
	bool bFound = false;

	while ((index < m_loadedTextures) && (bFound == false))
	{
		if (m_textureIDs[index].tag.compare(tag) == 0)
		{
			textureSlot = index;
			bFound = true;
		}
		else
			index++;
	}

	return(textureSlot);
}

/***********************************************************
 *  FindMaterial()
 *
 *  This method is used for getting a material from the previously
 *  defined materials list that is associated with the passed in tag.
 ***********************************************************/
bool SceneManager::FindMaterial(std::string tag, OBJECT_MATERIAL& material)
{
	if (m_objectMaterials.size() == 0)
	{
		return(false);
	}

	int index = 0;
	bool bFound = false;
	while ((index < m_objectMaterials.size()) && (bFound == false))
	{
		if (m_objectMaterials[index].tag.compare(tag) == 0)
		{
			bFound = true;
			material.ambientColor = m_objectMaterials[index].ambientColor;
			material.ambientStrength = m_objectMaterials[index].ambientStrength;
			material.diffuseColor = m_objectMaterials[index].diffuseColor;
			material.specularColor = m_objectMaterials[index].specularColor;
			material.shininess = m_objectMaterials[index].shininess;
		}
		else
		{
			index++;
		}
	}

	return(true);
}

/***********************************************************
 *  SetTransformations()
 *
 *  This method is used for setting the transform buffer
 *  using the passed in transformation values.
 ***********************************************************/
void SceneManager::SetTransformations(
	glm::vec3 scaleXYZ,
	float XrotationDegrees,
	float YrotationDegrees,
	float ZrotationDegrees,
	glm::vec3 positionXYZ)
{
	// variables for this method
	glm::mat4 modelView;
	glm::mat4 scale;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 translation;

	// set the scale value in the transform buffer
	scale = glm::scale(scaleXYZ);
	// set the rotation values in the transform buffer
	rotationX = glm::rotate(glm::radians(XrotationDegrees), glm::vec3(1.0f, 0.0f, 0.0f));
	rotationY = glm::rotate(glm::radians(YrotationDegrees), glm::vec3(0.0f, 1.0f, 0.0f));
	rotationZ = glm::rotate(glm::radians(ZrotationDegrees), glm::vec3(0.0f, 0.0f, 1.0f));
	// set the translation value in the transform buffer
	translation = glm::translate(positionXYZ);

	modelView = translation * rotationX * rotationY * rotationZ * scale;

	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setMat4Value(g_ModelName, modelView);
	}
}

/***********************************************************
 *  SetShaderColor()
 *
 *  This method is used for setting the passed in color
 *  into the shader for the next draw command
 ***********************************************************/
void SceneManager::SetShaderColor(
	float redColorValue,
	float greenColorValue,
	float blueColorValue,
	float alphaValue)
{
	// variables for this method
	glm::vec4 currentColor;

	currentColor.r = redColorValue;
	currentColor.g = greenColorValue;
	currentColor.b = blueColorValue;
	currentColor.a = alphaValue;

	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setIntValue(g_UseTextureName, false);
		m_pShaderManager->setVec4Value(g_ColorValueName, currentColor);
	}
}

/***********************************************************
 *  SetShaderTexture()
 *
 *  This method is used for setting the texture data
 *  associated with the passed in ID into the shader.
 ***********************************************************/
void SceneManager::SetShaderTexture(std::string textureTag)
{
	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setIntValue(g_UseTextureName, true);

		int textureID = -1;
		textureID = FindTextureSlot(textureTag);
		m_pShaderManager->setSampler2DValue(g_TextureValueName, textureID);
	}
}





/***********************************************************
 *  SetTextureUVScale()
 *
 *  This method is used for setting the texture UV scale
 *  values into the shader.
 ***********************************************************/
void SceneManager::SetTextureUVScale(float u, float v)
{
	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setVec2Value("UVscale", glm::vec2(u, v));
	}
}

/***********************************************************
  *  LoadSceneTextures()
  *
  *  This method is used for preparing the 3D scene by loading
  *  the shapes, textures in memory to support the 3D scene
  *  rendering
  ***********************************************************/
void SceneManager::LoadSceneTextures()
{
	/*** STUDENTS - add the code BELOW for loading the textures that ***/
	/*** will be used for mapping to objects in the 3D scene. Up to  ***/
	/*** 16 textures can be loaded per scene. Refer to the code in   ***/
	/*** the OpenGL Sample for help.                                 ***/
	//added more textures
	bool bReturn = false;

	//removed loading the deault textures
	// all textures called are within VS project
	//texture created by me
	bReturn = CreateGLTexture(
		"textures/arcbest.png",
		"arcbest");
	bReturn = CreateGLTexture(
		"textures/black.png",
		"black");
	bReturn = CreateGLTexture(
		"textures/Alpha.png",
		"alpha");
	bReturn = CreateGLTexture(
		"textures/baloon.png",
		"baloon");
	//desgined by freekpik.com
	bReturn = CreateGLTexture(
		"textures/white.jpg",
		"coffecup");
	bReturn = CreateGLTexture(
		"textures/arcbest.jpg",
		"coffecup");
	bReturn = CreateGLTexture(
		"textures/orange.jpg",
		"saucepan_handle");
	bReturn = CreateGLTexture(
		"textures/orangedarker.jpg",
		"saucepan_orange");
	bReturn = CreateGLTexture(
		"textures/papertowel.jpg",
		"paper_towel");
	//edited this texture
	bReturn = CreateGLTexture(
		"textures/metalOrange.jpg",
		"metalOrange");

	// after the texture image data is loaded into memory, the
	// loaded textures need to be bound to texture slots - there
	// are a total of 16 available slots for scene textures
	BindGLTextures();
}


/***********************************************************
 *  SetShaderMaterial()
 *
 *  This method is used for passing the material values
 *  into the shader.
 ***********************************************************/
void SceneManager::SetShaderMaterial(
	std::string materialTag)
{
	if (m_objectMaterials.size() > 0)
	{
		OBJECT_MATERIAL material;
		bool bReturn = false;

		// find the defined material that matches the tag
		bReturn = FindMaterial(materialTag, material);
		if (bReturn == true)
		{
			// pass the material properties into the shader
			m_pShaderManager->setVec3Value("material.ambientColor", material.ambientColor);
			m_pShaderManager->setFloatValue("material.ambientStrength", material.ambientStrength);
			m_pShaderManager->setVec3Value("material.diffuseColor", material.diffuseColor);
			m_pShaderManager->setVec3Value("material.specularColor", material.specularColor);
			m_pShaderManager->setFloatValue("material.shininess", material.shininess);
		}
	}
}

/**************************************************************/
/*** STUDENTS CAN MODIFY the code in the methods BELOW for  ***/
/*** preparing and rendering their own 3D replicated scenes.***/
/*** Please refer to the code in the OpenGL sample project  ***/
/*** for assistance.                                        ***/
/**************************************************************/

/***********************************************************
  *  DefineObjectMaterials()
  *
  *  This method is used for configuring the various material
  *  settings for all of the objects within the 3D scene.
  ***********************************************************/
void SceneManager::DefineObjectMaterials()
{
	/*** STUDENTS - add the code BELOW for defining object materials. ***/
	/*** There is no limit to the number of object materials that can ***/
	/*** be defined. Refer to the code in the OpenGL Sample for help  ***/

	// Define black glass material for a table
	OBJECT_MATERIAL blackGlassMaterial;
	blackGlassMaterial.ambientColor = glm::vec3(0.05f, 0.05f, 0.05f);  // Very dim ambient reflection to give a dark appearance
	blackGlassMaterial.ambientStrength = 0.1f;                         // Lower ambient strength to make it appear dark
	blackGlassMaterial.diffuseColor = glm::vec3(0.1f, 0.1f, 0.1f);     // Dark color for diffuse reflection
	blackGlassMaterial.specularColor = glm::vec3(0.9f, 0.9f, 0.9f);    // High specular reflection to simulate glass
	blackGlassMaterial.shininess = 100.0f;                             // Very high shininess for a glossy surface
	blackGlassMaterial.tag = "table";                             // Tag to identify this material

	m_objectMaterials.push_back(blackGlassMaterial);

	// Define white porcelain material for a coffee mug
	OBJECT_MATERIAL whitePorcelainMaterial;
	whitePorcelainMaterial.ambientColor = glm::vec3(0.9f, 0.9f, 0.9f);  // Lightly dim ambient reflection for a bright appearance
	whitePorcelainMaterial.ambientStrength = 0.4f;                      // Moderate ambient strength
	whitePorcelainMaterial.diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f);  // Pure white color for diffuse reflection
	whitePorcelainMaterial.specularColor = glm::vec3(0.8f, 0.8f, 0.8f); // High specular reflection to mimic the glossiness of porcelain
	whitePorcelainMaterial.shininess = 80.0f;                           // High shininess for a smooth, reflective surface
	whitePorcelainMaterial.tag = "coffemug";                      // Tag to identify this material

	m_objectMaterials.push_back(whitePorcelainMaterial);

	// Define orange material for a saucepan
	OBJECT_MATERIAL orangeSaucepanMaterial;
	orangeSaucepanMaterial.ambientColor = glm::vec3(0.8f, 0.4f, 0.1f);  // Warm orange ambient reflection
	orangeSaucepanMaterial.ambientStrength = 0.5f;                       // Moderate ambient strength
	orangeSaucepanMaterial.diffuseColor = glm::vec3(1.0f, 0.5f, 0.2f);   // Bright orange color for diffuse reflection
	orangeSaucepanMaterial.specularColor = glm::vec3(0.1f, 0.1f, 0.1f);  // Very minimal specular reflection for a less shiny appearance
	orangeSaucepanMaterial.shininess = 8.0f;                             // Low shininess for a matte or less reflective look
	orangeSaucepanMaterial.tag = "saucepan";                        // Tag to identify this material

	// Add the material to the materials list
	m_objectMaterials.push_back(orangeSaucepanMaterial);

	// Define paper towel roll material
	OBJECT_MATERIAL paperTowelMaterial;
	paperTowelMaterial.ambientColor = glm::vec3(0.9f, 0.9f, 0.85f);  // Light beige/white color for ambient reflection
	paperTowelMaterial.ambientStrength = 0.3f;                        // Moderate ambient strength to give it a soft appearance
	paperTowelMaterial.diffuseColor = glm::vec3(0.95f, 0.95f, 0.9f);  // Slightly off-white color for diffuse reflection
	paperTowelMaterial.specularColor = glm::vec3(0.2f, 0.2f, 0.2f);   // Low specular reflection to keep it matte
	paperTowelMaterial.shininess = 10.0f;                             // Low shininess for a non-glossy finish
	paperTowelMaterial.tag = "paperTowelRoll";                        // Tag to identify this material

	m_objectMaterials.push_back(paperTowelMaterial);

	// Define balloon material
	OBJECT_MATERIAL balloonMaterial;
	balloonMaterial.ambientColor = glm::vec3(0.8f, 0.0f, 0.0f);  // Bright red ambient reflection
	balloonMaterial.ambientStrength = 0.5f;                      // Moderate ambient strength to make it pop
	balloonMaterial.diffuseColor = glm::vec3(1.0f, 0.0f, 0.0f);  // Pure red color for diffuse reflection
	balloonMaterial.specularColor = glm::vec3(0.9f, 0.9f, 0.9f); // High specular reflection to mimic the glossy surface
	balloonMaterial.shininess = 100.0f;                          // High shininess for a glossy, reflective finish
	balloonMaterial.tag = "balloon";                             // Tag to identify this material

	m_objectMaterials.push_back(balloonMaterial);

}

/***********************************************************
 *  SetupSceneLights()
 *
 *  This method is called to add and configure the light
 *  sources for the 3D scene.  There are up to 4 light sources.
 ***********************************************************/
void SceneManager::SetupSceneLights()
{
	// this line of code is NEEDED for telling the shaders to render 
	// the 3D scene with custom lighting, if no light sources have
	// been added then the display window will be black - to use the 
	// default OpenGL lighting then comment out the following line
	//m_pShaderManager->setBoolValue(g_UseLightingName, true);

	/*** STUDENTS - add the code BELOW for setting up light sources ***/
	/*** Up to four light sources can be defined. Refer to the code ***/
	/*** in the OpenGL Sample for help                              ***/

	// First light source - Pure white light, positioned above the scene
	m_pShaderManager->setVec3Value("lightSources[0].position", 0.0f, 14.0f, 3.0f);  // Position of the light source
	m_pShaderManager->setVec3Value("lightSources[0].ambientColor", 1.0f, 1.0f, 1.0f);  // Pure white ambient light
	m_pShaderManager->setVec3Value("lightSources[0].diffuseColor", 1.0f, 1.0f, 1.0f);  // Pure white diffuse light
	m_pShaderManager->setVec3Value("lightSources[0].specularColor", 1.0f, 1.0f, 1.0f); // Pure white specular highlights
	m_pShaderManager->setFloatValue("lightSources[0].focalStrength", 100.0f);  // Sharpness of the light
	m_pShaderManager->setFloatValue("lightSources[0].specularIntensity", 1.0f); // Specular intensity

	// Second light source - Warm colored point light, positioned to the side
	m_pShaderManager->setVec3Value("lightSources[1].position", -10.0f, 8.0f, -10.0f);  // Position of the second light source
	m_pShaderManager->setVec3Value("lightSources[1].ambientColor", 0.5f, 0.3f, 0.2f);  // Warm ambient light (reddish)
	m_pShaderManager->setVec3Value("lightSources[1].diffuseColor", 0.8f, 0.5f, 0.3f);  // Warm diffuse light
	m_pShaderManager->setVec3Value("lightSources[1].specularColor", 0.9f, 0.7f, 0.5f); // Warm specular highlights
	m_pShaderManager->setFloatValue("lightSources[1].focalStrength", 50.0f);  // Sharpness of the light (lower than the first light for a softer effect)
	m_pShaderManager->setFloatValue("lightSources[1].specularIntensity", 0.8f); // Specular intensity




	// Activate lighting in the shader
	m_pShaderManager->setBoolValue("bUseLighting", true);



}

/***********************************************************
 *  PrepareScene()
 *
 *  This method is used for preparing the 3D scene by loading
 *  the shapes, textures in memory to support the 3D scene 
 *  rendering
 ***********************************************************/
void SceneManager::PrepareScene()
{
	// define the materials for objects in the scene
	DefineObjectMaterials();
	// add and define the light sources for the scene
	SetupSceneLights();
	// load the textures for the 3D scene
	LoadSceneTextures();

	// only one instance of a particular mesh needs to be
	// loaded in memory no matter how many times it is drawn
	// in the rendered 3D scene

	m_basicMeshes->LoadPlaneMesh();

	m_basicMeshes->LoadCylinderMesh();//loading in additional assets
	m_basicMeshes->LoadTorusMesh();
	m_basicMeshes->LoadSphereMesh();
	m_basicMeshes->LoadConeMesh();
}

/***********************************************************
 *  RenderScene()
 *
 *  This method is used for rendering the 3D scene by 
 *  transforming and drawing the basic 3D shapes
 ***********************************************************/
void SceneManager::RenderScene()
{
	// declare the variables for the transformations
	glm::vec3 scaleXYZ;
	float XrotationDegrees = 0.0f;
	float YrotationDegrees = 0.0f;
	float ZrotationDegrees = 0.0f;
	glm::vec3 positionXYZ;

	/*** Set needed transformations before drawing the basic mesh.  ***/
	/*** This same ordering of code should be used for transforming ***/
	/*** and drawing all the basic 3D shapes.						***/
	/******************************************************************/
	// set the XYZ scale for the mesh
	/***						Table								***/
	scaleXYZ = glm::vec3(20.0f, 1.0f, 10.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(0.0f, 0.0f, 0.0f);

	// set the transformations into memory to be used on the drawn meshes
	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	SetShaderColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 200/255.0f);
	//setShader
	SetShaderMaterial("table");
	// draw the mesh with transformation values
	m_basicMeshes->DrawPlaneMesh();
	/******************************************************************/
	/***						Wall								***/
	scaleXYZ = glm::vec3(40.0f, 1.0f, 10.0f);

	XrotationDegrees = 90.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	positionXYZ = glm::vec3(0.0f, 9.0f, -10.0f);

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	SetShaderColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 200 / 255.0f);

	// draw the mesh with transformation values
	//m_basicMeshes->DrawPlaneMesh(); // Didnt want to draw wall yet
	/******************************************************************/
	/***				Cylinder for coffer Cup						***/
	scaleXYZ = glm::vec3(2.0f, 3.0f, 2.0f);

	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	positionXYZ = glm::vec3(10.0f, 0.0f, 6.0f);

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//SetShaderColor(8 / 255.0f, 144 / 255.0f, 44 / 255.0f, 1);
	SetShaderTexture("coffecup");
	//setShader
	SetShaderMaterial("coffemug");

	m_basicMeshes->DrawCylinderMesh(); 
	/******************************************************************/
	/***				Torus for coffer Cup						***/
	scaleXYZ = glm::vec3(1.0f, 1.0f, 2.0f);

	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 00.0f;

	positionXYZ = glm::vec3(8.0f, 1.5f, 6.0f);

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//SetShaderColor(255 / 255.0f, 14 / 255.0f, 44 / 255.0f, 1);
	SetShaderTexture("coffecup");
	//setShader
	SetShaderMaterial("coffemug");

	m_basicMeshes->DrawTorusMesh();
	/******************************************************************/
	/***			Cylinder for Sauce pan body						***/
	scaleXYZ = glm::vec3(4.0f, 2.5f, 4.0f);

	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	positionXYZ = glm::vec3(-4.0f, 0.0f, 4.0f);

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//SetShaderColor(255 / 255.0f, 144 / 255.0f, 15 / 255.0f, 1);
	//added texture
	SetShaderTexture("saucepan_orange");
	//Adresses Stretching and tiles image, the tiling doesnt look that great. I almost think this texture looks better non tiled. 
	SetTextureUVScale(200.0f, 200.0f);
	//setShader
	SetShaderMaterial("saucepan");

	m_basicMeshes->DrawCylinderMesh();
	/******************************************************************/
	/***			Cylinder for Sauce pan handle					***/
	scaleXYZ = glm::vec3(0.5f, 6.0f, 0.5f);

	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 90.0f;

	positionXYZ = glm::vec3(-7.0f, 2.0f,5.0f);

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//SetShaderColor(255 / 255.0f, 14 / 255.0f, 44 / 255.0f, 1);
	SetShaderTexture("saucepan_orange");
	//setShader
	SetShaderMaterial("saucepan");
	m_basicMeshes->DrawCylinderMesh();
	/******************************************************************/
	/******************************************************************/
	/***				Cylinder for Paper Towel Roll				***/
	scaleXYZ = glm::vec3(2.5f, 9.0f, 2.5f);  // Adjusted scale

	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	positionXYZ = glm::vec3(-8.0f, 0.0f, -4.0f);  // Adjusted position

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//set texture
	SetShaderTexture("paper_towel");
	//set tiling
	SetTextureUVScale(1.0f, 1.0f);
	//setShader
	SetShaderMaterial("paperTowelRoll");
	m_basicMeshes->DrawCylinderMesh();
	/******************************************************************/
	/******************************************************************/
	/***				Sphere for Balloon Body					***/
	scaleXYZ = glm::vec3(4.0f, 4.5f, 4.0f);  // Adjusted balloon shape to make it smaller

	XrotationDegrees = -45.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = -45.0f;

	positionXYZ = glm::vec3(7.0f, 3.75f, -4.0f);  // Adjusted position to place it on the correct side of the paper towel roll

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//set texture
	SetShaderTexture("baloon");
	//setShader
	SetShaderMaterial("balloon");
	m_basicMeshes->DrawSphereMesh();
	/******************************************************************/
	/******************************************************************/
	/***				Torus for Balloon Knot						***/
	scaleXYZ = glm::vec3(0.5f, 0.5f, 0.5f);  // Smaller scale for the knot

	XrotationDegrees = -45.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = -45.0f;

	positionXYZ = glm::vec3(3.6f, 1.35f, -1.55f);  // Position just below the balloon body

	SetTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	//set texture
	SetShaderTexture("baloon");
	//setShader
	SetShaderMaterial("balloon");
	m_basicMeshes->DrawConeMesh();
	/******************************************************************/




}


