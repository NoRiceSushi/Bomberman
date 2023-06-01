#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include<algorithm>

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene(bool startEnabled);

	~ModuleScene();

	bool Start() override;

	update_status Update() override;

	update_status PostUpdate() override;

	void SetTile(int x, int y, char value);

	bool ReadTile(int x, int y);
	bool isLeftEmpty(int x, int y);
	bool isRightEmpty(int x, int y);
	bool isDownEmpty(int x, int y);
	bool isDownLessEmpty(int x, int y);

	void DestroyLines();
	int Score = 0;
public:
	
	char map[12][8];


	/*
	 
	-,-,-,X,X,-,-,-
	-,-,-,X,X,-,-,-
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	
	*/

public:

	iPoint position;
	SDL_Rect rectG;
	SDL_Rect rectY;
	SDL_Rect rectR;
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* bgTexture2 = nullptr;
	SDL_Texture* bgBorders = nullptr;

	Animation* currentAnimation = nullptr;
	Animation* currentAnimY = nullptr;
	Animation* currentAnimR = nullptr;
	Animation AnimBorders;
	Animation AnimBordersy;
	Animation AnimBordersr;
};

#endif