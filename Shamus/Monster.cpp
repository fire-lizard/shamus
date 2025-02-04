// Monster.cpp: implementation of the CMonster class.
//
//////////////////////////////////////////////////////////////////////

#include "Monster.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMonster::CMonster()
{
    px = 0;
    py = 0;
    is_alive = true;
}

bool CMonster::CheckMonsterMovement(unsigned char value, signed char x, signed char y) const
{
    if (value >= 1 && value <= 5)
    {
        return false;
	}
    for (unsigned char index = 1;index < 5;index++)
    {
        if (index != number && X != nullptr && Y != nullptr)
        {
            if (x == X[index] && y == Y[index])
            {
                return false;
            }
        }
    }
    return true;
}
        
bool CMonster::Move(signed char& nx, signed char& ny, unsigned char value)
{
	const bool result = CheckMonsterMovement(value, nx, ny);
	if (result)
    {
        px = nx;
        py = ny;
    }
    nx = px;
    ny = py;
	return result;
}
