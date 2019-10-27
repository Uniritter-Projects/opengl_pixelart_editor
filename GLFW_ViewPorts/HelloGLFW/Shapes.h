#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ctime>

//World coordinates
const float Xmin = -1.0;
const float Xmax = 1.0;
const float Ymin = -1.0;
const float Ymax = 1.0;

using namespace std;

class Shape
{
public:
	Shape() {}
	~Shape() {}

	void DrawGrid(int cellsNumber);
	void DrawPencil(int posX, int posY, int crrColour, int cellsNumber, bool deleting);
	void DrawMatrix(int matriz[16][16], int cellsNumber);
	void DrawPalette(int crrColour);
};