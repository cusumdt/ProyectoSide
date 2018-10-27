#ifndef GAME_H
#define GAME_H
#include "raylib.h"
using namespace std;
namespace Game
{
	extern int screenWidth;
	extern int screenHeight;
	extern Vector2 PlayerPos;
	extern Vector2 PlayerSize;
	extern Vector2 ObstableP;
	extern Vector2 ObstacleS;
	extern Rectangle rec1;
	extern Rectangle rec2;
	void GDraw();
	void GUpdate();
	void GInit();
	void GPlay();
	void Restart();
	extern bool gameover;
	extern Image groundImage;
	extern Texture2D GroundText;
	extern Texture2D SkyText;
	extern Texture2D GroundText;
	extern Texture2D CloudText;
	extern Rectangle Ground1;
	extern Rectangle Ground2;
	extern Rectangle Sky1;
	extern Rectangle Cloud1;
	extern Rectangle player;
	extern Rectangle obstacle;
	extern Vector2 position1;
	extern Vector2 position2;
	extern Vector2 position3;
	extern int currentScreen;
};
#endif

