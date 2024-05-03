// Room.h: interface for the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOM_H__0C65CA01_8040_11D9_815D_E811484BFB1C__INCLUDED_)
#define AFX_ROOM_H__0C65CA01_8040_11D9_815D_E811484BFB1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRoom  
{
	unsigned char* _data;
	unsigned char _width;
	unsigned char _height;

	CRoom();
public:
	CRoom(unsigned char width, unsigned char height);
	virtual ~CRoom();
	unsigned char GetObject(signed char x, signed char y);
	void SetObject(signed char x, signed char y, unsigned char value);
};

#endif // !defined(AFX_ROOM_H__0C65CA01_8040_11D9_815D_E811484BFB1C__INCLUDED_)
