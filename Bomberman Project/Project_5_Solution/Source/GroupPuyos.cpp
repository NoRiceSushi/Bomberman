#include "ModulePlayer.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "GroupPuyos.h"

#include "SDL/include/SDL.h"
#include "SDL/include/SDL_scancode.h"

using namespace std;

GroupPuyos::GroupPuyos()	{



}

void GroupPuyos::UpdateGroup() {
	for (Puyo p: Group)
	{
		if (active)
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
				position.y += App->player->speed;
			}
		}
		
		else
		{
			p.UpdatePuyo();
		}
	}
}

