#include "ModulePlayer.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleScene.h"
#include "SDL/include/SDL.h"
#include "ModuleMenu.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer(int x, int y)
{
	air = rand() % 4;

	switch (air)
	{
	case 0:
		p[0].col = rand() % 4 + verde;
		p[0].position.x = 73;
		p[0].position.y = 32;
		p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

		p[1].col = rand() % 4 + verde;
		p[1].position.x = 89;
		p[1].position.y = 32;
		p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

		p[2].col = rand() % 4 + verde;
		p[2].position.x = 73;
		p[2].position.y = 48;
		p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

		break;
	case 1:
		p[0].col = rand() % 4 + verde;
		p[0].position.x = 73;
		p[0].position.y = 32;
		p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

		p[1].col = rand() % 4 + verde;
		p[1].position.x = 89;
		p[1].position.y = 32;
		p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

		p[2].col = rand() % 4 + verde;
		p[2].position.x = 89;
		p[2].position.y = 48;
		p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

		break;
	case 2:
		p[0].col = rand() % 4 + verde;
		p[0].position.x = 73;
		p[0].position.y = 32;
		p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

		p[1].col = rand() % 4 + verde;
		p[1].position.x = 73;
		p[1].position.y = 48;
		p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

		p[2].col = rand() % 4 + verde;
		p[2].position.x = 89;
		p[2].position.y = 48;
		p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

		break;
	case 3:
		p[0].col = rand() % 4 + verde;
		p[0].position.x = 89;
		p[0].position.y = 32;
		p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

		p[1].col = rand() % 4 + verde;
		p[1].position.x = 73;
		p[1].position.y = 48;
		p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

		p[2].col = rand() % 4 + verde;
		p[2].position.x = 89;
		p[2].position.y = 48;
		p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

		break;
	}

	for (int i = 0; i < 3; i++)
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
		}
	}
	p[0].currentAnimation = &p[0].downAnim;
	p[1].currentAnimation = &p[1].downAnim;
	p[2].currentAnimation = &p[2].downAnim;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;



	return ret;
}

update_status ModulePlayer::Update()
{
	if (App->menu->isMenuOpen == false) {

		if (p[0].position.y == 208 || App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 48) / 16) != true || p[0].active != true) {
			p[0].active = false;
			ModulePlayer::Activation();
		}

		if (p[1].position.y == 208 || App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 48) / 16) != true || p[1].active != true) {
			p[1].active = false;
			ModulePlayer::Activation();
		}

		if (p[2].position.y == 208 || App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 48) / 16) != true || p[2].active != true) {
			p[2].active = false;
			ModulePlayer::Activation();
		}


		if (p[0].position.y < 208 && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 48) / 16) == true && p[0].active == true)
		{
			p[0].position.y += speed;
		}

		if (p[1].position.y < 208 && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 48) / 16) == true && p[1].active == true)
		{
			p[1].position.y += speed;
		}

		if (p[2].position.y < 208 && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 48) / 16) == true && p[2].active == true)
		{
			p[2].position.y += speed;
		}

		int minX = 1000;
		int maxX = 0;
		int minY = 1000;
		int maxY = 0;

		for (int i = 0; i < 3; i++)
		{
			if (p[i].position.x > maxX)
			{
				maxX = p[i].position.x;
			}

			if (p[i].position.x < minX)
			{
				minX = p[i].position.x;
			}

			if (p[i].position.y > maxY)
			{
				maxY = p[i].position.y;
			}

			if (p[i].position.y < minY)
			{
				minY = p[i].position.y;
			}
		}

		if (p[0].active == true && p[1].active == true && p[2].active == true)
		{
			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && App->scene->isLeftEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isLeftEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isLeftEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				p[0].position.x -= 16;
				p[1].position.x -= 16;
				p[2].position.x -= 16;
			}
			else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && App->scene->isRightEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isRightEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isRightEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				p[0].position.x += 16;
				p[1].position.x += 16;
				p[2].position.x += 16;
			}
			else if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				p[0].position.y += speed;
				p[1].position.y += speed;
				p[2].position.y += speed;
			}
			else if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				for (int i = 0; i < 3; i++)
				{
					if (p[i].position.x == minX)
					{
						if (p[i].position.y == maxY)
						{
							p[i].position.y -= 16;
						}

						else
						{
							p[i].position.x += 16;
						}
					}

					else
					{
						if (p[i].position.y == minY)
						{
							p[i].position.y += 16;
						}

						else
						{
							p[i].position.x -= 16;
						}

					}
				}
			}

		}


		else
		{
			if (p[0].active == false && p[1].active == false && p[2].active == false) {
				App->scene->SetTile((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16, p[0].color);
				App->scene->SetTile((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16, p[1].color);
				App->scene->SetTile((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16, p[2].color);
			}
			

			//Eliminar lineas
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (p[0].currentAnimation != nullptr)
	{
		SDL_Rect rect = p[0].currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, p[0].position.x, p[0].position.y - rect.h, &rect);
		rect = p[1].currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, p[1].position.x, p[1].position.y - rect.h, &rect);
		rect = p[2].currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, p[2].position.x, p[2].position.y - rect.h, &rect);
	}
	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::Activation() {

	if (p[0].active == false)
	{
		if (p[0].position.x == p[1].position.x)
		{
			p[1].active = false;
		}

		if (p[0].position.x == p[2].position.x)
		{
			p[2].active = false;
		}
	}

	if (p[1].active == false)
	{
		if (p[1].position.x == p[0].position.x)
		{
			p[0].active = false;
		}

		if (p[1].position.x == p[2].position.x)
		{
			p[2].active = false;
		}
	}

	if (p[2].active == false)
	{
		if (p[2].position.x == p[1].position.x)
		{
			p[1].active = false;
		}

		if (p[2].position.x == p[0].position.x)
		{
			p[0].active = false;
		}
	}
}