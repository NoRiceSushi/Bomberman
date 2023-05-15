#pragma once
#ifndef __MODULE_SCORE_H__
#define __MODULE_SCORE_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

#define MAX_SCORE_LENGTH 10

class ModuleScore: public Module
{
public:
	ModuleScore(bool startEnabled);    // default constructor declaration
	~ModuleScore();   // destructor declaration

	bool Init() override;
	bool Start() override;
	update_status Update() override;
	update_status PostUpdate() override;

	// Font score index
	uint score = 000000;
	int scoreFont = -1;
	iPoint position;
	bool readyScreenEnd;
	float posSpeed;
	bool readyOnPos;

	SDL_Texture* textureCoins = nullptr;
	
	SDL_Texture* insertCoins = nullptr;
	Animation* coinCurrentAnim = nullptr;
	Animation Blink;
	Animation Out;

	SDL_Texture* ready = nullptr;
	Animation* readyAnim = nullptr;
	Animation readyIn;
	Animation readyOut;

	char scoreText[MAX_SCORE_LENGTH + sizeof(char)];

	uint coins = 00;
	uint sfx_coin = 0;

	SDL_Rect rect1;
	SDL_Rect rect2;
};

#endif // __MODULE_SCORE_H__