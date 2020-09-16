#include <Windows.h>
#include "glSetup.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
using namespace glm;
int rotate1 = 28;
int rotate2 = 18;
void init();
void quit();
void render(GLFWwindow * window);
void keyboard(GLFWwindow * window, int key, int code, int action, int mods);

bool readMesh(const char * fileName);
void deleteMesh();
int k = 0;
vec3 vecArr[36][18];
vec3 eye(3, 4, 3);
vec3 center(0, 0, 0);
vec3 up(0, 1, 0);
//vec3 circleCenter[36];



//Global cooridnate frame
float AXIS_LENGTH = 20;
float AXIS_LINE_WIDTH = 2;
int l = 0;

//Colors
GLfloat bgColor[4] = { 1,1,1,1 };


//Selected example 
int selection = 2;

int main(int argc, char* argv[])
{
	GLFWwindow * window = initializeOpenGL(argc, argv, bgColor);
	if (window == NULL) { return -1; }

	//Callbacks
	glfwSetKeyCallback(window, keyboard);

	//Normal vectors are normailized after Transformation
	glEnable(GL_NORMALIZE);

	//Viewport and perspective stting
	reshape(window, windowW, windowH);

	//initialization - Main Loop - Finalization
	init();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		render(window);
		glfwSwapBuffers(window);
	}

	//Finalization
	quit();

	//Terminate the glfw System
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void init()
{
	vec4 startOfCircle(1, 1.3, 0.0, 1.0);
	vecArr[0][0] = vec3(1, 1.3, 0.0);
	float angle1 = 20 * M_PI / 180;
	float angle2 = 10 * M_PI / 180;
	mat4 rotationMatrix1 = mat4(1.0f);
	mat4 rotationMatrix2 = mat4(1.0f);
	for (int i = 1; i < 18; i++)
	{
		rotationMatrix1 = translate(rotationMatrix1, vec3(1, 1, 0));
		rotationMatrix1 = rotate(rotationMatrix1, angle1, vec3(0, 0, 1));
		rotationMatrix1 = translate(rotationMatrix1, vec3(-1, -1, 0));
		vecArr[0][i] = rotationMatrix1 * startOfCircle;
	}
	for (int i = 1; i < 36; i++)
	{
		rotationMatrix2 = rotate(rotationMatrix2, angle2, vec3(0, 1, 0));
		for (int j = 0; j < 18; j++)
		{
			vecArr[i][j] = rotationMatrix2 * vec4(vecArr[0][j], 0);
		}
	}

	//Keyboard
	cout << "Keyboard input: s for turn on/off smooth shading" << endl;
	cout << "Keyboard input: 1 for sphere with 16 slices and 16 stacks" << endl;
	cout << "Keyboard input: 2 for sphere with 32 slices and 32 stacks" << endl;
	cout << "Keyboard input: 3 for sphere with 64 slices and 64 stacks" << endl;
	cout << "Keyboard input: 4 for sphere with 128 slices and 128 stacks" << endl;
	cout << "Keyboard input: 5 for smooth approximation of a bunny" << endl;
	cout << "Keyboard input: 6 for flat approximation of a bunny" << endl;
}
void drawPoints()
{
	glPointSize(3.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			glVertex3f(vecArr[i][j].x, vecArr[i][j].y, vecArr[i][j].z);
		}
	}
	glEnd();
	glFinish();
}
void drawWireFrame()
{
	if (rotate1 < 1)	rotate1 = 1;
	if (rotate1 > 36)	rotate1 = 36;
	if (rotate2 < 1)	rotate2 = 1;
	if (rotate2 > 18)	rotate2 = 18;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);

	//int j = 0;
	glColor3f(0, 0, 0);
	for (int i = 0; i < rotate1; i++)
	{
		for (int j = 0; j < rotate2; j++)
		{
			glVertex3f(vecArr[i][j].x, vecArr[i][j].y, vecArr[i][j].z);
			if (i != 35)
				glVertex3f(vecArr[i + 1][j].x, vecArr[i + 1][j].y, vecArr[i + 1][j].z);
			else
				glVertex3f(vecArr[0][j].x, vecArr[0][j].y, vecArr[0][j].z);
			if (i != 35 && j != 17)
				glVertex3f(vecArr[i + 1][j + 1].x, vecArr[i + 1][j + 1].y, vecArr[i + 1][j + 1].z);
			else
			{
				if (i == 35 && j != 17)
					glVertex3f(vecArr[0][j + 1].x, vecArr[0][j + 1].y, vecArr[0][j + 1].z);
				else if (i != 35 && j == 17)
					glVertex3f(vecArr[i + 1][0].x, vecArr[i + 1][0].y, vecArr[i + 1][0].z);
				else
					glVertex3f(vecArr[0][0].x, vecArr[0][0].y, vecArr[0][0].z);
			}
			if (j != 17)
				glVertex3f(vecArr[i][j + 1].x, vecArr[i][j + 1].y, vecArr[i][j + 1].z);
			else
				glVertex3f(vecArr[i][0].x, vecArr[i][j + 1].y, vecArr[i][0].z);
		}
	}
	glEnd();
	glFinish();
}
void drawTorus()
{

	glRotatef(-60, 0, 0, 1);
	drawPoints();
}

void quit()
{

}

void render(GLFWwindow * window)
{
	//Background Color	
	glClearColor(bgColor[0], bgColor[1], bgColor[3], bgColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//ModelView matrix 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	//Axes

	drawAxes(AXIS_LENGTH, AXIS_LINE_WIDTH);

	switch (selection)
	{
	case 1: drawPoints(); break;
	case 2: drawWireFrame(); break;
	}

}

void keyboard(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_1: selection = 1; break;
		case GLFW_KEY_2: selection = 2; break;
		case GLFW_KEY_A: rotate1--; drawWireFrame; break;
		case GLFW_KEY_D: rotate1++; drawWireFrame; break;
		case GLFW_KEY_W: rotate2++; drawWireFrame; break;
		case GLFW_KEY_S: rotate2--; drawWireFrame; break;

		}
	}
}