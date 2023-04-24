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
	ModuleScene();

	~ModuleScene();

	bool Start() override;

	update_status Update() override;

	update_status PostUpdate() override;

	void SetTile(int x, int y, char value);
	bool isYEmpty(int x, int y);

private:
	
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

	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* bgTexture2 = nullptr;
};

#endif