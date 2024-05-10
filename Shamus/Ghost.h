// Ghost.h: interface for the CGhost class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GHOST_H__8A97C842_62A1_11D9_A07B_EC387BC62146__INCLUDED_)
#define AFX_GHOST_H__8A97C842_62A1_11D9_A07B_EC387BC62146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGhost : public CSprite  
{
public:
	CGhost();
	bool Move(signed char& nx, signed char& ny, unsigned char value) override;
};

#endif // !defined(AFX_GHOST_H__8A97C842_62A1_11D9_A07B_EC387BC62146__INCLUDED_)
