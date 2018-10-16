#include "raylib.h"
int screenWidth = 1000;
int screenHeight = 450;	
Vector2 PlayerPos = { 50.0f, screenHeight/2.0f};
Vector2 PlayerSize = { 30,30 };
Vector2 ObstableP = { (float)screenWidth, (float)GetRandomValue(50, 400) };
Vector2 ObstacleS = { 50.0f, GetRandomValue(20,200) };
void Obstacle();
void gameOver();
Rectangle rec1;
Rectangle rec2;
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------


	InitWindow(screenWidth, screenHeight, "SideScroll Practice");
	SetTargetFPS(60);
	while (!WindowShouldClose() )  
	{
		// Update
		if (IsKeyDown(KEY_UP)) PlayerPos.y -= 2.0f;
		if (IsKeyDown(KEY_DOWN)) PlayerPos.y += 2.0f;
		if (PlayerPos.y > 420)
		{PlayerPos.y = 420;}
		if (PlayerPos.y < 0)
		{PlayerPos.y = 0;}
		ObstableP.x = ObstableP.x - 10;
		if (ObstableP.x < -80) 
		{
			Obstacle();
		}
		gameOver();
		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangleV(ObstableP, ObstacleS, BLACK);
		DrawRectangleV(PlayerPos, PlayerSize , MAROON);
		EndDrawing();

	}

	CloseWindow();      
	return 0;
}
void Obstacle() 
{
	ObstableP = { (float)screenWidth + 100 , (float)GetRandomValue(50, 400) };
	ObstacleS = { 50, (float)GetRandomValue(20,200) };
}
void gameOver()
{
	bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                                            
}