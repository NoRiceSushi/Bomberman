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
	float posSpeedBomba;
	float posSpeedGo;
	bool readyOnPos;
	bool bombOnPos;
	iPoint positionBomba;
	iPoint positionGo;
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* textureCoins = nullptr;
	
	SDL_Texture* insertCoins = nullptr;
	Animation* coinCurrentAnim = nullptr;
	Animation Blink;
	Animation Out;

	SDL_Texture* ready = nullptr;
	Animation* readyAnim = nullptr;
	Animation readyIn;
	Animation readyOut;

	SDL_Texture* bombazaText = nullptr;
	SDL_Texture* explosionText = nullptr;
	SDL_Texture* goText = nullptr;

	Animation* bombaAnim = nullptr;
	Animation bombaIdle;
	Animation bombaOut;

	Animation* explosionAnim = nullptr;
	Animation explosionBomb;
	Animation explosionOut;

	Animation* goAnim = nullptr;
	Animation goIdle;
	Animation goOut;

	SDL_Texture* bomb = nullptr;
	Animation* bomb1Anim = nullptr;
	Animation* bomb2Anim = nullptr;
	Animation* bomb3Anim = nullptr;
	Animation* bomb4Anim = nullptr;
	Animation* bomb5Anim = nullptr;
	Animation* bomb6Anim = nullptr;
	Animation* bomb7Anim = nullptr;
	Animation bomb1;
	Animation bomb2;
	Animation bomb3;
	Animation bomb4;
	Animation bomb5;
	Animation bomb6;
	Animation bomb7;

	char scoreText[MAX_SCORE_LENGTH + sizeof(char)];

	uint coins = 00;
	uint sfx_coin = 0;

	SDL_Rect rect1;
	SDL_Rect rect2;
	SDL_Rect rectBomb;
	SDL_Rect rectExplosion;
	SDL_Rect rectGo;
	SDL_Rect rectbomb1;
	SDL_Rect rectbomb2;
	SDL_Rect rectbomb3;
	SDL_Rect rectbomb4;
	SDL_Rect rectbomb5;
	SDL_Rect rectbomb6;
	SDL_Rect rectbomb7;
};

#endif // __MODULE_SCORE_H__