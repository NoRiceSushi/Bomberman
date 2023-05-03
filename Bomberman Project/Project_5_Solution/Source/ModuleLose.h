#ifndef __MODULELOSE_H__
#define __MODULELOSE_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleLose : public Module
{
public:
	//Constructor
	ModuleLose(bool startEnabled);

	//Destructor
	~ModuleLose();

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

	Uint32 timerStart = 0;
	bool timerStarted = false;
	// The scene sprite sheet loaded into an SDL_Texture

	SDL_Texture* SpriteSheetOP_png = nullptr;

	Animation* currentAnimation = nullptr;
	Animation AnimLose;

};

#endif 

