#include "raylib.h"
#include "End.h"
#include "Menu.h"
#include <iostream>
using namespace std;
namespace Game
{
	bool player1;
	const int MENU = 1;
	const int PLAY = 2;
	const int GOVER = 3;
	int screenWidth = 1000;
	int screenHeight = 450;
	bool gameover = false;
	Vector2 PlayerPos = { 150.0f, screenHeight / 100 * 40 };
	Vector2 Player2Pos = { 150.0f, screenHeight / 2.0f };
	Vector2 Player2Size = { 32.0f,16.0f };
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
	Image player2Image;
	Texture2D PCText;
	Texture2D player2Texture;
	Texture2D SkyText;
	Texture2D GroundText;
	Texture2D CloudText;
	Rectangle recMusic = { 0.0f,0.0f,60.0f,20.0f };
	Rectangle Ground1;
	Rectangle Ground2;
	Rectangle Sky1;
	Rectangle Cloud1;
	Rectangle playeranim;
	Rectangle player2Anim;
	Rectangle player = { PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y };
	Rectangle player2 = { Player2Pos.x, Player2Pos.y, (float)Player2Size.x, (float)Player2Size.y };
	Rectangle obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	Vector2 position1 = { -1.0f, 0.0f };
	Vector2 position3 = { -999.0f, 0.0f };
	Vector2 position4 = { 0.0f, 0.0f };
	Vector2 position5 = { 1000.0f, 0.0f };
	Vector2 positionStatic = { 0.0f, 0.0f };
	Vector2 mouse;
	//Sound JumpSound;
	//Music music;
	float playerAccel = 10.0f;
	float player2Accel = 10.0f;
	int PCFrame = 1;
	int fpsFrame = 0;
	int currentScreen = 1;
	bool soundPlaying = true;
	void GPlay()
	{
		GInit();
		while (!WindowShouldClose() && gameover != true)
		{
			switch (currentScreen)
			{
			case MENU:
				SetExitKey(KEY_ESCAPE);
				MUpdate();
				MDraw();
				break;
			case PLAY:
				SetExitKey(KEY_F12);
				GUpdate();
				GDraw();
				break;
			case GOVER:
				EDraw();
				EUpdate();
				break;
			}
		}
		//UnloadMusicStream(music);
		//UnloadSound(JumpSound);
		//CloseAudioDevice();
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
		if (p2)
		{
			if (CheckCollisionRecs(player2, obstacle))
			{
				player1 = false;
				currentScreen++;
			}
		}
		if (CheckCollisionRecs(player, obstacle))
		{
			player1 = true;
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
			if (p2)
			{
				DrawTextureRec(player2Texture, player2Anim, Player2Pos, GREEN);
				DrawText("P1 Press UP to jump, P2 Press SPACE to jump, ESC to pause", 5, 430, 15, BLACK);
			}
			else
			{
				DrawText("Press UP to jump, ESC to pause", 5, 430, 15, BLACK);
			}
			DrawRectangle(recMusic.x, recMusic.y, recMusic.width, recMusic.height, BLUE);
			DrawText("M U T E", recMusic.x / 2, recMusic.y / 2, 15, WHITE);
		}
		else
		{
			ClearBackground(WHITE);
			DrawTextureRec(SkyText, Sky1, positionStatic, WHITE);
			DrawText("PAUSED", screenWidth / 4, screenHeight / 3, 50, WHITE);
			DrawText("SPACE TO RESUME", screenWidth / 4, screenHeight / 3 + 60, 50, WHITE);
			DrawText("ESCAPE AGAIN TO EXIT", screenWidth / 4, screenHeight / 3 + 120, 50, WHITE);
		}
		EndDrawing();
	}
	void GUpdate()
	{

		if (!Paused)
		{
			if (soundPlaying)
			{
				//UpdateMusicStream(music);
				//PlayMusicStream(music);
			}
			mouse = GetMousePosition();
			if (CheckCollisionPointRec(mouse, recMusic))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					//soundPlaying = !soundPlaying;
				}
			}
			if (IsKeyPressed(KEY_UP))
			{

				//if(soundPlaying)PlaySound(JumpSound);
				playerAccel = -80.0f;
			}
			if (p2)
			{
				if (IsKeyPressed(KEY_SPACE))
				{

					//if(soundPlaying)PlaySound(JumpSound);
					player2Accel = -80.0f;
					cout << p2<<endl;
				}
				Player2Pos.y = Player2Pos.y + (float)player2Accel;
				player2Accel = +130 * GetFrameTime();
			}
			PlayerPos.y = PlayerPos.y + (float)playerAccel;
			playerAccel = +130 * GetFrameTime();
			if (IsKeyPressed(KEY_ESCAPE))
			{

				Paused = true;
			}
			if (PlayerPos.y > (screenHeight - PlayerSize.y))
			{
				currentScreen++;

			}
			if (p2)
			{
				if (Player2Pos.y > (screenHeight - Player2Size.y))
				{
					currentScreen++;

				}
			}
			if (PlayerPos.y < 0)
			{
				PlayerPos.y = 0;
			}
			if (p2)
			{
				if (Player2Pos.y < 0)
				{
					Player2Pos.y = 0;
				}
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
				if (p2)
				{
					player2Anim.y = ((float)PCFrame * player2Texture.height / 2);

				}
			}

			gameOver();
		}
		else
		{
			if (IsKeyPressed(KEY_ESCAPE))
			{
				currentScreen--;
			}
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
		//InitAudioDevice();
		//music = LoadMusicStream("res/music.ogg");
		//JumpSound = LoadSound("res/jump.wav");
		pcImage = LoadImage("res/Player.png");
		PCText = LoadTextureFromImage(pcImage);
		player2Image = LoadImage("res/Player.png");
		player2Texture = LoadTextureFromImage(player2Image);
		player2Anim = { 0.0f, 0.0f, (float)player2Texture.width, (float)player2Texture.height / 2 };
		playeranim = { 0.0f, 0.0f, (float)PCText.width, (float)PCText.height / 2 };
		groundImage = LoadImage("res/parallax.png");
		GroundText = LoadTextureFromImage(groundImage);
		skyImage = LoadImage("res/sky.png");
		SkyText = LoadTextureFromImage(skyImage);
		Sky1 = { 0.0f,0.0f, (float)SkyText.width, (float)SkyText.height };
		cloudImage = LoadImage("res/cloud.png");
		CloudText = LoadTextureFromImage(cloudImage);
		Cloud1 = { 0.0f,0.0f, (float)CloudText.width, (float)CloudText.height };
		Ground1 = { 0.0f, 0.0f, (float)GroundText.width, (float)GroundText.height };
	}
	void Restart()
	{
		Paused = false;
		//StopMusicStream(music);
		//PlayMusicStream(music);
		Obstacle();
		PlayerPos = { 150.0f, screenHeight / 2.0f };
		Player2Pos = { 150.0f, screenHeight / 2.0f };
		obstacle = { ObstacleP.x, ObstacleP.y, (float)ObstacleS.x, (float)ObstacleS.y };
	}
}