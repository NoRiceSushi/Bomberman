#include "StudioNames.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFade.h"
#include "SceneIntro.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"

StudioNames::StudioNames(bool startEnabled) : Module(startEnabled)
{

}

StudioNames::~StudioNames()
{

}

// Load assets
bool StudioNames::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Sprite/SSWstudionames.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status StudioNames::Update()
{

	App->fade->FadeToBlack(this, (Module*)App->neogeo, 70);

	return update_status::UPDATE_CONTINUE;

}

// Update: draw background
update_status StudioNames::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}