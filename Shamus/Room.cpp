// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Room.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoom::CRoom(unsigned char width, unsigned char height)
{
	_width = width;
	_height = height;
	_data = new unsigned char[width * height];
}

CRoom::~CRoom()
{
	delete[] _data;
}

unsigned char CRoom::GetItem(signed char x, signed char y) const
{
	return _data[x * _height + y];
}

void CRoom::SetItem(signed char x, signed char y, unsigned char value) const
{
	_data[x * _height + y] = value;
}
