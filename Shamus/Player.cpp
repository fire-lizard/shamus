// Player.cpp: implementation of the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "Shamus.h"
#include "Player.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlayer::CPlayer()
{
    rx = 0;
    ry = 0;
    px = 0;
    py = 0;
    lives = 3;
    keys = 0;
    room_changed = false;
}

bool CPlayer::CheckPlayerMovement(unsigned char& value)
{
    bool movement = true;
    switch (value)
    {
        case LINE1:
        case LINE2:
        case LINE3:
        case LINE4:
        case LINE5:
        case DOOR:
            movement = false;
            break;
        case LIFE:
            lives++;
            value = 0;
            break;
        case BLUE_KEY:
        case BROWN_KEY:
        case CYAN_KEY:
        case GREEN_KEY:
        case ORANGE_KEY:
        case PURPLE_KEY:
        case RED_KEY:
            keys++;
            value = 0;
            break;
        case BLUE_LOCK:
        case BROWN_LOCK:
        case CYAN_LOCK:
        case GREEN_LOCK:
        case ORANGE_LOCK:
        case PURPLE_LOCK:
        case RED_LOCK:
            movement = (keys > 0);
            if (movement)
            {
                keys--;
                value = 0;
            }
            break;
        case AWARD:
            value = 0;
            break;
        default:;
    }
    return movement;
}

bool CPlayer::CheckRoom(signed char& x, signed char& y)
{
    if (x < 0)
    {
        if (rx > 0)
        {
			x = XCOUNT - 1;
			rx--;
			return true;
        }
        else
        {
             x = 0;
             return false;
        }
    }
    if (x > XCOUNT - 1)
    {
        if (rx < MAX_ROOM_X - 1)
        {
			x = 0;
			rx++;
			return true;
        }
        else
        {
            x = XCOUNT - 1;
            return false;
        }
    }
    if (y > YCOUNT - 1)
    {
        if (ry < MAX_ROOM_Y - 1)
        {
			y = 0;
			ry++;
			return true;
        }
        else
        {
            y = YCOUNT - 1;
            return false;
        }
    }
    if (y < 0)
    {
        if (ry > 0)
        {
			y = YCOUNT - 1;
			ry--;
			return true;
        }
        else
        {
            y = 0;
            return false;
        }
    }
    return false;
}

bool CPlayer::Move(signed char& nx, signed char& ny, unsigned char value)
{
	const bool on_border = (nx > XCOUNT - 1 || nx < 0 || ny > YCOUNT - 1 || ny < 0);
    bool result = false;
	if (!on_border)
    {
        room_changed = false;
        result = CheckPlayerMovement(value);
		if (result)
        {
            px = nx;
            py = ny;
        }
    }
    else
    {
        room_changed = CheckRoom(nx, ny);
        if (room_changed)
        {
            px = nx;
            py = ny;
		}
    }
    nx = px;
    ny = py;
	return result;
}
