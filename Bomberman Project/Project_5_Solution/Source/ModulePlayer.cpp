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
	position[0+ ACT_PUYOS].x = 48+25;
	position[0+ ACT_PUYOS].y = 32;

	position[1+ ACT_PUYOS].x = 64+25;
	position[1+ ACT_PUYOS].y = 32;
	
	position[2+ ACT_PUYOS].x = 64 + 25;
	position[2+ ACT_PUYOS].y = 48;

	// idle animation - just one sprite
	idleAnim.PushBack({ 0, 16, 16, 16 });
}


ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/SpriteSheetPuyos.png"); // arcade version
	currentAnimation = &idleAnim;

	return ret;
}

update_status ModulePlayer::Update()
{
	if (position[0].y<208 || (position[2].y==1	&&	position[0].x == position[1].x))										
	{
		App->player->position[0].y += 0.5;
	}
	if (position[1].y < 208 && !(position[1].x==position[0].x	&&	position[0].y>=207) && !(position[1].x == position[2].x && position[2].y >= 208))	
	{
		App->player->position[1].y += 0.5;
	}

	if (position[2].y < 208 || (position[0].y == 1 && position[2].x == position[1].x))									
	{
		App->player->position[2].y += 0.5;
	}


	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && position[0].x > 40 && position[1].x > 40 && position[2].x > 40 && !((position[1].x == position[0].x && position[1].y != position[2].y) || (position[1].x == position[2].x && position[1].y != position[0].y)))
	{
		position[0].x -= 16;
		position[1].x -= 16;
		position[2].x -= 16;
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && position[0].x < 128 && position[1].x < 128 && position[2].x < 128 && !((position[1].x==position[0].x && position[1].y!=position[2].y) || (position[1].x == position[2].x && position[1].y != position[0].y)))
	{
		position[0].x += 16;
		position[1].x += 16;
		position[2].x += 16;
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position[0].y < 208 && position[1].y < 207 && position[2].y < 208)
	{
		position[0].y += speed;
		position[1].y += speed;
		position[2].y += speed;
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position[0].y > 0)
	{
		position[0].y -= speed;
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position[1].y > 0)
	{
		position[1].y -= speed;
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position[2].y > 0)
	{
		position[2].y -= speed;
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, position[0].x, position[0].y - rect.h, &rect);
	App->render->Blit(texture, position[1].x, position[1].y - rect.h, &rect);
	App->render->Blit(texture, position[2].x, position[2].y - rect.h, &rect);


	ACT_PUYOS += 3;

	return update_status::UPDATE_CONTINUE;
}
