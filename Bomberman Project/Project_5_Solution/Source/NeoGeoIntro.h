#ifndef __NEOGEO_H__
#define __NEOGEO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class NeoGeoIntro : public Module
{
public:
	//Constructor
	NeoGeoIntro(bool startEnabled);

	//Destructor
	~NeoGeoIntro();

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
	SDL_Texture* bgBorders = nullptr;
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
	SDL_Texture* Starting10 = nullptr;
	SDL_Texture* Starting11 = nullptr;
	SDL_Texture* Starting12 = nullptr;
	SDL_Texture* Starting13 = nullptr;
	SDL_Texture* Starting14 = nullptr;
	SDL_Texture* Starting15 = nullptr;
	SDL_Texture* Starting16 = nullptr;
	SDL_Texture* Starting17 = nullptr;
	SDL_Texture* Starting18 = nullptr;
	SDL_Texture* Starting19 = nullptr;
	SDL_Texture* Starting20 = nullptr;
	SDL_Texture* Starting21 = nullptr;
	SDL_Texture* Starting22 = nullptr;
	SDL_Texture* Starting23 = nullptr;
	SDL_Texture* Starting24 = nullptr;
	SDL_Texture* Starting25 = nullptr;
	SDL_Texture* Starting26 = nullptr;
	SDL_Texture* Starting27 = nullptr;
	SDL_Texture* Starting28 = nullptr;
	SDL_Texture* Starting29 = nullptr;
	SDL_Texture* Starting30 = nullptr;
	SDL_Texture* Starting31 = nullptr;
	SDL_Texture* Starting32 = nullptr;
	SDL_Texture* Starting33 = nullptr;
	SDL_Texture* Starting34 = nullptr;
	SDL_Texture* Starting35 = nullptr;
	SDL_Texture* Starting36 = nullptr;


	Uint32 timerStart = 0;
	bool timerStarted = false;

	uint sfx_explosion = 0;
};

#endif
