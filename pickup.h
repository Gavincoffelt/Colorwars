#pragma once
#include "raylib.h"


class pickups{
public:

	// location
	Vector2 pos;

	//radius
	float radius;
	//value
	int value;
	//enabled
	bool enabled = true;
	void draw();
	
};
