// Sprite.h: interface for the CSprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITE_H__29275B62_6293_11D9_A07B_F33E791D5046__INCLUDED_)
#define AFX_SPRITE_H__29275B62_6293_11D9_A07B_F33E791D5046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSprite  
{
public:
    signed char px, py;

	virtual bool Move(signed char& nx, signed char& ny, unsigned char value) = 0;
	void GetCoords(signed char& X, signed char& Y) const;
	static void Show(const unsigned int* array, double x, double y, int w, int h);
	static void Show(const unsigned char* array, double x, double y, int w, int h);
};

#endif // !defined(AFX_SPRITE_H__29275B62_6293_11D9_A07B_F33E791D5046__INCLUDED_)
