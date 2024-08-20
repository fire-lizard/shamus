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
        glColor3d(1,0.3,0.3);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
}

void CWall::Wall2(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 4;
    double ydistance = (y2 - y1) / 4;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
    glBegin(GL_QUADS);
        glColor3d(0, 0, 0);
        glVertex2d(x1 + xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y2 - ydistance);
        glVertex2d(x1 + xdistance, y2 - ydistance);
    glEnd();
}

void CWall::Wall3(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 8;
    double ydistance = (y2 - y1) / 8;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
    glBegin(GL_QUADS);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x1 + xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y2 - ydistance);
        glVertex2d(x1 + xdistance, y2 - ydistance);
    glEnd();
}

void CWall::Wall4(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 8;
    double ydistance = (y2 - y1) / 8;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
    glBegin(GL_QUADS);
        glColor3d(0.3, 1, 0.3);
        glVertex2d(x1 + xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y1 + ydistance);
        glVertex2d(x2 - xdistance, y2 - ydistance);
        glVertex2d(x1 + xdistance, y2 - ydistance);
    glEnd();
    glBegin(GL_QUADS);
        glColor3d(0, 0, 0);
        glVertex2d(x1 + 2 * xdistance, y1 + 2 * ydistance);
        glVertex2d(x2 - 2 * xdistance, y1 + 2 * ydistance);
        glVertex2d(x2 - 2 * xdistance, y2 - 2 * ydistance);
        glVertex2d(x1 + 2 * xdistance, y2 - 2 * ydistance);
    glEnd();
}

void CWall::Wall5(double x1, double y1, double x2, double y2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x1, y2);
    glEnd();
}

void CWall::Show(unsigned char kind, double x1, double y1, double x2, double y2)
{
    typedef void(*obj_func)(double x1, double y1, double x2, double y2);
    constexpr obj_func objects[] = {Wall1,Wall2,Wall3,Wall4,Wall5};
	objects[kind](x1, y1, x2, y2);
}
