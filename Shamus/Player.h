// Player.h: interface for the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_)
#define AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define RED_BRICK 1
#define COLOR_BRICK 2
#define SOLID_BRICK 3
#define GRAY_BRICK 4
#define DOOR 5
#define LIFE 6
#define KEY 7
#define QUESTION_MARK 8

class CPlayer : public CSprite  
{
	bool CheckPlayerMovement(unsigned char& value);
	bool CheckRoom(signed char& x, signed char& y);
public:
    unsigned char lives, keys;
	signed char rx, ry;
	bool room_changed;

	CPlayer();
	virtual ~CPlayer();
	bool Move(signed char& nx, signed char& ny, unsigned char value);
};

#endif // !defined(AFX_PLAYER_H__29275B63_6293_11D9_A07B_F33E791D5046__INCLUDED_)
