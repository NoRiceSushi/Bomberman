#ifndef __MODULEGAMEOVER_H__
#define __MODULEGAMEOVER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	//Constructor
	ModuleGameOver(bool startEnabled);

	//Destructor
	~ModuleGameOver();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

public:
	iPoint position;
	iPoint positionLetterG;
	iPoint positionLetterA;
	Uint32 timerStart = 0;
	bool timerStarted = false;
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* gameover_png = nullptr;

	SDL_Texture* letter = nullptr;
	Animation* LettersAnimationG = nullptr;
	Animation* LettersAnimationA = nullptr;
	Animation* LettersAnimationM = nullptr;
	Animation* LettersAnimationE = nullptr;
	Animation* LettersAnimationO = nullptr;
	Animation* LettersAnimationV = nullptr;
	Animation* LettersAnimationE2 = nullptr;
	Animation* LettersAnimationR = nullptr;
	Animation AnimLettersG;
	Animation AnimLettersA;
	Animation AnimLettersM;
	Animation AnimLettersE;
	Animation AnimLettersO;
	Animation AnimLettersV;
	Animation AnimLettersE2;
	Animation AnimLettersR;
	int targetPosG = 49;
	int targetPosA = 49;
	int targetPosM = 49;
	int targetPosE = 49;
	int targetPosO = 113;
	int targetPosV = 113;
	int targetPosE2 = 113;
	int targetPosR = 113;
	bool moveLettersG = true;
	bool moveLettersA = true;
	bool moveLettersM = true;
	bool moveLettersE = true;
	bool moveLettersO = true;
	bool moveLettersV = true;
	bool moveLettersE2 = true;
	bool moveLettersR = true;
	int lettersPosG = -46;
	int lettersPosA = -46;
	int lettersPosM = -46;
	int lettersPosE = -46;
	int lettersPosO = -46;
	int lettersPosV = -46;
	int lettersPosE2 = -46;
	int lettersPosR = -46;

	bool LetterAOnPos;


};

#endif 
