// Player.h: interface for the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_)
#define AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Sprite.h"
#include "Maze.h"

enum Item
{
    NONE,
    LIFE,
    AWARD,
    DOOR,
    LINE1,
    LINE2,
    LINE3,
    LINE4,
    LINE5,
    WALL1,
    WALL2,
    WALL3,
    WALL4,
    WALL5,
    WALL6,
    WALL7,
    WALL8,
    WALL9,
    WALL10,
    BLUE_KEY,
    BLUE_LOCK,
    BROWN_KEY,
    BROWN_LOCK,
    CYAN_KEY,
    CYAN_LOCK,
    GREEN_KEY,
    GREEN_LOCK,
    ORANGE_KEY,
    ORANGE_LOCK,
    PURPLE_KEY,
    PURPLE_LOCK,
    RED_KEY,
    RED_LOCK,
    LEFT_ARROW,
    RIGHT_ARROW
};

class CPlayer : public CSprite  
{
	bool CheckPlayerMovement(unsigned char& value);
	bool CheckRoom(signed char& x, signed char& y);
public:
    unsigned char lives, blue_keys, brown_keys, cyan_keys, green_keys, orange_keys, purple_keys, red_keys;
	signed char rx, ry;
	bool room_changed;

	CPlayer();
	bool Move(signed char& nx, signed char& ny, unsigned char value) override;
};

#endif // !defined(AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_)
