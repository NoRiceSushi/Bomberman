#ifndef __MODULE_BOMBAZO_H__
#define __MODULE_BOMBAZO_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleBombazo : public Module
{
public:

	ModuleBombazo(bool startEnabled);



	~ModuleBombazo();

	bool Start() override;
	update_status Update() override;
	update_status PostUpdate() override;
	/*void Bomb();
	void Activation();*/

public:

	int x, y;
	/*int speed = 1;
	SDL_Texture* texture = nullptr;*/


	fPoint position;

	bool active = true;
	int col;


	Animation* currentAnimation = nullptr;

	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;



	float speed = 0.5;
	int air = 0;
	int minX, maxX, minY, maxY;
	SDL_Texture* texture = nullptr;
	uint sfx_rotate = 0;
};

#endif //!__MODULE_BOMBAZO_H__