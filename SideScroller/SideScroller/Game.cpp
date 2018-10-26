#include "raylib.h"
#include "End.h"
namespace Game
{
	const int MENU = 1;
	const int PLAY = 2;
	const int GOVER = 3;
	int screenWidth = 1000;
	int screenHeight = 450;
	bool gameover = false;
	Vector2 PlayerPos = { 50.0f, screenHeight / 2.0f };
	Vector2 PlayerSize = { 32.0f,16.0f };
	Vector2 ObstacleP = { (float)screenWidth, (float)GetRandomValue(50, 400) };
	Vector2 ObstacleS = { 50.0f, GetRandomValue(20,200) };
	void Obstacle();
	void gameOver();
	Rectangle rec1;
	Rectangle rec2;
	void GDraw();
	void GUpdate();
	void GInit();
	void Restart();
	bool Paused = false;
	Image image;
	Image sky;
	Image cloud;
	Image playercharacter;
	Texture2D PlayerCharacter;
	Texture2D Sky;
	Texture2D ImagenFondo;
	Texture2D Cloud;
	Rectangle fondo;
	Rectangle fondo2;
	Rectangle Cielo;
	Rectangle Nubes;
	Rectangle playeranim = { PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y };
	Rectangle player = { PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y };
	Rectangle obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	Vector2 position1 = { 0.0f, 0.0f };
	Vector2 position2 = { 500.0f, 0.0f };
	Vector2 position3 = { -500.0f, 0.0f };
	Vector2 position4 = { 0.0f, 0.0f };
	Vector2 position5 = { 1000.0f, 0.0f };
	Vector2 positionStatic = {0.0f, 0.0f};
	int PCFrame = 0;
	int currentScreen = 1;
	void GPlay()
	{
		GInit();
		while (!WindowShouldClose() && gameover != true)
		{
			switch (currentScreen)
			{
			case MENU:
				currentScreen++;
				break;
			case PLAY:
				GUpdate();
				GDraw();
				break;
			case GOVER:
				End::EDraw();
				End::EUpdate();
				break;
			}
		}
		CloseWindow();
	}
	void Obstacle()
	{
		ObstacleP = { (float)screenWidth + 100 , (float)GetRandomValue(50, 400) };
		ObstacleS = { 50, (float)GetRandomValue(20,200) };
		obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	}
	void gameOver()
	{
		if (CheckCollisionRecs(player, obstacle))
		{
			currentScreen++;
		
		}
	}
	void GDraw()
	{
		BeginDrawing();
		if (!Paused)
		{
			ClearBackground(RAYWHITE);
			DrawTextureRec(Sky, Cielo, positionStatic, WHITE);
			DrawTextureRec(Cloud, Nubes, position4, WHITE);
			DrawTextureRec(Cloud, Nubes, position5, WHITE);
			DrawTextureRec(ImagenFondo, fondo, position1, WHITE);
			DrawTextureRec(ImagenFondo, fondo2, position2, WHITE);
			DrawTextureRec(ImagenFondo, fondo, position3, WHITE);
			DrawRectangleV({ obstacle.x , obstacle.y }, { obstacle.width, obstacle.height }, BLACK);
			DrawRectangleV({ player.x,player.y }, { player.width , player.height }, MAROON);
			
		}
		else
		{
			ClearBackground(BLACK);
			DrawText("PAUSED", screenWidth / 4, screenHeight / 3, 50, WHITE);
			DrawText("SPACE TO RESUME", screenWidth / 4, screenHeight / 3+60, 50, WHITE);
			DrawText("ESCAPE AGAIN TO EXIT", screenWidth / 4, screenHeight / 3 + 120, 50, WHITE);
		}
		EndDrawing();
	}
	void GUpdate()
	{

		if (!Paused)
		{
			if (IsKeyDown(KEY_UP)) player.y -= 3.0f;
			if (IsKeyDown(KEY_DOWN)) player.y += 3.0f;
			if (IsKeyPressed(KEY_ESCAPE)) 
			{ 
				SetExitKey(KEY_ESCAPE);
				Paused = true; 
			}
			if (player.y > (screenHeight - PlayerSize.y))
			{
				player.y = screenHeight - PlayerSize.y;

			}
			if (player.y < 0)
			{
				player.y = 0;
			}
			obstacle.x = obstacle.x - 250 * GetFrameTime();
			if (obstacle.x < -50)
			{
				Obstacle();
			}
			position1.x += 80 * GetFrameTime();
			if (position1.x > 1000)
			{
				position1.x = position3.x - fondo.width * 2 - 1;
			}
			position2.x += 80 * GetFrameTime();
			if (position2.x > 1000)
			{
				position2.x = position1.x - fondo.width * 2 - 1;
			}
			position3.x += 80 * GetFrameTime();
			if (position3.x > 1000)
			{
				position3.x = position2.x - fondo.width * 2 - 1;
			}
			position4.x -= 40 * GetFrameTime();
			if (position4.x < -1000)
			{
				position4.x = screenWidth;
			}
			position5.x -= 40 * GetFrameTime();
			if (position5.x < -1000)
			{
				position5.x = screenWidth;
			}
			gameOver();
		}
		else
		{
			if (IsKeyPressed(KEY_SPACE))
			{
				SetExitKey(KEY_F12);
				Paused = false;   
			}
		}
	}
	void GInit()
	{
		SetExitKey(KEY_F12);
		InitWindow(screenWidth, screenHeight, "SideScroll Practice");
		SetTargetFPS(60);
		image = LoadImage("res/parallax.png");
		ImagenFondo = LoadTextureFromImage(image);
		sky = LoadImage("res/sky.png");
		Sky = LoadTextureFromImage(sky);
		Cielo = {0.0f,0.0f, (float)Sky.width, (float)Sky.height};
		cloud = LoadImage("res/cloud.png");
		Cloud = LoadTextureFromImage(cloud);
		Nubes = { 0.0f,0.0f, (float)Cloud.width, (float)Cloud.height };
		fondo = { 0.0f, 0.0f, (float)ImagenFondo.width / 2, (float)ImagenFondo.height };
		fondo2 = { 500.0f, 0.0f, (float)ImagenFondo.width / 2, (float)ImagenFondo.height };
		
	}
	void Restart()
	{
		Obstacle();
		player = { PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y };
		obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	}
}