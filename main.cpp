/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "ball.h"
#include "pickup.h"
#include "ball2.h"
#include <string>
#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 800;
	float time = 0;
	float maxtime = 10.0f;
	int player1score = 0;
	int player2score = 0;
	int final1score = 0;
	int final2score = 0;
	InitWindow(screenWidth, screenHeight, "Color War");
	SetTargetFPS(60);
	ball2 player2;
	player2.pos = { 780.0f,780.0f };
	player2.radius = 35.0f;
	player2.speed = 300.0f;
	ball player;
	player.pos = { 20.0f,20.0f };
	player.radius =  35.0f;
	player.speed = 300.0f;
	//--------------------------------------------------------------------------------------			
	// Main game loop
	int counter = 0;Rectangle grid[16][16]{};
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		// Update
		//----------------------------------------------------------------------------------
		player.update(GetFrameTime());
		player2.update(GetFrameTime());
		if (player.pos.x < 0.0f) {
			player.pos.x = 800.0f;
		}
		else if (player.pos.x > 800.0f) {
			player.pos.x = 0.0f;
		} if (player.pos.y < 0.0f) {
			player.pos.y = 800.0f;
		}
		else if (player.pos.y > 800.0f) {
			player.pos.y = 0.0f;

		}
		if (player2.pos.x < 0.0f) {
			player2.pos.x = 800.0f;
		}
		else if (player2.pos.x > 800.0f) {
			player2.pos.x = 0.0f;
		} if (player2.pos.y < 0.0f) {
			player2.pos.y = 800.0f;
		}
		else if (player2.pos.y > 800.0f) {
			player2.pos.y = 0.0f;

		}
		
		//----------------------------------------------------------------------------------
		
		// Draw
		//----------------------------------------------------------------------------------
		
		BeginDrawing();
		time += GetFrameTime();
			int fill = 0;
			if (time < maxtime) {
				for (size_t i = 0; i < 16; ++i)
				{

					for (size_t j = 0; j < 16; ++j)
					{
						counter++;
						if (counter < 255)
						{
							grid[i][j].player1 = false;
							grid[i][j].player2 = false;

						}
						int x = j * 50;
						int y = i * 50;
						grid[i][j].x = x;
						grid[i][j].y = y;
						if ((grid[i][j].player1 == false) and (grid[i][j].player2 == false)) {
							DrawRectangle(grid[i][j].x, grid[i][j].y, 49, 49, WHITE);
						}
						if (grid[i][j].player1 == true)
						{
							DrawRectangle(grid[i][j].x, grid[i][j].y, 49, 49, DARKBLUE);
						}
						if (grid[i][j].player2 == true)
						{
							DrawRectangle(grid[i][j].x, grid[i][j].y, 49, 49, MAROON);
						}
						if (CheckCollisionCircleRec(player.pos, player.radius, grid[i][j])) {
							DrawRectangle(grid[i][j].x, grid[i][j].y, 49, 49, BLUE);
							grid[i][j].player1 = true;
							grid[i][j].player2 = false;
						}
						if (CheckCollisionCircleRec(player2.pos, player2.radius, grid[i][j])) {
							DrawRectangle(grid[i][j].x, grid[i][j].y, 49, 49, RED);
							grid[i][j].player2 = true;
							grid[i][j].player1 = false;







						}
					}
							ClearBackground(BLACK);
				}

				player.draw();
				player2.draw();
				DrawText(std::to_string(time).c_str(), 600, 10, 40, BLACK);
				

			}
			
			

				if (time > maxtime) {
					for (size_t i = 0; i < 16; ++i)
					{
						for (size_t j = 0; j < 16; ++j)
						{
							if (grid[i][j].player1 == true) {
								player1score++;
								grid[i][j].player1 = false;
							}
							else if (grid[i][j].player2 == true) {
								player2score++;
								grid[i][j].player2 = false;

							}
						}
					}
					final1score = player1score;
					final2score = player2score;
					time = maxtime;
					ClearBackground(WHITE);
					DrawText("Games Over!", 250, 400, 40, BLACK);
					DrawText("P1:", 5, 10, 40, BLACK);
					DrawText("P2:", 675, 10, 40, BLACK);
				    DrawText(std::to_string(player1score).c_str(), 65, 10, 40, BLACK);
				    DrawText(std::to_string(player2score).c_str(), 750, 10, 40, BLACK);
					if (player1score > player2score) {
						DrawText("Player One  Has won! Would you like to restart? Y/N", 100, 500, 25, DARKBLUE);
						if (IsKeyDown(KEY_Y)) {
							main();
						}
						else if (IsKeyDown(KEY_N)) {
							return 0;
						}

					}
					 else if (player1score < player2score) {
						DrawText("Player Two  Has won! Would you like to restart? Y/N", 100, 500, 25, MAROON);
						if (IsKeyDown(KEY_Y)) {
							main();
						}
						else if (IsKeyDown(KEY_N)) {
							return 0;
						}
					}
					 else if(player1score == player2score) {
						 DrawText("Its a tie! Would you like to restart? Y/N", 100, 500, 25, PURPLE);
						 if (IsKeyDown(KEY_Y)) {
							 main();
						 }
						 else if (IsKeyDown(KEY_N)) {
							 return 0;
						 }
					 }
				}
	
		


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
