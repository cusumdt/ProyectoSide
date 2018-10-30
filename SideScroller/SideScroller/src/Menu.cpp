#include "raylib.h"
#include "Game.h"
Vector2 mousePoint;
Rectangle rec1;
Rectangle rec2;
bool creditScreen = false;
namespace Game
{
	bool p2 = false;
	Rectangle rec3;
	void MUpdate()
	{
		p2 = false;
		mousePoint = GetMousePosition();
		rec1.x = screenWidth / 2 - 50;
		rec1.y = screenHeight / 2;
		rec1.height = 50;
		rec1.width = 100;

		rec3.x = screenWidth / 2 - 50;
		rec3.y = screenHeight / 2 + 80;
		rec3.height = 50;
		rec3.width = 100;


		rec2.x = screenWidth / 2 - 50;
		rec2.y = screenHeight / 2 + 160;
		rec2.height = 50;
		rec2.width = 100;


		if (CheckCollisionPointRec(mousePoint, rec1))
		{

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && creditScreen == false)
			{
				Restart();
				currentScreen++;
			}
		}
		if (CheckCollisionPointRec(mousePoint, rec2))
		{

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				creditScreen = !creditScreen;
			}
		}
		if (CheckCollisionPointRec(mousePoint, rec3))
		{

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				Restart();
				p2 = true;
				currentScreen++;
			}
		}

	}

	void MDraw()
	{
		BeginDrawing();
		if (!creditScreen)
		{
			ClearBackground(RAYWHITE);
			DrawTextureRec(SkyText, Sky1, { 0,0 }, WHITE);
			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			DrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, BLACK);
			DrawRectangle(rec3.x, rec3.y, rec3.width, rec3.height, BLACK);
			DrawText("P l a y", rec1.x + 25, rec1.y + 15, 18, WHITE);
			DrawText("C r e d i t s", rec2.x + 5, rec2.y + 15, 18, WHITE);
			DrawText("Two Players", rec3.x + 5, rec3.y + 15, 18, WHITE);
			DrawText("Flappy Ship", screenWidth / 2 - 150, 100, 60, MAROON);
			DrawText("Flappy Shipv1.0", 10, screenHeight - 15, 10, WHITE);
		}
		else
		{
			DrawTextureRec(SkyText, Sky1, { 0,0 }, WHITE);
			DrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, BLACK);
			DrawText("B a c k", rec2.x + 15, rec2.y + 15, 18, WHITE);
			DrawText("Made using RAYLIB", screenWidth / 2 - 250, 50, 30, WHITE);
			DrawText("Art made in PISKELAPP.COM", screenWidth / 2 - 250, 100, 30, WHITE);
			DrawText("Created by Damian Iglesias", screenWidth / 2 - 250, 150, 30, WHITE);
			DrawText("Menu Screen by Martin Concetti", screenWidth / 2 - 250, 200, 30, WHITE);
			DrawText("Sound made in BeepBox", screenWidth / 2 - 250, 250, 30, WHITE);
		}
		EndDrawing();
	}

}
