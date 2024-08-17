// Sprite.cpp: implementation of the CSprite class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Sprite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CSprite::GetCoords(signed char& X, signed char& Y) const
{
    X = px;
    Y = py;
}

void CSprite::Show(const unsigned int* array, double x, double y, int w, int h)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2d(x, y);
    glDrawPixels(w, h, GL_RGBA, GL_UNSIGNED_BYTE, array);
}

void CSprite::Show(const unsigned char* array, double x, double y, int w, int h)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2d(x, y);
    glDrawPixels(w, h, GL_RGBA, GL_UNSIGNED_BYTE, array);
}
