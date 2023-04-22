#ifndef __PUYO__
#define __PUYO__

#include "p2Point.h"
#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class Puyo : public Module	{

public:
	Puyo();

	~Puyo();

	bool Start() override;
	void UpdatePuyo();

public:
	int color=1;
	float speed = 1;
	fPoint position;

	SDL_Texture* texture = nullptr;

	Animation* currentAnimation = nullptr;

	Animation downAnim;
	Animation stayAnim;
	Animation moveAnim;
};

#endif  //__PUYO__