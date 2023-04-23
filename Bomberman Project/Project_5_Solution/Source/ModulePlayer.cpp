#include "ModulePlayer.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	p->position.x = 73;
	p->position.y = 32;
	p->downAnim.PushBack({ 0, rand() % 4 * 16, 16,16 });

	p[1]->position.x = 73;
	p[1]->position.y = 32;
	p[1]->downAnim.PushBack({ 0, rand() % 4 * 16, 16,16 });
}


ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/SpriteSheetPuyos.png"); // arcade version


	return ret;
}

update_status ModulePlayer::Update()
{
	if (p->active) 
	{
		p->currentAnimation = &p->downAnim;

		if (p->position.y < 208)
		{
			p->position.y += p->speed;
		}
		

		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && p->position.x > 40)
		{
			p->position.x -= 16;
		}
		else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && p->position.x < 128)
		{
			p->position.x += 16;
		}
		else if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && p->position.y < 208)
		{
			p->position.y += p->speed;
		}
	}

	else
	{
		return update_status::UPDATE_CONTINUE;
	}
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = p->currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p->position.x, p->position.y - rect.h, &rect);
	//rect = Group[1].currentAnimation->GetCurrentFrame();
	//App->render->Blit(texture, Group[1].position.x, Group[1].position.y - rect.h, &rect);
	//rect = Group[2].currentAnimation->GetCurrentFrame();
	//App->render->Blit(texture, Group[2].position.x, Group[2].position.x - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}
