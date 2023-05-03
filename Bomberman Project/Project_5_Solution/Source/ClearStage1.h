#ifndef __CLEARSTAGE1_H__
#define __CLEARSTAGE1_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ClearStage1 : public Module
{
public:
	//Constructor
	ClearStage1(bool startEnabled);

	//Destructor
	~ClearStage1();

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

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* Stage_Clear_png = nullptr;

};

#endif 