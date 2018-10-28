#include "raylib.h"
#include "Game.h"
namespace Game
{
	void EDraw()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTextureRec(SkyText, Sky1, {0,0}, WHITE);
		DrawText("YOU LOSE", screenWidth/4, screenHeight/3, 50, WHITE);
		DrawText("ENTER TO GO TO MENU", screenWidth / 4, screenHeight / 3+60, 50, WHITE);
		DrawText("SPACE TO RESTART", screenWidth / 4, screenHeight / 3+120, 50, WHITE);
		EndDrawing();
	}
	void EUpdate()
	{
		if (IsKeyDown(KEY_ESCAPE))
		{
			gameover = true;
		}
		if (IsKeyDown(KEY_SPACE))
		{
			Game::Restart();
			currentScreen--;
		}
		if (IsKeyDown(KEY_ENTER))
		{
			currentScreen = 1;
		}
	}
};