#pragma once
#ifndef __MODULE_SCORE_H__
#define __MODULE_SCORE_H__

#include "Module.h"
#include "Globals.h"
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
	char scoreText[MAX_SCORE_LENGTH + sizeof(char)];



};

#endif // __MODULE_SCORE_H__