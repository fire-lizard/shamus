// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Room.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoom::CRoom()
{

}

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

unsigned char CRoom::GetObject(signed char x, signed char y)
{
	return _data[x * _height + y];
}

void CRoom::SetObject(signed char x, signed char y, unsigned char value)
{
	_data[x * 20 + y] = value;
}
