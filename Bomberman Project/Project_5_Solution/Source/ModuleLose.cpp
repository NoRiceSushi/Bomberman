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
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
#include "ModuleLose.h"
#include "ModuleMenu.h"

ModuleLose::ModuleLose(bool startEnabled) : Module(startEnabled)
{
	AnimLose.PushBack({ 2, 2, 82, 65 });
	AnimLose.PushBack({ 2, 69, 82, 65 });
	AnimLose.PushBack({ 2, 136, 82, 65 });
	AnimLose.PushBack({ 2, 203, 82, 65 });
	AnimLose.PushBack({ 2, 270, 82, 65 });
	AnimLose.PushBack({ 2, 337, 82, 65 });
	AnimLose.PushBack({ 2, 404, 82, 65 });
	AnimLose.PushBack({ 2, 471, 82, 65 });
	AnimLose.PushBack({ 2, 538, 82, 65 });
	AnimLose.PushBack({ 2, 471, 82, 65 });
	AnimLose.PushBack({ 2, 404, 82, 65 });
	AnimLose.PushBack({ 2, 337, 82, 65 });
	AnimLose.PushBack({ 2, 270, 82, 65 });
	AnimLose.PushBack({ 2, 203, 82, 65 });
	AnimLose.PushBack({ 2, 136, 82, 65 });
	AnimLose.PushBack({ 2, 69, 82, 65 });
	AnimLose.PushBack({ 2, 2, 82, 65 });
	AnimLose.speed = 0.3f;
}

ModuleLose::~ModuleLose()
{

}

// Load assets
bool ModuleLose::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	App->score->Disable();
	currentAnimation = &AnimLose;
	SpriteSheetOP_png = App->textures->Load("Assets/SpriteSheetOP.png");
	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	
	//if (App->scene->ReadTile(4, 0) == false || App->scene->ReadTile(5, 0) == false)
	//{
	//	gameover_png = App->textures->Load("Assets/Game_over.png");
	//	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	//	/*App->fade->FadeToBlack(this, (Module*)App->gameover, 90);*/
	//}

	return true;
}

update_status ModuleLose::Update()
{
	currentAnimation->Update();

	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart < 1500) {
		return update_status::UPDATE_CONTINUE;
	}
	else {
		App->fade->FadeToBlack(this, (Module*)App->gameover, 40);
		return update_status::UPDATE_CONTINUE;
	}
	
}

// Update: draw background
update_status ModuleLose::PostUpdate()
{
	if (!App->menu->isMenuOpen) {
		// Draw everything --------------------------------------
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(SpriteSheetOP_png, 49, 80, &rect);
	}
	return update_status::UPDATE_CONTINUE;
}