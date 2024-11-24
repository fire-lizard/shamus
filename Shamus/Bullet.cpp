#include "Bullet.h"

Bullet::Bullet(signed char x, signed char y)
{
	bx = x;
	by = y;
	is_fired = false;
	direction = CENTER;
}