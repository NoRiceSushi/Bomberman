#include "ModuleGameOver.h"
#include "ModuleInput.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"
#include "ModulePlayer.h"
#include "ModuleFade.h"

ModuleGameOver::ModuleGameOver(bool startEnabled) : Module(startEnabled)
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
	AnimLose.speed = 0.8f;
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
	SpriteSheetOP_png = App->textures->Load("Assets/SpriteSheetOP.png");
	currentAnimation = &AnimLose;
	return true;
}

update_status ModuleGameOver::Update()
{
	/*if (App->input->keys[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 40);
	}*/
	//if (App->scene->ReadTile(4, 0) == false || App->scene->ReadTile(5, 0) == false)
	//{
	//	gameover_png = App->textures->Load("Assets/Game_over.png");
	//	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	//	/*App->fade->FadeToBlack(this, (Module*)App->gameover, 90);*/
	//}
	// ok
	// 
	//if (App->input->keys[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	//{

	//	App->fade->FadeToBlack(this, (Module*)App->gameover, 40);
	//	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	//	App->render->Blit(SpriteSheetOP_png, 19, 10, &rect);
	//}
	currentAnimation->Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleGameOver::PostUpdate()
{
	// Draw everything --------------------------------------
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(SpriteSheetOP_png, 19, 10, &rect);
	App->render->Blit(gameover_png, 0, 0, 0, 0);
	return update_status::UPDATE_CONTINUE;
}