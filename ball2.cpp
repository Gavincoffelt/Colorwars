#include "ball2.h"






void ball2::update(float deltaTime)
{
	if (IsKeyDown(KEY_UP)) {
		pos.y -= speed * deltaTime;

	}
	if (IsKeyDown(KEY_DOWN)) {
		pos.y += speed * deltaTime;

	}
	if (IsKeyDown(KEY_LEFT)) {
		pos.x -= speed * deltaTime;

	}
	if (IsKeyDown(KEY_RIGHT)) {
		pos.x += speed * deltaTime;

	}
	
}

void ball2::draw()
{
	DrawCircle(pos.x, pos.y, radius, RED);
}
