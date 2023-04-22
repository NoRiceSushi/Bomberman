#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "Puyo.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();

	~ModulePlayer();

	update_status Update() override;

	update_status PostUpdate() override;

public:
	Puyo* Group[1] = { nullptr };
	fPoint position;
	int speed = 1;
	bool active = true;

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
