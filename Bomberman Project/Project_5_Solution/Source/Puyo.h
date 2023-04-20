#include "p2Point.h"
#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class Puyo {
public:
	Puyo();

	~Puyo();

	void UpdatePuyo();

private:
	int color=1;
	fPoint position;
	float speed= 0.5;

	Animation* currentAnimation = nullptr;

	Animation downAnim;
	Animation stayAnim;
	Animation moveAnim;
};