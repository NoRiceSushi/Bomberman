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
#include "ModulePlayers.h"
#include "ModuleFade.h"
#include "ModuleScore.h"
#include "ModuleLose.h"

ModuleGameOver::ModuleGameOver(bool startEnabled) : Module(startEnabled)
{
	
}

ModuleGameOver::~ModuleGameOver()
{

}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	gameover_png = App->textures->Load("Assets/Game_over.png");
	App->audio->PlayMusic("Assets/audio/24_Game_Over.ogg", 1.0f);
	App->players->Disable();
	App->player->Disable();
	App->lose->Disable();
	App->scene->Disable();
	//if (App->scene->ReadTile(4, 0) == false || App->scene->ReadTile(5, 0) == false)
	//{
	//	gameover_png = App->textures->Load("Assets/Game_over.png");
	//	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	//	/*App->fade->FadeToBlack(this, (Module*)App->gameover, 90);*/
	//}
	
	return true;
}

update_status ModuleGameOver::Update()
{

	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart < 4000) {
		return update_status::UPDATE_CONTINUE;
	}
	else {
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
		return update_status::UPDATE_CONTINUE;
	}
	
	
}

// Update: draw background
update_status ModuleGameOver::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(gameover_png, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}