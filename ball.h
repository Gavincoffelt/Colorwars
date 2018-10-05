#pragma once
#include"raylib.h"
class ball {
public:
	// Position of the Object
	Vector2 pos;
	// Size of the ball.

	float radius;
	// How fast the ball is traveling.
	float speed;


	void update(float deltaTime);
	void draw();
};