 // Maze.cpp: implementation of the CMaze class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Maze.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMaze::CMaze()
{
	_rooms = new CRoom*[MAX_ROOM_X * MAX_ROOM_Y];
	for (unsigned short index = 0;index < MAX_ROOM_X * MAX_ROOM_Y;index++)
	{
		_rooms[index] = nullptr;
	}
}

CMaze::~CMaze()
{
	for (unsigned short index = 0;index < MAX_ROOM_X * MAX_ROOM_Y;index++)
	{
		if (_rooms[index])
		{
			delete _rooms[index];
		}
	}
	delete[] _rooms;
}

void CMaze::SetPaths()
{
	for (unsigned char index1 = 0;index1 < XCOUNT + 2;index1++)
   	{
        for (unsigned char index2 = 0;index2 < YCOUNT + 2;index2++)
        {
            if (index1 > 0 && index1 < XCOUNT + 1 && index2 > 0 && index2 < YCOUNT + 1)			
			{
				const unsigned char point = _rooms[_rx * MAX_ROOM_Y + _ry]->GetItem(index1 - 1, index2 - 1);
                if (point >= 1 && point <= 8)
                {
                    _path[index1][index2] = 255;
                }
                else
                {
                    _path[index1][index2] = 254;
                }
            }
            else
            {
					_path[index1][index2] = 255;
            }
        }        
    }
}

void CMaze::MinValue(signed char x1, signed char y1, signed char& x, signed char& y)
{
   	valarray <unsigned char> v(4);
    v[0] = _pathFind[x1 - 1][y1];
    v[1] = _pathFind[x1 + 1][y1];
    v[2] = _pathFind[x1][y1 - 1];
	v[3] = _pathFind[x1][y1 + 1];
    unsigned char b = min(min(v[0], v[1]), min(v[2], v[3]));
	if (b == v[0])
    {
        x = x1 - 1;
	    y = y1;
        return;
	}
    if (b == v[1])
	{
        x = x1 + 1;
        y = y1;
	    return;
    }
	if (b == v[2])
    {
        x = x1;
	    y = y1 - 1;
        return;
	}
    if (b == v[3])
	{
        x = x1;
        y = y1 + 1;
	}
}

void CMaze::GetPaths(signed char& x1, signed char& y1, signed char x2, signed char y2)
{
    unsigned char ni = 0;
    constexpr unsigned char nk = 64;
    do
    {
        for (unsigned char index1 = 1;index1 < XCOUNT + 1;index1++)
        {
            for (unsigned char index2 = 1;index2 < YCOUNT + 1;index2++)
            {
       	        if (_pathFind[index1][index2] == ni)
               	{
	                const unsigned char c1 = _pathFind[index1 - 1][index2];
	                const unsigned char c2 = _pathFind[index1 + 1][index2];
	                const unsigned char c3 = _pathFind[index1][index2 - 1];
	                const unsigned char c4 = _pathFind[index1][index2 + 1];
               	    if (c1 == 254)
                    {
                        _pathFind[index1 - 1][index2] = ni + 1;
                    }
                    if (c2 == 254)
       	            {
               	        _pathFind[index1 + 1][index2] = ni + 1;
                    }
                    if (c3 == 254)
                    {
                        _pathFind[index1][index2 - 1] = ni + 1;
                    }
       	            if (c4 == 254)
               	    {
                       	_pathFind[index1][index2 + 1] = ni + 1;
                    }
                    if (c1 == 253)
                    {
       	                MinValue(index1 - 1,index2,x1,y1);
               	        return;
                    }
                    if (c2 == 253)
                    {
                        MinValue(index1 + 1,index2,x1,y1);
                        return;
       	            }
               	    if (c3 == 253)
                    {
                        MinValue(index1,index2 - 1,x1,y1);
                        return;
                    }
       	            if (c4 == 253)
               	    {
                        MinValue(index1,index2 + 1,x1,y1);
                        return;
                    }
                }
       	    }
        }
        ni++;
    }
    while (ni <= nk);
}

void CMaze::Wave(signed char& x1, signed char& y1, signed char x2, signed char y2)
{
	for (unsigned i = 0;i < XCOUNT + 2;i++)
	{
		for (unsigned j = 0;j < YCOUNT + 2;j++)
		{
			_pathFind[i][j] = _path[i][j];
		}
	}
    x1++;
    y1++;
    x2++;
    y2++;
    _pathFind[x1][y1] = 253;
    _pathFind[x2][y2] = 0;
    GetPaths(x1,y1,x2,y2);
    x1--;
    y1--;
}

void CMaze::SelectRoom(signed char rx, signed char ry)
{
	_rx = rx;
	_ry = ry;
    SetPaths();
}        

void CMaze::AddRoom(unsigned char x, unsigned char y, CRoom* room) const
{
	_rooms[x * MAX_ROOM_Y + y] = room;
}

CRoom* CMaze::RoomNo(unsigned char x, unsigned char y) const
{
	return _rooms[x * MAX_ROOM_Y + y];
}
