#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneIntro : public Module
{
public:
	//Constructor
	SceneIntro(bool startEnabled);

	//Destructor
	~SceneIntro();

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
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* InsertA = nullptr;
	SDL_Texture* Starting1 = nullptr;
	SDL_Texture* Starting2 = nullptr;
	SDL_Texture* Starting3 = nullptr;
	SDL_Texture* Starting4 = nullptr;
	SDL_Texture* Starting5 = nullptr;
	SDL_Texture* Starting6 = nullptr;
	SDL_Texture* Starting7 = nullptr;
	SDL_Texture* Starting8 = nullptr;
	SDL_Texture* Starting9 = nullptr;
	Animation* AnimBlink;
	Animation Blink;
	SDL_Rect rectBlink;

	Uint32 timerStart = 0;
	bool timerStarted = false;

	uint sfx_explosion = 0;
};

#endif