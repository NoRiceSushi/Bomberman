#include "ModulePlayer.h"
#include <time.h>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleScene.h"
#include "SDL/include/SDL.h"
#include "ModuleMenu.h"
#include "ModuleScore.h"
#include "ModuleAudio.h"
#include "ModuleFade.h"
#include "ModuleGameOver.h"
#include "Animation.h"
#include "SDL/include/SDL_scancode.h"
#include "ModuleBombazo.h"

//int bomba = 0;
//int verde = 0;
//bool win = false;
//float contadorW = 0;

ModuleBombazo::ModuleBombazo(bool startEnabled) : Module(startEnabled)
{





	position.x = 73;
	position.y = 32;
	downAnim.PushBack({ 128, 86, 28,25 });





	currentAnimation = &downAnim;






}

ModuleBombazo::~ModuleBombazo()
{

}

bool ModuleBombazo::Start()
{
	LOG("Loading bombazo textures");


	bool ret = true;



	return ret;
}

update_status ModuleBombazo::Update()
{


	{
		if (App->menu->isMenuOpen == false && App->score->coins != 0)
		{

			if (position.y == 208 || App->scene->isDownEmpty((position.x - 25) / 16, (position.y - 48) / 16) != true || active != true)
			{
				active = false;

			}
			if (position.y < 208 && App->scene->isDownEmpty((position.x - 25) / 16, (position.y - 48) / 16) == true && active == true)
			{
				position.y += speed;
			}

			if (active == true)
			{


				if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && App->scene->isLeftEmpty((position.x - 25) / 16, (position.y - 32) / 16) == true)
				{
					position.x -= 16;

				}
				if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && App->scene->isRightEmpty((position.x - 25) / 16, (position.y - 32) / 16) == true)
				{
					position.x += 16;

				}
				if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->scene->isDownEmpty((position.x - 25) / 16, (position.y - 42) / 16) == true)
				{
					position.y += speed * 8;

					App->score->score++;
				}
				if (App->input->keys[SDL_SCANCODE_Q] == KEY_STATE::KEY_REPEAT)
				{

					position.y -= speed;

				}
			}
		}
	}




	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBombazo::PostUpdate()
{
	if (currentAnimation != nullptr)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y - rect.h, &rect);


	}
	return update_status::UPDATE_CONTINUE;
}


