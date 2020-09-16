#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "glSetup.h"
#include <string.h>
#pragma comment(lib, "glew32.lib")

using namespace std;

bool perspectiveView = true;

float screenScale = 0.6;	//portion of the screen when not using full screen
int screenW = 0, screenH = 0;	//screenScale portion of the screen
int windowW, windowH;	//FrameBuffer size
float aspect;	//Aspect ratio = windowW/windowH
float dpiScaling = 0;	//DPI Scailing for HIDPI : windowW = dpiScaling x screenW

int vsync = 1;	//Vertical sync on/off

float fovy = 46.4;	//fovy of 28mm lens in degree

float nearDist = 1.0;
float farDist = 20.0;

void errorCallback(int error, const char* description)
{
	cout << "####" << description << endl;
}

void setupProjectionMatirx()
{
	if (perspectiveView)	gluPerspective(fovy, aspect, nearDist, farDist);
	else glOrtho(-1.0*aspect, 1.0*aspect, -1.0, 1.0, -nearDist, farDist);
}

// w and h are width and height of the framebuffer
void reshape(GLFWwindow* window, int w, int h)
{
	aspect = (float)w / h;

	//set the viewport
	windowW = w;
	windowH = h;
	glViewport(0, 0, w, h);

	//Initialize the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//set up a projection matrix
	setupProjectionMatirx();

	//The screen size is required for mouse interaction
	glfwGetWindowSize(window, &screenW, &screenH);
	cerr << "reshape(" << w << "," << h << ")";
	cerr << "with screen " << screenW << "x" << screenH << endl;
}

GLFWwindow* initializeOpenGL(int argc, char* argv[], GLfloat bgColor[4], bool modern)
{
	glfwSetErrorCallback(errorCallback);
	//Init GLFW
	if (!glfwInit()) exit(EXIT_FAILURE);

	if (modern)	//Enable OpenGL 4.1 in OS X
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_SAMPLES, 4);
	}
	else
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	}

	//create the window
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	int monitorW, monitorH;
	glfwGetMonitorPhysicalSize(monitor, &monitorW, &monitorH);
	cerr << "Status: Monitor " << monitorW << "mm x " << monitorH << "mm" << endl;

	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
	if (screenW == 0) screenW = videoMode->width * screenScale;
	if (screenH == 0) screenH = videoMode->height * screenScale;

	GLFWwindow* window = glfwCreateWindow(screenW, screenH, argv[0], NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		cerr << "Failed in glfwCreateWindow()" << endl;
		return NULL;
	}

	//Context
	glfwMakeContextCurrent(window);

	//Clear the background ASAP
	glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glfwSwapBuffers(window);

	//Check the size of the window
	glfwGetWindowSize(window, &screenW, &screenH);
	cerr << "Status: Screen " << screenW << " x " << screenH << endl;

	glfwGetFramebufferSize(window, &windowW, &windowH);
	cerr << "Status : FrameBuffer " << windowW << " x " << windowH << endl;

	//DPI scaling
	if (dpiScaling == 0)	dpiScaling = (float)(windowW) / screenW;

	//Callbacks
	glfwSetFramebufferSizeCallback(window, reshape);

	//Get the OpenGL version and renderer
	cout << "Status: Renderer " << glGetString(GL_RENDERER) << endl;
	cout << "Status: Vendor " << glGetString(GL_VENDOR) << endl;
	cout << "Status: OpenGL " << glGetString(GL_VERSION) << endl;

	//GLSL version for shader loading
	char glslVersion[256];
	strcpy(glslVersion, (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	cout << "Status: GLSL " << glslVersion << endl;

	//Vertical Sync
	glfwSwapInterval(vsync);
	cerr << "Status: GLEW" << glewGetString(GLEW_VERSION) << endl;
	//Initializing GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		cerr << "ERROR: " << glewGetErrorString(error) << endl;
		return 0;
	}
	return window;

}

void drawAxes(float l, float w)
{
	glLineWidth(w);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(l, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, l, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, l);
	glEnd();
}
