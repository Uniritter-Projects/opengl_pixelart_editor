//Mapeamento de teclas na GLFW: https://www.glfw.org/docs/latest/group__keys.html
#include <cstdlib>
#include <iostream>
#include "Shapes.h"
using namespace std;

Shape shape;

void ajustaCamera2D(int width, int height);

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

bool onEditor = true;

int xPos = 0;
int yPos = 0;
int crrColour = 1;
int crrSize = 8;
bool gridVisible = true;
bool deleting = false;

int matrix[16][16];

void clearMatrix()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void setInitialDraw()
{
	matrix[0][0] = 2;
	matrix[0][1] = 2;
	matrix[0][2] = 2;
	matrix[0][3] = 2;
	matrix[0][4] = 2;
	matrix[0][5] = 2;
	matrix[0][6] = 2;
	matrix[0][7] = 2;

	matrix[1][0] = 2;
	matrix[1][1] = 2;
	matrix[1][2] = 2;
	matrix[1][3] = 2;
	matrix[1][4] = 2;
	matrix[1][5] = 2;
	matrix[1][6] = 2;
	matrix[1][7] = 2;

	matrix[2][0] = 2;
	matrix[2][1] = 2;
	matrix[2][5] = 9;

	matrix[3][0] = 2;
	matrix[3][1] = 2;

	matrix[4][0] = 2;
	matrix[4][1] = 2;
	matrix[4][3] = 9;
	matrix[4][6] = 9;

	matrix[5][0] = 2;
	matrix[5][1] = 2;
	matrix[5][2] = 2;
	matrix[5][3] = 2;
	matrix[5][4] = 2;
	matrix[5][5] = 2;
	matrix[5][6] = 2;
	matrix[5][7] = 2;

	matrix[6][0] = 2;
	matrix[6][1] = 7;
	matrix[6][2] = 2;
	matrix[6][3] = 7;
	matrix[6][4] = 2;
	matrix[6][5] = 2;
	matrix[6][6] = 2;
	matrix[6][7] = 2;

	matrix[7][0] = 2;
	matrix[7][1] = 2;
	matrix[7][2] = 2;
	matrix[7][3] = 2;
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
		matrix[xPos][yPos] = crrColour;
	if (button == GLFW_MOUSE_BUTTON_2 && action == GLFW_PRESS)
		clearMatrix();
	if (button == GLFW_MOUSE_BUTTON_3 && action == GLFW_PRESS)
	{
		if (crrColour <= 9)
			crrColour++;
		else
			crrColour = 1;
	}
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Navigation keys
	if ((key == GLFW_KEY_W || key == GLFW_KEY_UP) && action == GLFW_PRESS)
	{
		if (xPos < crrSize - 1)
			xPos++;
	}
	else if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT) && action == GLFW_PRESS)
	{
		if (yPos > 0)
			yPos--;
	}
	else if ((key == GLFW_KEY_S || key == GLFW_KEY_DOWN) && action == GLFW_PRESS)
	{
		if (xPos > 0)
			xPos--;
	}
	else if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT) && action == GLFW_PRESS)
	{
		if (yPos < crrSize - 1)
			yPos++;
	}
	else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		matrix[xPos][yPos] = crrColour;
	}
	else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	else if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
	{
		clearMatrix();
	}
	else if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		gridVisible = !gridVisible;
	}

	//Colour keys
	if (key == GLFW_KEY_KP_0 && action == GLFW_PRESS)
	{
		crrColour = 0;
		deleting = true;
	}
	else if (key == GLFW_KEY_KP_1 && action == GLFW_PRESS)
	{
		crrColour = 1;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_2 && action == GLFW_PRESS)
	{
		crrColour = 2;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_3 && action == GLFW_PRESS)
	{
		crrColour = 3;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_4 && action == GLFW_PRESS)
	{
		crrColour = 4;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_5 && action == GLFW_PRESS)
	{
		crrColour = 5;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_6 && action == GLFW_PRESS)
	{
		crrColour = 6;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_7 && action == GLFW_PRESS)
	{
		crrColour = 7;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_8 && action == GLFW_PRESS)
	{
		crrColour = 8;
		deleting = false;
	}
	else if (key == GLFW_KEY_KP_9 && action == GLFW_PRESS)
	{
		crrColour = 9;
		deleting = false;
	}

	//Resize keys
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		crrSize = 8;
		xPos = 0;
		yPos = 0;

		clearMatrix();
	}
	else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		crrSize = 12;
		xPos = 0;
		yPos = 0;

		clearMatrix();
	}
	else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		crrSize = 16;
		xPos = 0;
		yPos = 0;

		clearMatrix();
	}
}

void reshape(GLFWwindow* window, int width, int height)
{
	if (height == 0)
		height = 1;

	ajustaCamera2D(width,height);
}

void ajustaCamera2D(int width, int height)
{
	//Ativa a matriz de projeção --> conceitos mais tarde!!
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width < height) //altura menor que largura
	{
		float aspecto = (float)height / width; //proporcao altura/largura 
		gluOrtho2D(Xmin, Xmax, Ymin*aspecto, Ymax*aspecto); //corrige a proporção na largura
	}
	else {
		float aspecto = (float)width / height; //proporcao largura/altura
		gluOrtho2D(Xmin*aspecto, Xmax*aspecto, Ymin, Ymax); //corrige a proporção na altura
	}
}

void oneViewport(int w, int h, int layout)
{
	glViewport(0, 0, w, h);

	glTranslatef(-0.5,0,0);
	glScalef(0.75, 0.75, 0.75);

	if (gridVisible)
	{
		shape.DrawMatrix(matrix, crrSize);
		shape.DrawGrid(crrSize);
		shape.DrawPencil(xPos, yPos, crrColour, crrSize, deleting);
		shape.DrawPalette(crrColour);
	}
	else
	{
		shape.DrawGrid(crrSize);
		shape.DrawMatrix(matrix, crrSize);
		shape.DrawPencil(xPos, yPos, crrColour, crrSize, deleting);
		shape.DrawPalette(crrColour);
	}
}

int main(void)
{
	srand(time(0));

	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(640, 480, "Pixel art editor  :)", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glfwSetFramebufferSizeCallback(window, reshape);

	int width, height;
	float ratio;

	ajustaCamera2D(640, 480);

	setInitialDraw();

	while (!glfwWindowShouldClose(window))
	{	
		//aqui recupera o tamanho atual da janela
		glfwGetFramebufferSize(window, &width, &height);

		// Limpa a janela de visualização com a cor branca
		glClearColor(0.8, 0.8, 0.8, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//seta a matriz de modelo 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Default view
		if (onEditor)
			oneViewport(width, height, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}