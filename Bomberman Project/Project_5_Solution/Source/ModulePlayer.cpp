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
	p[0].col = rand() % 4;
	p[0].position.x = 73;
	p[0].position.y = 32;
	p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

	p[1].col = rand() % 4;
	p[1].position.x = 89;
	p[1].position.y = 32;
	p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

	p[2].col = rand() % 4;
	p[2].position.x = 73;
	p[2].position.y = 48;
	p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

	p[3].col = rand() % 4;
	p[3].position.x = 89;
	p[3].position.y = 48;
	p[3].downAnim.PushBack({ 0, p[3].col * 16, 16,16 });

	air = rand() % 4;
	p[air].downAnim.PushBack({ 0, 80, 16,16 });
	p[air].col = 5;

	for (int i = 0; i < 4; i++)
	{
		switch (p[i].col)
		{
			case 0:
				p[i].color = 'N';
				break;
			case 1:
				p[i].color = 'A';
				break;
			case 2:
				p[i].color = 'B';
				break;
			case 3:
				p[i].color = 'R';
				break;
			case 4:
				p[i].color = 'V';
				break;
			case 5:
				p[i].color = ' ';
				break;
		}
	}
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
	if (p[0].active && p[1].active && p[2].active && p[3].active)
	{
		p[0].currentAnimation = &p[0].downAnim;
		p[1].currentAnimation = &p[1].downAnim;
		p[2].currentAnimation = &p[2].downAnim;
		p[3].currentAnimation = &p[3].downAnim;

		if (p[0].position.y < 208 && p[1].position.y < 208 && p[2].position.y < 208 && p[3].position.y < 208)
		{
			p[0].position.y += p->speed;
			p[1].position.y += p->speed;
			p[2].position.y += p->speed;
			p[3].position.y += p->speed;
		}
		

		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && p[0].position.x > 40 && p[1].position.x > 40 && p[2].position.x > 40 && p[3].position.x > 40)
		{
			p[0].position.x -= 16;
			p[1].position.x -= 16;
			p[2].position.x -= 16;
			p[3].position.x -= 16;
		}
		else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && p[0].position.x < 128 && p[1].position.x < 128 && p[2].position.x < 128 && p[3].position.x < 128)
		{
			p[0].position.x += 16;
			p[1].position.x += 16;
			p[2].position.x += 16;
			p[3].position.x += 16;
		}
		else if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && p[0].position.y < 208 && p[1].position.y < 208 && p[2].position.y < 208 && p[3].position.y < 208)
		{
			p[0].position.y += p->speed;
			p[1].position.y += p->speed;
			p[2].position.y += p->speed;
			p[3].position.y += p->speed;
		}
		else if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			p[0].position.y -= 2;
			p[1].position.y -= 2;
			p[2].position.y -= 2;
			p[3].position.y -= 2;
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
	SDL_Rect rect = p[0].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[0].position.x, p[0].position.y - rect.h, &rect);
	rect = p[1].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[1].position.x, p[1].position.y - rect.h, &rect);
	rect = p[2].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[2].position.x, p[2].position.y - rect.h, &rect);
	rect = p[3].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[3].position.x, p[3].position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}
