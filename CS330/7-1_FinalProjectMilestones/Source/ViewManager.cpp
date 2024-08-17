///////////////////////////////////////////////////////////////////////////////
// viewmanager.h
// ============
// manage the viewing of 3D objects within the viewport
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//	Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#include "ViewManager.h"

// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>    

// declaration of the global variables and defines
namespace
{
	// Variables for window width and height
	const int WINDOW_WIDTH = 1000;
	const int WINDOW_HEIGHT = 800;
	const char* g_ViewName = "view";
	const char* g_ProjectionName = "projection";

	// camera object used for viewing and interacting with
	// the 3D scene
	Camera* g_pCamera = nullptr;

	// these variables are used for mouse movement processing
	float gLastX = WINDOW_WIDTH / 2.0f;
	float gLastY = WINDOW_HEIGHT / 2.0f;
	bool gFirstMouse = true;

	//These are used for scroll Wheel
	float gScrollLastX = WINDOW_WIDTH / 2.0f;
	float gScrollLastY = WINDOW_HEIGHT / 2.0f;
	bool gFirstScroll = true;

	// time between current frame and last frame
	float gDeltaTime = 0.0f;
	float gLastFrame = 0.0f;
	float gSpeedMultiplier = 1.0f;

	// the following variable is false when orthographic projection
	// is off and true when it is on
	bool bOrthographicProjection = false;
}

/***********************************************************
 *  ViewManager()
 *
 *  The constructor for the class
 ***********************************************************/
ViewManager::ViewManager(
	ShaderManager *pShaderManager)
{
	// initialize the member variables
	m_pShaderManager = pShaderManager;
	m_pWindow = NULL;
	g_pCamera = new Camera();
	// default camera view parameters
	g_pCamera->Position = glm::vec3(0.0f, 7.0f, 25.0f);
	g_pCamera->Front = glm::vec3(0.0f, -0.5f, -2.0f);
	g_pCamera->Up = glm::vec3(0.0f, 1.0f, 0.0f);
	g_pCamera->Zoom = 80;
}

/***********************************************************
 *  ~ViewManager()
 *
 *  The destructor for the class
 ***********************************************************/
ViewManager::~ViewManager()
{
	// free up allocated memory
	m_pShaderManager = NULL;
	m_pWindow = NULL;
	if (NULL != g_pCamera)
	{
		delete g_pCamera;
		g_pCamera = NULL;
	}
}

/***********************************************************
 *  CreateDisplayWindow()
 *
 *  This method is used to create the main display window.
 ***********************************************************/
GLFWwindow* ViewManager::CreateDisplayWindow(const char* windowTitle)
{
	GLFWwindow* window = nullptr;

	// try to create the displayed OpenGL window
	window = glfwCreateWindow(
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		windowTitle,
		NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	// tell GLFW to capture all mouse events
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// this callback is used to receive mouse moving events
	glfwSetCursorPosCallback(window, &ViewManager::Mouse_Position_Callback);

	// this callback is used to receive mouse wheel scrolling events
	glfwSetScrollCallback(window, &ViewManager::Mouse_Scroll_Wheel_Callback);

	// enable blending for supporting tranparent rendering
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_pWindow = window;

	return(window);
}

/***********************************************************
 *  Mouse_Position_Callback()
 *
 *  This method is automatically called from GLFW whenever
 *  the mouse is moved within the active GLFW display window.
 ***********************************************************/
void ViewManager::Mouse_Position_Callback(GLFWwindow* window, double xMousePos, double yMousePos)
{
	// when the first mouse move event is received, this needs to be recorded so that
	// all subsequent mouse moves can correctly calculate the X position offset and Y
	// position offset for proper operation
	if (gFirstMouse)
	{
		gLastX = xMousePos;
		gLastY = yMousePos;
		gFirstMouse = false;
	}

	// calculate the X offset and Y offset values for moving the 3D camera accordingly
	float xOffset = xMousePos - gLastX;
	float yOffset = gLastY - yMousePos; // reversed since y-coordinates go from bottom to top

	// set the current positions into the last position variables
	gLastX = xMousePos;
	gLastY = yMousePos;

	// Adjust sensitivity for wider range of motion
	float sensitivity = 10.0f; // Adjust this value as needed
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	// move the 3D camera according to the calculated offsets
	g_pCamera->ProcessMouseMovement(xOffset, yOffset);
}

/***********************************************************
 *  Mouse_Scroll_Wheel_Callback()
 *
 *  This method is automatically called from GLFW whenever
 *  the mouse wheel is scrolled within the active GLFW display window.
 ***********************************************************/
void ViewManager::Mouse_Scroll_Wheel_Callback(GLFWwindow* window, double xScrollPos, double yScrollPos)
{
	// When the first mouse scroll event is received, record the position
	// to correctly calculate subsequent scroll offsets
	if (gFirstScroll)
	{
		gScrollLastX = xScrollPos;
		gScrollLastY = yScrollPos;
		gFirstScroll = false;
	}

	// Calculate the Y offset value for adjusting the speed multiplier
	// Scaling factor (0.05f) is used to fine-tune the sensitivity of the scroll wheel
	float yOffset = (yScrollPos - gScrollLastX) * 0.05f;

	// Adjust the speed multiplier based on the Y offset value
	gSpeedMultiplier += yOffset;

	// Clamp the speed multiplier to ensure it stays within a reasonable range
	if (gSpeedMultiplier < 0.25f) {
		gSpeedMultiplier = 0.25f;
	}
	else if (gSpeedMultiplier > 5.0f) {
		gSpeedMultiplier = 5.0f;
	}

	// Update the last scroll position variables
	gScrollLastY = yScrollPos;
}


/***********************************************************
 *  ProcessKeyboardEvents()
 *
 *  This method is called to process any keyboard events
 *  that may be waiting in the event queue.
 ***********************************************************/
void ViewManager::ProcessKeyboardEvents()
{
	// close the window if the escape key has been pressed
	if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_pWindow, true);
	}

	// if the camera object is null, then exit this method
	if (NULL == g_pCamera)
	{
		return;
	}

	// process camera zooming in and out
	if (glfwGetKey(m_pWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(FORWARD, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(BACKWARD, gDeltaTime);
	}

	// process camera panning left and right
	if (glfwGetKey(m_pWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(LEFT, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(RIGHT, gDeltaTime);
	}

	// process camera panning up and down
	if (glfwGetKey(m_pWindow, GLFW_KEY_E) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(UP, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_Q) == GLFW_PRESS)
	{
		g_pCamera->ProcessKeyboard(DOWN, gDeltaTime);
	}
	//perspective switching
	if (glfwGetKey(m_pWindow, GLFW_KEY_P) == GLFW_PRESS)
	{
		bOrthographicProjection = false;
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_O) == GLFW_PRESS)
	{
		bOrthographicProjection = true;
	}
	/*Rotation this screws with Ortho and Perspective 
	* TODO: needs work if I have time
	if (glfwGetKey(m_pWindow, GLFW_KEY_R) == GLFW_PRESS) {
		RotateCamera(10.0f, 0.0f); // Rotate around Y axis
	}*/

}
/* Rotate Camera Clockwise i owe a great portion of this to StackOverflow
* This is not the only post but it was the most helpful. 
* https://stackoverflow.com/questions/58264255/have-problem-understanding-translating-the-camera-in-opengl
* several sources like The Red Book 9th edition and the website linked below.
* https://learnopengl.com/Getting-started/Camera
* I really just didnt like not being able to rotate around camera it was quite annoying trying to move from perspective.
* I realize now left and right perspectives probably would have been simplere and that may be what i actually do to work better with Ortho and Perspective views
*/
void ViewManager::RotateCamera(float yaw, float pitch) {
	// Scale the yaw and pitch by the sensitivity factor
	float sensitivity = 0.1f;
	float scaledYaw = yaw * sensitivity;
	float scaledPitch = pitch * sensitivity;

	// Update the camera's yaw and pitch
	g_pCamera->Yaw += scaledYaw;
	g_pCamera->Pitch += scaledPitch;

	// Constrain the pitch to prevent screen flipping
	if (g_pCamera->Pitch > 89.0f)
		g_pCamera->Pitch = 89.0f;
	if (g_pCamera->Pitch < -89.0f)
		g_pCamera->Pitch = -89.0f;

	// Update the camera's front vector based on the new yaw and pitch
	glm::vec3 front;
	front.x = cos(glm::radians(g_pCamera->Yaw)) * cos(glm::radians(g_pCamera->Pitch));
	front.y = sin(glm::radians(g_pCamera->Pitch));
	front.z = sin(glm::radians(g_pCamera->Yaw)) * cos(glm::radians(g_pCamera->Pitch));
	g_pCamera->Front = glm::normalize(front);

	// Also re-calculate the Right and Up vector
	g_pCamera->Right = glm::normalize(glm::cross(g_pCamera->Front, g_pCamera->WorldUp));
	g_pCamera->Up = glm::normalize(glm::cross(g_pCamera->Right, g_pCamera->Front));
}

// Get Perspective Projection Matrix
glm::mat4 ViewManager::GetPerspectiveProjectionMatrix()
{
	return glm::perspective(glm::radians(g_pCamera->Zoom), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
}

// Get Orthographic Projection Matrix
glm::mat4 ViewManager::GetOrthographicProjectionMatrix()
{
	float orthoScale = 10.0f; // Adjust as needed
	return glm::ortho(-orthoScale, orthoScale, -orthoScale, orthoScale, 0.1f, 100.0f);
}

/***********************************************************
 *  PrepareSceneView()
 *
 *  This method is used for preparing the 3D scene by loading
 *  the shapes, textures in memory to support the 3D scene 
 *  rendering
 ***********************************************************/
void ViewManager::PrepareSceneView()
{
	glm::mat4 view;
	glm::mat4 projection;

	// per-frame timing gSpeedMultiplyer allows for scroll actions to speed up movements
	float currentFrame = glfwGetTime();
	gDeltaTime = (currentFrame - gLastFrame) * gSpeedMultiplier;
	gLastFrame = currentFrame;

	// process any keyboard events that may be waiting in the 
	// event queue
	ProcessKeyboardEvents();

	// get the current view matrix from the camera
	view = g_pCamera->GetViewMatrix();

	// define the current projection matrix
	projection = glm::perspective(glm::radians(g_pCamera->Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);

	if (bOrthographicProjection)
	{
		projection = GetOrthographicProjectionMatrix();
	}
	else
	{
		projection = GetPerspectiveProjectionMatrix();
	}

	// if the shader manager object is valid
	if (NULL != m_pShaderManager)
	{
		// set the view matrix into the shader for proper rendering
		m_pShaderManager->setMat4Value(g_ViewName, view);
		// set the view matrix into the shader for proper rendering
		m_pShaderManager->setMat4Value(g_ProjectionName, projection);
		// set the view position of the camera into the shader for proper rendering
		m_pShaderManager->setVec3Value("viewPosition", g_pCamera->Position);
	}
}