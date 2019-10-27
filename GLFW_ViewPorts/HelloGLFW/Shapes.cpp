#include "Shapes.h"
#include<iostream>
#include<fstream>

extern int matrix[16][16];

void Shape::DrawGrid(int cellsNumber)
{
	glLineWidth(1);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = cellsNumber;

	float cell = (Xmax - Xmin) / ncells;

	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(Xmin, Ymin);
	glVertex2f(Xmin, Ymax);
	glVertex2f(Xmax, Ymin);
	glVertex2f(Xmax, Ymax);
	glEnd();

	glColor3f(0.65, 0.65, 0.65);
	for (int i = 0; i < ncells; i++)
	{
		for (int j = 0; j < ncells; j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}
}
void Shape::DrawPencil(int posX, int posY, int crrColour, int cellsNumber, bool deleting)
{
	glLineWidth(2);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = cellsNumber;
	float cell = (Xmax - Xmin) / ncells;

	switch (crrColour)
	{
		case 0:
			glColor3f(0.5, 0.05, 0.05);
			break;

		case 1:
			glColor3f(1, 0, 0);
			break;

		case 2:
			glColor3f(0, 1, 0);
			break;

		case 3:
			glColor3f(0, 0, 1);
			break;

		case 4:
			glColor3f(1, 1, 0);
			break;

		case 5:
			glColor3f(1, 0, 1);
			break;

		case 6:
			glColor3f(0, 1, 1);
			break;

		case 7:
			glColor3f(0, 0, 0);
			break;

		case 8:
			glColor3f(0.5, 0.5, 0.5);
			break;

		case 9:
			glColor3f(1, 1, 1);
			break;
	}

	if (!deleting)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f(xi + cell * posY, yi + cell * posX);
		glVertex2f(xi + cell * (posY + 1), yi + cell * posX);
		glVertex2f(xi + cell * (posY + 1), yi + cell * (posX + 1));
		glVertex2f(xi + cell * posY, yi + cell * (posX + 1));
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f(xi + cell * (posY + 1), yi + cell * posX);
		glVertex2f(xi + cell * posY, yi + cell * posX);
		glVertex2f(xi + cell * (posY + 1), yi + cell * (posX + 1));
		glVertex2f(xi + cell * posY, yi + cell * (posX + 1));
		glEnd();
	}
}
void Shape::DrawMatrix(int matriz[16][16], int cellsNumber)
{
	glLineWidth(1);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = cellsNumber;
	float cell = (Xmax - Xmin) / ncells;

	//Background
	glLineWidth(0.5);

	glScalef(0.95, 0.95, 1);
	glColor3f(0.45, 0.35, 0.25);

	for (int i = 0; i < cellsNumber; i++)
	{
		for (int j = 0; j < cellsNumber; j++)
		{
			glBegin(GL_QUADS);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

	glScalef(0.945, 0.945, 1);
	glColor3f(0.35, 0.15, 0.15);

	for (int i = 0; i < cellsNumber; i++)
	{
		for (int j = 0; j < cellsNumber; j++)
		{
			glBegin(GL_QUADS);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

	//Base colour
	glScalef(0.94, 0.94, 1);
	glColor3f(1, 1, 1);

	for (int i = 0; i < cellsNumber; i++)
	{
		for (int j = 0; j < cellsNumber; j++)
		{
			glBegin(GL_QUADS);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (matriz[i][j] == 1)
			{
				glColor3f(1, 0, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 2)
			{
				glColor3f(0, 1, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 3)
			{
				glColor3f(0, 0, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 4)
			{
				glColor3f(1, 1, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 5)
			{
				glColor3f(1, 0, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 6)
			{
				glColor3f(0, 1, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 7)
			{
				glColor3f(0.1, 0.1, 0.1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 8)
			{
				glColor3f(0.5, 0.5, 0.5);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (matriz[i][j] == 9)
			{
				glColor3f(0.9, 0.9, 0.9);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
		}
	}
}
void Shape::DrawPalette(int crrColour)
{
	glTranslatef(1.75, 0, 0);
	glScalef(0.35, 0.35, 1);

	glLineWidth(1);

	int cellsNumber = 3;
	float xi = Xmin;
	float yi = Ymin;
	float ncells = cellsNumber;

	float cell = (Xmax - Xmin) / ncells;

	glColor3f(0.65, 0.65, 0.65);
	glBegin(GL_POINTS);
	glVertex2f(Xmin, Ymin);
	glVertex2f(Xmin, Ymax);
	glVertex2f(Xmax, Ymin);
	glVertex2f(Xmax, Ymax);
	glEnd();

	glScalef(1, 1, 1);
	glColor3f(0.45, 0.35, 0.25);

	//Background
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glBegin(GL_QUADS);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

	glScalef(0.9, 0.9, 1);
	glColor3f(0.35, 0.15, 0.15);

	//Background
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glBegin(GL_QUADS);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

	glScalef(0.9, 0.9, 1);

	//Fill
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 0)
			{
				glColor3f(1, 0, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 0 && j == 1)
			{
				glColor3f(0, 1, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 0 && j == 2)
			{
				glColor3f(0, 0, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 1 && j == 0)
			{
				glColor3f(1, 1, 0);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 1 && j == 1)
			{
				glColor3f(1, 0, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 1 && j == 2)
			{
				glColor3f(0, 1, 1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 2 && j == 0)
			{
				glColor3f(0.1, 0.1, 0.1);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 2 && j == 1)
			{
				glColor3f(0.5, 0.5, 0.5);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (i == 2 && j == 2)
			{
				glColor3f(0.9, 0.9, 0.9);

				glBegin(GL_QUADS);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
		}
	}

	//Current colour
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (crrColour == 1 && i == 0 && j == 0)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 2 && i == 0 && j == 1)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 3 && i == 0 && j == 2)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 4 && i == 1 && j == 0)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 5 && i == 1 && j == 1)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 6 && i == 1 && j == 2)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 7 && i == 2 && j == 0)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 8 && i == 2 && j == 1)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
			if (crrColour == 9 && i == 2 && j == 2)
			{
				glColor3f(0, 0, 0);
				glLineWidth(3);

				glBegin(GL_LINE_LOOP);
				glVertex2f(xi + cell * j, yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * i);
				glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
				glVertex2f(xi + cell * j, yi + cell * (i + 1));
				glEnd();
			}
		}
	}
}