#include "pickup.h"
#include "raylib.h"
void pickups::draw()
{
	if (enabled = true)
		DrawCircle(pos.x, pos.y, radius, GOLD);

}

