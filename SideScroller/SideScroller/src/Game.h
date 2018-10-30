#ifndef GAME_H
#define GAME_H
#include "raylib.h"
using namespace std;
namespace Game
{
	extern int screenWidth;
	extern int screenHeight;
	static Vector2 PlayerPos;
	static Vector2 PlayerSize;
	static Vector2 ObstableP;
	static Vector2 ObstacleS;
	void GDraw();
	void GUpdate();
	void GInit();
	void GPlay();
	void Restart();
	extern bool gameover;
	static Image groundImage;
	static Texture2D GroundText;
	extern Texture2D SkyText;
	extern Texture2D GroundText;
	static Texture2D CloudText;
	static Rectangle Ground1;
	static Rectangle Ground2;
	extern Rectangle Sky1;
	static Rectangle Cloud1;
	static Rectangle player;
	static Rectangle obstacle;
	extern Vector2 position1;
	static Vector2 position2;
	static Vector2 position3;
	extern int currentScreen;
	extern bool player1;
};
#endif

