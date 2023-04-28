
#ifndef __MODULEGAMEOVER_H__
#define __MODULEGAMEOVER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	ModuleGameOver();

	~ModuleGameOver();

	update_status Update() override;

	update_status PostUpdate() override;

public:
	iPoint position;

	SDL_Texture* gameover_png = nullptr;
	bool isGameOverOpen = false;

};

#endif 

