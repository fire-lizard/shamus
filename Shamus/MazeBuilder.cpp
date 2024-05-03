// MazeBuilder.cpp: implementation of the CMazeBuilder class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "MazeBuilder.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMazeBuilder::CMazeBuilder()
{
	_currentMaze = 0;
}

CMazeBuilder::~CMazeBuilder()
{
	if (_currentMaze)
	{
		delete _currentMaze;
	}
}

void CMazeBuilder::BuildMaze(unsigned char data[MAX_ROOM_X][MAX_ROOM_Y][XCOUNT][YCOUNT])
//void CMazeBuilder::BuildMaze(unsigned char *data)
{
	unsigned char* start = &data[0][0][0][0];
	//unsigned char* start = &data[0];
	_currentMaze = new CMaze;
	for (unsigned char index1 = 0;index1 < MAX_ROOM_X;index1++)
	{
		for (unsigned char index2 = 0;index2 < MAX_ROOM_Y;index2++)
		{
			CRoom* room = new CRoom(XCOUNT, YCOUNT);
			for (unsigned char i = 0;i < XCOUNT;i++)
			{
				for (unsigned char j = 0;j < YCOUNT;j++)
				{
					room->SetObject(i, j, data[index1][index2][i][j]);
					//room->SetObject(i, j, data[((index1 * MAX_ROOM_Y) + index2) * XCOUNT + i * YCOUNT + j]);
				}
			}
			_currentMaze->AddRoom(index1, index2, room);
		}
	}
}

CMaze* CMazeBuilder::GetMaze()
{
	return _currentMaze;
}
