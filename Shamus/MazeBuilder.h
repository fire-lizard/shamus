// MazeBuilder.h: interface for the CMazeBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZEBUILDER_H__DBF2D4C1_804A_11D9_815D_E811484BFB1C__INCLUDED_)
#define AFX_MAZEBUILDER_H__DBF2D4C1_804A_11D9_815D_E811484BFB1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Maze.h"
#include "Room.h"

class CMazeBuilder  
{
	CMaze* _currentMaze;
public:
	CMazeBuilder();
	virtual ~CMazeBuilder();
	void BuildMaze(const unsigned char *data);
	CMaze* GetMaze() const;
};

#endif // !defined(AFX_MAZEBUILDER_H__DBF2D4C1_804A_11D9_815D_E811484BFB1C__INCLUDED_)
