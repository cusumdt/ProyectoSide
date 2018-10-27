#include "raylib.h"
#include "End.h"
#include "Menu.h"
namespace Game
{
	const int MENU = 1;
	const int PLAY = 2;
	const int GOVER = 3;
	int screenWidth = 1000;
	int screenHeight = 450;
	bool gameover = false;
	Vector2 PlayerPos = { 150.0f, screenHeight / 2.0f };
	Vector2 PlayerSize = { 32.0f,16.0f };
	Vector2 ObstacleP = { (float)screenWidth, (float)GetRandomValue(50, 400) };
	Vector2 ObstacleS = { 50.0f, GetRandomValue(20,200) };
	void Obstacle();
	void gameOver();
	void GDraw();
	void GUpdate();
	void GInit();
	void Restart();
	bool Paused = false;
	Image groundImage;
	Image skyImage;
	Image cloudImage;
	Image pcImage;
	Texture2D PCText;
	Texture2D SkyText;
	Texture2D GroundText;
	Texture2D CloudText;
	Rectangle Ground1;
	Rectangle Ground2;
	Rectangle Sky1;
	Rectangle Cloud1;
	Rectangle playeranim;
	Rectangle player = { PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y };
	Rectangle obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	Vector2 position1 = { 0.0f, 0.0f };
	Vector2 position3 = { -1000.0f, 0.0f };
	Vector2 position4 = { 0.0f, 0.0f };
	Vector2 position5 = { 1000.0f, 0.0f };
	Vector2 positionStatic = {0.0f, 0.0f};
	Sound JumpSound;
	float playerAccel = 10.0f;
	int PCFrame = 1;
	int fpsFrame = 0;
	int currentScreen = 1;
	void GPlay()
	{
		GInit();
		while (!WindowShouldClose() && gameover != true)
		{
			switch (currentScreen)
			{
			case MENU:
				MUpdate();
				MDraw();
				break;
			case PLAY:
				GUpdate();
				GDraw();
				break;
			case GOVER:
				EDraw();
				EUpdate();
				break;
			}
		}
		UnloadSound(JumpSound);
		CloseAudioDevice();
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
		player.y = PlayerPos.y;
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
			DrawTextureRec(SkyText, Sky1, positionStatic, WHITE);
			DrawTextureRec(CloudText, Cloud1, position4, WHITE);
			DrawTextureRec(CloudText, Cloud1, position5, WHITE);			
			DrawTextureRec(GroundText, Ground1, position1, WHITE);
			DrawTextureRec(GroundText, Ground1, position3, WHITE);			
			DrawRectangleV({ obstacle.x , obstacle.y }, { obstacle.width, obstacle.height }, BLACK);
			DrawTextureRec(PCText, playeranim, PlayerPos, WHITE);
			DrawText("Press UP to jump, ESC to pause", 5, 430, 15, BLACK);
		}
		else
		{
			ClearBackground(WHITE);
			DrawTextureRec(SkyText, Sky1, positionStatic, WHITE);
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
			//if (IsKeyDown(KEY_UP)) PlayerPos.y -= 3.0f;
			//if (IsKeyDown(KEY_DOWN)) PlayerPos.y += 3.0f;
			if (IsKeyPressed(KEY_UP))
			{
				PlaySound(JumpSound);
				playerAccel = -80.0f;
			}
			PlayerPos.y = PlayerPos.y + (float)playerAccel;
			playerAccel = +130*GetFrameTime();
			if (IsKeyPressed(KEY_ESCAPE)) 
			{ 
				SetExitKey(KEY_ESCAPE);
				Paused = true; 
			}
			if (PlayerPos.y > (screenHeight - PlayerSize.y))
			{
				currentScreen++;

			}
			if (PlayerPos.y < 0)
			{
				PlayerPos.y = 0;
			}
			obstacle.x = obstacle.x - 250 * GetFrameTime();
			if (obstacle.x < -50)
			{
				Obstacle();
			}
			position1.x += 80 * GetFrameTime();
			if (position1.x >= 1000)
			{
				position1.x = position3.x - Ground1.width;
			}
			position3.x += 80 * GetFrameTime();
			if (position3.x >= 1000)
			{
				position3.x = position1.x - Ground1.width;
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
			fpsFrame++;
			if (fpsFrame > 6)
			{
				fpsFrame = 0;
				PCFrame++;
				if (PCFrame > 2) { PCFrame = 1; }
				playeranim.y = ((float)PCFrame * PCText.height / 2);
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
		InitAudioDevice();
		JumpSound = LoadSound("res/jump.wav");
		pcImage = LoadImage("res/Player.png");
		PCText = LoadTextureFromImage(pcImage);
		playeranim = { 0.0f, 0.0f, (float)PCText.width, (float)PCText.height / 2 };
		groundImage = LoadImage("res/parallax.png");
		GroundText = LoadTextureFromImage(groundImage);
		skyImage = LoadImage("res/sky.png");
		SkyText = LoadTextureFromImage(skyImage);
		Sky1 = {0.0f,0.0f, (float)SkyText.width, (float)SkyText.height};
		cloudImage = LoadImage("res/cloud.png");
		CloudText = LoadTextureFromImage(cloudImage);
		Cloud1 = { 0.0f,0.0f, (float)CloudText.width, (float)CloudText.height };
		Ground1 = { 0.0f, 0.0f, (float)GroundText.width, (float)GroundText.height };

		
	}
	void Restart()
	{
		Obstacle();
		PlayerPos = { 150.0f, screenHeight / 2.0f };
		obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	}
}