// Monster.h: interface for the CMonster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONSTER_H__8A97C841_62A1_11D9_A07B_EC387BC62146__INCLUDED_)
#define AFX_MONSTER_H__8A97C841_62A1_11D9_A07B_EC387BC62146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMonster : public CSprite  
{
	bool CheckMonsterMovement(unsigned char value, signed char x, signed char y) const;
public:
    signed char *X, *Y;
    unsigned char number;

	CMonster();
	bool Move(signed char& nx, signed char& ny, unsigned char value) override;
};

#endif // !defined(AFX_MONSTER_H__8A97C841_62A1_11D9_A07B_EC387BC62146__INCLUDED_)
