// Sprite.cpp: implementation of the CSprite class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Sprite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSprite::CSprite()
{

}

CSprite::~CSprite()
{

}

void CSprite::GetCoords(signed char& X, signed char& Y)
{
    X = px;
    Y = py;
}

void CSprite::Show(unsigned long* array, double x, double y)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glRasterPos2d(x, y);
    glDrawPixels(20,20,GL_RGBA,GL_UNSIGNED_BYTE,array);
}
