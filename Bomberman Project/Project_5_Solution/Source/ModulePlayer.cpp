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
<<<<<<< HEAD
	position[0+ ACT_PUYOS].x = 48+25 ;
	position[0+ ACT_PUYOS].y = 32;
=======
>>>>>>> 238b7137b4d56b899e5ea25f531954e287ea7f26

	Group[0] = new Puyo();

	//Group[0].position.x = 48 + 25;
	//Group[0].position.y = 32;

	/*Group[1].position.x = 64 + 25;
	Group[1].position.y = 32;

	Group[2].position.x = 64 + 25;
	Group[2].position.y = 48;

	Group[3].position.x = 48 + 25;
	Group[3].position.y = 48;*/
}


ModulePlayer::~ModulePlayer()
{

}

update_status ModulePlayer::Update()
{
	for (Puyo* p : Group)
	{
		if (active) //Todo el modulo del jugador, no el grupo
		{
			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && position.x > 40)
			{
				position.x -= 16;
			}
			else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && position.x < 128)
			{
				position.x += 16;
			}
			else if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < 208)
			{
				position.y += speed;
			}
		}

		else
		{
			p->UpdatePuyo();
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = Group[0]->currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, Group[0]->position.x, Group[0]->position.y - rect.h, &rect);
	//rect = Group[1].currentAnimation->GetCurrentFrame();
	//App->render->Blit(texture, Group[1].position.x, Group[1].position.y - rect.h, &rect);
	//rect = Group[2].currentAnimation->GetCurrentFrame();
	//App->render->Blit(texture, Group[2].position.x, Group[2].position.x - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}
