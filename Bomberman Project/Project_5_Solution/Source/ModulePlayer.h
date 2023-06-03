#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool startEnabled);

	~ModulePlayer();

	bool Start() override;
	update_status Update() override;
	update_status PostUpdate() override;
	void Bomb();
	void Activation();

public:

	int x, y;
	/*int speed = 1;
	SDL_Texture* texture = nullptr;*/
	struct Puyo
	{
		fPoint position;

		bool active = true;
		int col;
		char color = '0';
		int pos;

		Animation* currentAnimation = nullptr;

		Animation WhiteidleAnim;
		Animation RedidleAnim;
		Animation BlueidleAnim;
		Animation BlackidleAnim;
		Animation GreenidleAnim;

		Animation upAnim;
		Animation downAnim;


		Animation WhiteOutAnim;
		Animation RedOutAnim;
		Animation BlueOutAnim;
		Animation BlackOutAnim;
		Animation GreenOutAnim;
	};

	struct Puyo p[3];
	float speed = 0.5;
	int air = 0;
	int minX, maxX, minY, maxY;
	SDL_Texture* texture = nullptr;
	uint sfx_rotate = 0;

};

#endif //!__MODULE_PLAYER_H__

