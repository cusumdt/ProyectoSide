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
	extern Image image;
	extern Texture2D ImagenFondo;
	extern Texture2D Sky;
	extern Texture2D ImagenFondo;
	extern Texture2D Cloud;
	extern Rectangle fondo;
	extern Rectangle fondo2;
	extern Rectangle Cielo;
	extern Rectangle Nubes;
	extern Rectangle player;
	extern Rectangle obstacle;
	extern Vector2 position1;
	extern Vector2 position2;
	extern Vector2 position3;
	extern int currentScreen;
};
#endif

