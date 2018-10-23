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
void Draw();
void Update();
void Init();
Image image;
Texture2D ImagenFondo;
Rectangle fondo;
Rectangle fondo2;
Rectangle player = {PlayerPos.x, PlayerPos.y, (float)PlayerSize.x, (float)PlayerSize.y};
Rectangle obstacle = { 0.0f, 0.0f, (float)ImagenFondo.width / 2, (float)ImagenFondo.height };
Vector2 position1 = { 0.0f, 0.0f };
Vector2 position2 = { 500.0f, 0.0f };
Vector2 position3 = { -500.0f, 0.0f };
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	Init();
	while (!WindowShouldClose() )  
	{
		Update();
		Draw();
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
void Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);	
	DrawTextureRec(ImagenFondo, fondo, position1, WHITE);
	DrawTextureRec(ImagenFondo, fondo2, position2, WHITE);
	DrawTextureRec(ImagenFondo, fondo, position3, WHITE);
	DrawRectangleV(ObstableP, ObstacleS, BLACK);
	DrawRectangleV(PlayerPos, PlayerSize, MAROON);
	EndDrawing();
}

void Update()
{
	if (IsKeyDown(KEY_UP)) PlayerPos.y -= 2.0f;
	if (IsKeyDown(KEY_DOWN)) PlayerPos.y += 2.0f;
	if (PlayerPos.y > 420)
	{
		PlayerPos.y = 420;
	}
	if (PlayerPos.y < 0)
	{
		PlayerPos.y = 0;
	}
	ObstableP.x = ObstableP.x - 10;
	if (ObstableP.x < -80)
	{
		Obstacle();
	}
	position1.x += 80 * GetFrameTime();
	if (position1.x > 1000)
	{
		position1.x = position3.x-fondo.width*2;
	}
	position2.x += 80 * GetFrameTime();
	if (position2.x > 1000)
	{
		position2.x = position1.x- fondo.width*2;
	}
	position3.x += 80 * GetFrameTime();
	if (position3.x > 1000)
	{
		position3.x = position2.x- fondo.width*2;
	}
	gameOver();
}
void Init()
{

	InitWindow(screenWidth, screenHeight, "SideScroll Practice");
	SetTargetFPS(60);	
	image = LoadImage("res/parallax.png");    
	ImagenFondo = LoadTextureFromImage(image);
	fondo = { 0.0f, 0.0f, (float)ImagenFondo.width / 2, (float)ImagenFondo.height };
	fondo2 = { 500.0f, 0.0f, (float)ImagenFondo.width / 2, (float)ImagenFondo.height };
}