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
#include "Animation.h"
#include "SDL/include/SDL.h"

ModuleGameOver::ModuleGameOver(bool startEnabled) : Module(startEnabled)
{
	AnimLetters.PushBack({ 0,1073, 45, 46 }); //G
	AnimLetters.PushBack({ 48,1073, 45, 46 }); //A
	AnimLetters.PushBack({ 96,1073, 45, 46 });  //M
	AnimLetters.PushBack({ 144,1073, 45, 46 }); //E
	AnimLetters.PushBack({ 192,1073, 45, 46 });//O
	AnimLetters.PushBack({ 240,1073, 45, 46 });//V
	AnimLetters.PushBack({ 288,1073, 45, 46 });//E
	AnimLetters.PushBack({ 336,1073, 45, 46 });//R
	AnimLetters.speed = 0.4f;

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
	letter = App->textures->Load("Assets/SpriteSheetOP.png");
	LettersAnimation = &AnimLetters;
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
	LetterAOnPos = false;
	return true;
}

update_status ModuleGameOver::Update()
{

	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart < 3000) {
		
	}
	else {
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 70);
		

		
	}
	LettersAnimation->Update();
	return update_status::UPDATE_CONTINUE;
	
}

// Update: draw background
update_status ModuleGameOver::PostUpdate()
{
	// Draw everything --------------------------------------


	App->render->Blit(gameover_png, 0, 0, NULL);
	SDL_Rect rect = LettersAnimation->GetCurrentFrame();
	App->render->Blit(letter, 19, 10, &rect);
	return update_status::UPDATE_CONTINUE;
}