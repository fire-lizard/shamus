#pragma once

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "SDL2.lib")

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>

#include <map>
#include <valarray>
#include <cstdio>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL.h>

#include "Room.h"
#include "Maze.h"
#include "MazeBuilder.h"
#include "Sprite.h"
#include "Player.h"
#include "Monster.h"
#include "Ghost.h"
#include "Wall.h"

using namespace std;
