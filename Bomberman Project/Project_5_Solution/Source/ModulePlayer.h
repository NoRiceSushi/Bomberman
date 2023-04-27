#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(int x, int y);

	~ModulePlayer();

	bool Start() override;
	update_status Update() override;
	update_status PostUpdate() override;

	void Activation();

public:
	struct Puyo
	{
		fPoint position;

		bool active = true;
		int col;
		char color = '0';

		Animation* currentAnimation = nullptr;

		Animation idleAnim;
		Animation upAnim;
		Animation downAnim;
	};

	int verde = 0;
	struct Puyo p[3];
	int speed = 2;
	int air = 0;
	int minX, maxX, minY, maxY;
	SDL_Texture* texture = nullptr;
};

#endif //!__MODULE_PLAYER_H__
