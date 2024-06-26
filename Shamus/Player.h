// Player.h: interface for the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_)
#define AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum Item
{
    NONE = 0,
    LIFE = 1,
    AWARD = 2,
    DOOR = 3,
    LINE1 = 4,
    LINE2 = 5,
    LINE3 = 6,
    LINE4 = 7,
    LINE5 = 8,
    WALL1 = 9,
    WALL2 = 10,
    WALL3 = 11,
    WALL4 = 12,
    WALL5 = 13,
    WALL6 = 14,
    WALL7 = 15,
    WALL8 = 16,
    WALL9 = 17,
    BLUE_KEY = 18,
    BROWN_KEY = 19,
    CYAN_KEY = 20,
    GREEN_KEY = 21,
    ORANGE_KEY = 22,
    PURPLE_KEY = 23,
    RED_KEY = 24,
    BLUE_LOCK = 25,
    BROWN_LOCK = 26,
    CYAN_LOCK = 27,
    GREEN_LOCK = 28,
    ORANGE_LOCK = 29,
    PURPLE_LOCK = 30,
    RED_LOCK = 31
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
