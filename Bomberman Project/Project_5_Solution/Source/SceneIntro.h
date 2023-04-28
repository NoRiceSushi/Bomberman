#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneIntro : public Module
{
public:
	SceneIntro(bool startEnabled);

	~SceneIntro();

	bool Start() override;

	update_status Update() override;

	update_status PostUpdate() override;

public:
	SDL_Texture* bgTexture = nullptr;
};

#endif#pragma once
