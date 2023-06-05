#include "ModuleGameOver.h"
#include "ModuleInput.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"
#include "ModulePlayer.h"
#include "ModuleFade.h"
#include "ModuleScore.h"
#include "ClearStage1.h"

ClearStage1::ClearStage1(bool startEnabled) : Module(startEnabled)
{

}

ClearStage1::~ClearStage1()
{

}

// Load assets
bool ClearStage1::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	Stage_Clear_png = App->textures->Load("Assets/Sprite/Stage_Clear.png");
	App->audio->PlayMusic("Assets/audio/20_Stage_Clear.ogg", 1.0f);

	return true;
}

update_status  ClearStage1::Update()
{
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status  ClearStage1::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(Stage_Clear_png, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}