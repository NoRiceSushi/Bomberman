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
#include "ModuleWin.h"
#include "ModuleMenu.h"

ModuleWin::ModuleWin(bool startEnabled) : Module(startEnabled)
{
	AnimWin.PushBack({ 86, 2, 118, 101 });
	AnimWin.PushBack({ 86, 105, 118, 101 });
	AnimWin.PushBack({ 86,208, 118, 101 });
	AnimWin.PushBack({ 86, 311, 118, 101 });
	AnimWin.PushBack({ 86, 414, 118, 101 });
	AnimWin.PushBack({ 86, 414, 118, 101 });
	AnimWin.PushBack({ 86, 311, 118, 101 });
	AnimWin.PushBack({ 86,208, 118, 101 });
	AnimWin.PushBack({ 86, 105, 118, 101 });
	AnimWin.PushBack({ 86, 2, 118, 101 });
	AnimWin.speed = 0.4f;
}

ModuleWin::~ModuleWin()
{

}

// Load assets
bool ModuleWin::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	App->score->Disable();
	currentAnimation = &AnimWin;
	SpriteSheetOP_png = App->textures->Load("Assets/SpriteSheetOP.png");
	App->audio->PlayMusic("Assets/audio/18_Win.ogg", 1.0f);

	//if (App->scene->ReadTile(4, 0) == false || App->scene->ReadTile(5, 0) == false)
	//{
	//	gameover_png = App->textures->Load("Assets/Game_over.png");
	//	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	//	/*App->fade->FadeToBlack(this, (Module*)App->gameover, 90);*/
	//}

	return true;
}

update_status ModuleWin::Update()
{
	currentAnimation->Update();

	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart <2000) {
		return update_status::UPDATE_CONTINUE;
	}
	else {
		App->fade->FadeToBlack(this, (Module*)App->clearstage1, 70);
		return update_status::UPDATE_CONTINUE;
	}

}

// Update: draw background
update_status ModuleWin::PostUpdate()
{
	if (!App->menu->isMenuOpen) {
		// Draw everything --------------------------------------
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(SpriteSheetOP_png, 31, 70, &rect);
	}
		return update_status::UPDATE_CONTINUE;
}