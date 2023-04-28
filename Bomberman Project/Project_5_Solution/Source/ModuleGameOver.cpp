#include "ModuleGameOver.h"
#include "ModuleInput.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"
#include "ModulePlayer.h"

ModuleGameOver::ModuleGameOver() : isGameOverOpen(false)
{

}

ModuleGameOver::~ModuleGameOver()
{

}

update_status ModuleGameOver::Update()
{
	if (App->scene->ReadTile(4,0)==false || App->scene->ReadTile(3, 0) == false)
	{
		gameover_png = App->textures->Load("Assets/Game_over.png");
		App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleGameOver::PostUpdate()
{
	// Draw everything --------------------------------------

	App->render->Blit(gameover_png, 0, 0, 0, 10);

	return update_status::UPDATE_CONTINUE;
}