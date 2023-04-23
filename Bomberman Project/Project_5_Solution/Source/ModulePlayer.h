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
	struct Puyo
	{
		fPoint position;
		int speed = 1;
		bool active = true;
		int verde = 0;
		char color;

		Animation* currentAnimation = nullptr;

		Animation idleAnim;
		Animation upAnim;
		Animation downAnim;
	}p[4];
	
	
	SDL_Texture* texture = nullptr;

};

#endif //!__MODULE_PLAYER_H__
