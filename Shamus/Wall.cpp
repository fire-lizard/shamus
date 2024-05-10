// Wall.cpp: implementation of the CWall class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Wall.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CWall::Wall1(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(0.5,0.125,0);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
	glBegin(GL_LINES);
		glColor3d(0,0,0);
		glVertex2d((x1 + x2) / 2, y1);
		glVertex2d((x1 + x2) / 2, y2);
		glVertex2d(x1, (y1 + y2) / 2);
		glVertex2d(x2, (y1 + y2) / 2);
	glEnd();
}

void CWall::Wall2(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1,1,0);
        glVertex2d(x1, y1);
        glColor3d(1,0,0);
        glVertex2d(x2, y1);
        glColor3d(0,1,0);
        glVertex2d(x2, y2);
        glColor3d(0,0,1);
        glVertex2d(x1, y2);
    glEnd();
}

void CWall::Wall3(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(0.5,0,0.5);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
		glColor3d(0,0,0);
		glVertex2d(x1 + (x2 - x1) * 0.25, y1 + (y2 - y1) * 0.25);
		glVertex2d(x1 + (x2 - x1) * 0.75, y1 + (y2 - y1) * 0.25);
		glVertex2d(x1 + (x2 - x1) * 0.75, y1 + (y2 - y1) * 0.75);
		glVertex2d(x1 + (x2 - x1) * 0.25, y1 + (y2 - y1) * 0.75);
    glEnd();
}

void CWall::Wall4(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(0.25,0.25,0.25);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
	glEnd();
	glBegin(GL_LINES);
		glColor3d(0,0,0);
		glVertex2d(x1 + (x2 - x1) * 0.25, y1);
		glVertex2d(x1 + (x2 - x1) * 0.25, y2);
		glVertex2d(x1 + (x2 - x1) * 0.75, y1);
		glVertex2d(x1 + (x2 - x1) * 0.75, y2);
		glVertex2d((x1 + x2) / 2, y1);
		glVertex2d((x1 + x2) / 2, y2);
		glVertex2d(x1, (y1 + y2) / 2);
		glVertex2d(x2, (y1 + y2) / 2);
		glVertex2d(x1, y1 + (y2 - y1) * 0.25);
		glVertex2d(x2, y1 + (y2 - y1) * 0.25);
		glVertex2d(x1, y1 + (y2 - y1) * 0.75);
		glVertex2d(x2, y1 + (y2 - y1) * 0.75);
    glEnd();
}

void CWall::Door(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1,0,1);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
		glColor3d(1,0,0);
		glVertex2d(x1 + (x2 - x1) * 0.125, y1 + (y2 - y1) * 0.125);
		glVertex2d(x1 + (x2 - x1) * 0.875, y1 + (y2 - y1) * 0.125);
		glVertex2d(x1 + (x2 - x1) * 0.875, y1 + (y2 - y1) * 0.875);
		glVertex2d(x1 + (x2 - x1) * 0.125, y1 + (y2 - y1) * 0.875);
		glColor3d(0,1,0);
		glVertex2d(x1 + (x2 - x1) * 0.25, y1 + (y2 - y1) * 0.25);
		glVertex2d(x1 + (x2 - x1) * 0.75, y1 + (y2 - y1) * 0.25);
		glVertex2d(x1 + (x2 - x1) * 0.75, y1 + (y2 - y1) * 0.75);
		glVertex2d(x1 + (x2 - x1) * 0.25, y1 + (y2 - y1) * 0.75);
		glColor3d(0,0,1);
		glVertex2d(x1 + (x2 - x1) * 0.375, y1 + (y2 - y1) * 0.375);
		glVertex2d(x1 + (x2 - x1) * 0.625, y1 + (y2 - y1) * 0.375);
		glVertex2d(x1 + (x2 - x1) * 0.625, y1 + (y2 - y1) * 0.625);
		glVertex2d(x1 + (x2 - x1) * 0.375, y1 + (y2 - y1) * 0.625);
    glEnd();
}

void CWall::Show(unsigned char kind, double x1, double y1, double x2, double y2)
{
    typedef void(*obj_func)(double x1, double y1, double x2, double y2);
    constexpr obj_func objects[] = {Wall1,Wall2,Wall3,Wall4,Door};
	objects[kind](x1, y1, x2, y2);
}
