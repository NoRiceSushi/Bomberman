#include "IntroInfo.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFade.h"
#include "SceneIntro.h"
#include "StudioNames.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"

IntroInfo::IntroInfo(bool startEnabled) : Module(startEnabled)
{

}
IntroInfo::~IntroInfo()
{

}

// Load assets
bool IntroInfo::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Sprite/descriptionBomberman.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}


update_status IntroInfo::Update()
{

	App->fade->FadeToBlack(this, (Module*)App->studio, 70);

	return update_status::UPDATE_CONTINUE;

}

// Update: draw background
update_status IntroInfo::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}