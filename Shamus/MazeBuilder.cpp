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
	_currentMaze = nullptr;
}

CMazeBuilder::~CMazeBuilder()
{
	delete _currentMaze;
}

void CMazeBuilder::BuildMaze(const unsigned char *data)
{
	_currentMaze = new CMaze;
	int idx = 0;
	for (unsigned char index1 = 0;index1 < MAX_ROOM_X;index1++)
	{
		for (unsigned char index2 = 0;index2 < MAX_ROOM_Y;index2++)
		{
			const auto room = new CRoom(XCOUNT, YCOUNT);
			for (unsigned char i = 0;i < XCOUNT;i++)
			{
				for (unsigned char j = 0;j < YCOUNT;j++)
				{
					const unsigned char item = data[idx];
					if (item > 0)
					{
						room->SetItem(i, j, item);
					}
					idx++;
				}
			}
			_currentMaze->AddRoom(index1, index2, room);
		}
	}
}

CMaze* CMazeBuilder::GetMaze() const
{
	return _currentMaze;
}
