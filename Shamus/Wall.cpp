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

void CWall::Wall6(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 3;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x1, y2);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x1 + xdistance, y2);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + 2 * xdistance, y1);
        glVertex2d(x1 + 2 * xdistance, y2);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
    glEnd();
}

void CWall::Back1(double x1, double y1, double x2, double y2)
{
}

void CWall::Back2(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    double sxdistance = (x2 - x1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glColor3d(0.25, 0.67, 0.25);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3d(0.3, 1, 0.3);
        glVertex2d(x1, y1);
        glVertex2d(x1 + sxdistance, y1);
        glVertex2d(x1 + sxdistance, y2);
        glVertex2d(x1, y2);
        glEnd();
    glBegin(GL_POLYGON);
        glColor3d(0.3, 1, 0.3);
        glVertex2d(x2 - sxdistance, y1);
        glVertex2d(x2, y1);
        glVertex2d(x2, y2);
        glVertex2d(x2 - sxdistance, y2);
    glEnd();
}

void CWall::Back3(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
}

void CWall::Back4(double x1, double y1, double x2, double y2)
{
}

void CWall::Back5(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    double sxdistance = (x2 - x1) / 10;
    double sydistance = (y2 - y1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1 + ydistance - sydistance);
        glVertex2d(x1, y1 + ydistance + sydistance);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + 0.5 * xdistance, y1 + ydistance - 3 * sydistance);
        glVertex2d(x1 + 0.5 * xdistance, y1 + ydistance + 3 * sydistance);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + xdistance, y1 + ydistance - 5 * sydistance);
        glVertex2d(x1 + xdistance, y1 + ydistance + 5 * sydistance);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1, 1, 0.3);
        glVertex2d(x2 - 0.5 * xdistance, y1 + ydistance - 3 * sydistance);
        glVertex2d(x2 - 0.5 * xdistance, y1 + ydistance + 3 * sydistance);
    glEnd();
    glBegin(GL_LINES);
    glColor3d(1, 1, 0.3);
        glVertex2d(x2, y1 + ydistance - sydistance);
        glVertex2d(x2, y1 + ydistance + sydistance);
    glEnd();
}

void CWall::Back6(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    double sxdistance = (x2 - x1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glColor3d(0.67, 0.67, 0.22);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + xdistance - sxdistance, y1);
        glVertex2d(x1 + xdistance + sxdistance, y1);
        glVertex2d(x1 + xdistance + sxdistance, y2);
        glVertex2d(x1 + xdistance - sxdistance, y2);
    glEnd();
}

void CWall::Back7(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 3;
    double ydistance = (y2 - y1) / 3;
    double sxdistance = (x2 - x1) / 10;
    double sydistance = (y2 - y1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y1 + ydistance - sydistance);
        glVertex2d(x2, y1 + ydistance - sydistance);
        glVertex2d(x2, y1 + ydistance + sydistance);
        glVertex2d(x1, y1 + ydistance + sydistance);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1, y2 - ydistance - sydistance);
        glVertex2d(x2, y2 - ydistance - sydistance);
        glVertex2d(x2, y2 - ydistance + sydistance);
        glVertex2d(x1, y2 - ydistance + sydistance);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x1 + xdistance - sxdistance, y1);
        glVertex2d(x1 + xdistance + sxdistance, y1);
        glVertex2d(x1 + xdistance + sxdistance, y2);
        glVertex2d(x1 + xdistance - sxdistance, y2);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x2 - xdistance - sxdistance, y1);
        glVertex2d(x2 - xdistance + sxdistance, y1);
        glVertex2d(x2 - xdistance + sxdistance, y2);
        glVertex2d(x2 - xdistance - sxdistance, y2);
    glEnd();
}

void CWall::Back8(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    double sxdistance = (x2 - x1) / 10;
    double sydistance = (y2 - y1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3d(0.3, 1, 0.3);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x1 + xdistance, y1 + sydistance);
        glVertex2d(x2 - sxdistance, y1 + ydistance);
        glVertex2d(x1 + sxdistance, y1 + ydistance);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 1, 0.3);
        glVertex2d(x2 - sxdistance, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2 - sydistance);
        glVertex2d(x1 + sxdistance, y1 + ydistance);
    glEnd();
}

void CWall::Back9(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    double sxdistance = (x2 - x1) / 10;
    double sydistance = (y2 - y1) / 10;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3d(1, 1, 0.3);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(1, 0.3, 0.3);
        glVertex2d(x1 + xdistance, y1 + sydistance);
        glVertex2d(x2 - sxdistance, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2 - sydistance);
        glVertex2d(x1 + sxdistance, y1 + ydistance);
    glEnd();
}

void CWall::Back10(double x1, double y1, double x2, double y2)
{
    double xdistance = (x2 - x1) / 2;
    double ydistance = (y2 - y1) / 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3d(0.5, 0.5, 0.25);
        glVertex2d(x1 + xdistance, y1);
        glVertex2d(x2, y1 + ydistance);
        glVertex2d(x1 + xdistance, y2);
        glVertex2d(x1, y1 + ydistance);
    glEnd();
}

void CWall::Show(unsigned char kind, double x1, double y1, double x2, double y2)
{
    typedef void(*obj_func)(double x1, double y1, double x2, double y2);
    constexpr obj_func objects[] = {Wall1,Wall2,Wall3,Wall4,Wall5,Wall6,Back1,Back2,Back3,Back4,Back5,Back6,Back7,Back8,Back9,Back10};
	objects[kind](x1, y1, x2, y2);
}
