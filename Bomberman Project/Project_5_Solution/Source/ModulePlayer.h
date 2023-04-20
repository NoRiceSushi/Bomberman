#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();

	~ModulePlayer();

	bool Start() override;

	update_status Update() override;

	update_status PostUpdate() override;

public:
	fPoint position[5];

	int speed = 1;
	bool down = true;

	int verde = 0;
	SDL_Texture* texture = nullptr;
	
	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
};

#endif //!__MODULE_PLAYER_H__
