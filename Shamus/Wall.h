// Wall.h: interface for the CWall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WALL_H__E9B17541_62EE_11D9_A07B_C4B37BC65346__INCLUDED_)
#define AFX_WALL_H__E9B17541_62EE_11D9_A07B_C4B37BC65346__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWall  
{
	static void Wall1(double x1, double y1, double x2, double y2);
	static void Wall2(double x1, double y1, double x2, double y2);
	static void Wall3(double x1, double y1, double x2, double y2);
	static void Wall4(double x1, double y1, double x2, double y2);
	static void Wall5(double x1, double y1, double x2, double y2);
	static void Wall6(double x1, double y1, double x2, double y2);
	static void Back1(double x1, double y1, double x2, double y2);
	static void Back2(double x1, double y1, double x2, double y2);
	static void Back3(double x1, double y1, double x2, double y2);
	static void Back4(double x1, double y1, double x2, double y2);
	static void Back5(double x1, double y1, double x2, double y2);
	static void Back6(double x1, double y1, double x2, double y2);
	static void Back7(double x1, double y1, double x2, double y2);
	static void Back8(double x1, double y1, double x2, double y2);
	static void Back9(double x1, double y1, double x2, double y2);
	static void Back10(double x1, double y1, double x2, double y2);
public:
	static void PlayerBullet(double x1, double y1, double x2, double y2);
	static void MonsterBullet(double x1, double y1, double x2, double y2);
	static void Show(unsigned char kind, double x1, double y1, double x2, double y2);
};

#endif // !defined(AFX_WALL_H__E9B17541_62EE_11D9_A07B_C4B37BC65346__INCLUDED_)
