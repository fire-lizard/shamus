#pragma once

enum Direction
{
    CENTER,
    WEST,
    SOUTHWEST,
    SOUTH,
    SOUTHEAST,
    EAST,
    NORTHEAST,
    NORTH,
    NORTHWEST
};

class Bullet
{
public:
	signed char bx, by;
	bool is_fired;
    Direction direction;

	Bullet(signed char x, signed char y);
};
