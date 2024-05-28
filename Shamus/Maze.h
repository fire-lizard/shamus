// Maze.h: interface for the CMaze class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZE_H__29275B61_6293_11D9_A07B_F33E791D5046__INCLUDED_)
#define AFX_MAZE_H__29275B61_6293_11D9_A07B_F33E791D5046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define XCOUNT 40//Размер игрового поля по горизонтали
#define YCOUNT 25//Размер игрового поля по вертикали
#define MAX_ROOM_X 45//Количество комнат по горизонтали
#define MAX_ROOM_Y 12//Количество комнат по вертикали
#define MONSTER_COUNT 3//количество монстров

class CMaze  
{
	CRoom** _rooms;// Лабиринт
	signed char _rx;
	signed char _ry;
	unsigned char _path[XCOUNT + 2][YCOUNT + 2]; //Массив путей
	unsigned char _pathFind[XCOUNT + 2][YCOUNT + 2];

	void SetPaths();
	void MinValue(signed char x1, signed char y1, signed char& x, signed char& y);
	void GetPaths(signed char& x1, signed char& y1, signed char x2, signed char y2);
public:
	CMaze();
	virtual ~CMaze();
	void Wave(signed char& x1, signed char& y1, signed char x2, signed char y2);
	void SelectRoom(signed char rx, signed char ry);
	void AddRoom(unsigned char x, unsigned char y, CRoom* room) const;
	CRoom* RoomNo(unsigned char x, unsigned char y) const;
};

#endif // !defined(AFX_MAZE_H__29275B61_6293_11D9_A07B_F33E791D5046__INCLUDED_)
