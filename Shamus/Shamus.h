#pragma once

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")

#if defined _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>
#endif

#include <map>
#include <valarray>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cerrno>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Room.h"
#include "Maze.h"
#include "MazeBuilder.h"
#include "Sprite.h"
#include "Player.h"
#include "Monster.h"
#include "Ghost.h"
#include "Wall.h"
#include "IniFile.h"
#include "Bullet.h"

using namespace std;
