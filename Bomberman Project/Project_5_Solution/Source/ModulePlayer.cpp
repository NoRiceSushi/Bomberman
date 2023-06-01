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
#include "ModulePlayers.h"
#include <iostream>

int bomba = 0;
int verde = 0;
bool win = false;
float contadorW = 0;
int PrimerGiro = 1;
int girar;

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	srand(time(0));
	air = rand() % 4;

	////black puyo idle anim
	//p->idleAnim.PushBack({0,0,16,16});
	//p->idleAnim.PushBack({ 16,0,16,16 });
	//p->idleAnim.PushBack({ 32,0,16,16 });
	//p->idleAnim.PushBack({ 48,0,16,16 });
	//p->idleAnim.PushBack({ 64,0,16,16 });
	//p->idleAnim.PushBack({ 80,0,16,16 });
	//p->idleAnim.PushBack({ 96,0,16,16 });
	//p->idleAnim.PushBack({ 112,0,16,16 });
	//p->idleAnim.PushBack({ 128,0,16,16 });
	//p->idleAnim.PushBack({ 144,0,16,16 });
	//p->idleAnim.PushBack({ 160,0,16,16 });
	//p->idleAnim.PushBack({ 176,0,16,16 });
	//p->idleAnim.PushBack({ 192,0,16,16 });
	//p->idleAnim.speed = 0.1;
	//p->idleAnim.loop = false;

	////blue puyo idle anim
	//p->idleAnim.PushBack({ 0,16,16,16 });
	//p->idleAnim.PushBack({ 16,16,16,16 });
	//p->idleAnim.PushBack({ 32,16,16,16 });
	//p->idleAnim.speed = 0.1;
	//p->idleAnim.loop = false;

	////white puyo idle anim
	//p->idleAnim.PushBack({ 0,32,16,16 });
	//p->idleAnim.PushBack({ 16,32,16,16 });
	//p->idleAnim.PushBack({ 32,32,16,16 });
	//p->idleAnim.PushBack({ 48,32,16,16 });
	//p->idleAnim.PushBack({ 64,32,16,16 });
	//p->idleAnim.PushBack({ 80,32,16,16 });
	//p->idleAnim.PushBack({ 96,32,16,16 });
	//p->idleAnim.PushBack({ 112,32,16,16 });
	//p->idleAnim.PushBack({ 128,32,16,16 });
	//p->idleAnim.speed = 0.1;
	//p->idleAnim.loop = false;

	////red puyo idle anim
	//p->idleAnim.PushBack({ 0,48,16,16 });
	//p->idleAnim.PushBack({ 16,48,16,16 });
	//p->idleAnim.PushBack({ 32,48,16,16 });
	//p->idleAnim.PushBack({ 48,48,16,16 });
	//p->idleAnim.PushBack({ 64,48,16,16 });
	//p->idleAnim.PushBack({ 80,48,16,16 });
	//p->idleAnim.PushBack({ 96,48,16,16 });
	//p->idleAnim.PushBack({ 112,48,16,16 });
	//p->idleAnim.PushBack({ 128,48,16,16 });
	//p->idleAnim.speed = 0.1;
	//p->idleAnim.loop = false;

	////green puyo idle anim
	//p->idleAnim.PushBack({ 0,64,16,16 });
	//p->idleAnim.PushBack({ 16,64,16,16 });
	//p->idleAnim.speed = 0.1;
	//p->idleAnim.loop = false;

	ModulePlayer::Bomb();

	if (bomba != 10)
	{



		if (bomba == 5)
		{
			bomba = 0;

			p[0].position.x = 73;
			p[0].position.y = 32;
			p[0].downAnim.PushBack({ 0, 6 * 16, 16,16 });

			p[0].color = 'X';

			p[1].position.x = 73;
			p[1].position.y = 32;
			p[1].downAnim.PushBack({ 0, 6 * 16, 16,16 });

			p[1].color = 'X';

			p[2].position.x = 73;
			p[2].position.y = 32;
			p[2].downAnim.PushBack({ 0, 6 * 16, 16,16 });

			p[2].color = 'X';

			p[0].currentAnimation = &p[0].downAnim;
			p[1].currentAnimation = &p[1].downAnim;
			p[2].currentAnimation = &p[2].downAnim;
		}

		else if (win==false)
		{

			switch (air)
			{
			case 0:
				p[0].col = rand() % 4 + verde;
				p[0].position.x = 73;
				p[0].position.y = 32;
				p[0].pos = 0;
				p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

				p[1].col = rand() % 4 + verde;
				p[1].position.x = 89;
				p[1].position.y = 32;
				p[1].pos = 1;
				p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

				p[2].col = rand() % 4 + verde;
				p[2].position.x = 73;
				p[2].position.y = 48;
				p[2].pos = 3;
				p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

				break;
			case 1:
				p[0].col = rand() % 4 + verde;
				p[0].position.x = 73;
				p[0].position.y = 32;
				p[0].pos = 0;
				p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

				p[1].col = rand() % 4 + verde;
				p[1].position.x = 89;
				p[1].position.y = 32;
				p[1].pos = 1;
				p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

				p[2].col = rand() % 4 + verde;
				p[2].position.x = 89;
				p[2].position.y = 48;
				p[2].pos = 2;
				p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

				break;
			case 2:
				p[0].col = rand() % 4 + verde;
				p[0].position.x = 73;
				p[0].position.y = 32;
				p[0].pos = 0;
				p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

				p[1].col = rand() % 4 + verde;
				p[1].position.x = 73;
				p[1].position.y = 48;
				p[1].pos = 3;
				p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

				p[2].col = rand() % 4 + verde;
				p[2].position.x = 89;
				p[2].position.y = 48;
				p[2].pos = 2;
				p[2].downAnim.PushBack({ 0, p[2].col * 16, 16,16 });

				break;
			case 3:
				p[0].col = rand() % 4 + verde;
				p[0].position.x = 89;
				p[0].position.y = 32;
				p[0].pos = 1;
				p[0].downAnim.PushBack({ 0, p[0].col * 16, 16,16 });

				p[1].col = rand() % 4 + verde;
				p[1].position.x = 73;
				p[1].position.y = 48;
				p[1].pos = 3;
				p[1].downAnim.PushBack({ 0, p[1].col * 16, 16,16 });

				p[2].col = rand() % 4 + verde;
				p[2].position.x = 89;
				p[2].position.y = 48;
				p[2].pos = 2;
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
		}
	}

	girar = 0;
	contadorW = 0;

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
	sfx_rotate = App->audio->LoadFx("Assets/sfx/sfx_rotation.wav");

	bool ret = true;



	return ret;
}

update_status ModulePlayer::Update()
{
	if (App->menu->isMenuOpen == false && App->score->coins != 0 && App->score->readyScreenEnd == true) {

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

		if (p[0].active == true && p[1].active == true && p[2].active == true)
		{
			if (verde == 0 && App->input->keys[SDL_SCANCODE_Y] == KEY_STATE::KEY_DOWN)
			{
				verde++;
			}

			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && App->scene->isLeftEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isLeftEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isLeftEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				p[0].position.x -= 16;
				p[1].position.x -= 16;
				p[2].position.x -= 16;
			}
			if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && App->scene->isRightEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isRightEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isRightEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true)
			{
				p[0].position.x += 16;
				p[1].position.x += 16;
				p[2].position.x += 16;
			}
			if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 42) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 42) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 42) / 16) == true)
			{
				p[0].position.y += speed * 8;
				p[1].position.y += speed * 8;
				p[2].position.y += speed * 8;
				App->score->score++;
			}
			if (App->input->keys[SDL_SCANCODE_Q] == KEY_STATE::KEY_REPEAT)
			{

				p[0].position.y -= speed;
				p[1].position.y -= speed;
				p[2].position.y -= speed;
			}
			if ((girar == 1 && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true) || App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_A] != KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_D] != KEY_STATE::KEY_DOWN && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true && p[0].color != 'X')
			{
				if (girar == 0) {
					App->audio->PlayFx(sfx_rotate);
					girar++;
				}
				else
				{
					contadorW += (0.5*PrimerGiro);

					if (p[0].pos == 0)
					{
						p[0].position.x += 1;
					}
					if (p[0].pos == 1)
					{
						p[0].position.y += 1;
					}
					if (p[0].pos == 2)
					{
						p[0].position.x -= 1;
					}
					if (p[0].pos == 3)
					{
						p[0].position.y -= 1;
					}



					if (p[1].pos == 0)
					{
						p[1].position.x += 1;
					}
					if (p[1].pos == 1)
					{
						p[1].position.y += 1;
					}
					if (p[1].pos == 2)
					{
						p[1].position.x -= 1;
					}
					if (p[1].pos == 3)
					{
						p[1].position.y -= 1;
					}

					if (p[2].pos == 0)
					{
						p[2].position.x += 1;
					}
					if (p[2].pos == 1)
					{
						p[2].position.y += 1;
					}
					if (p[2].pos == 2)
					{
						p[2].position.x -= 1;
					}
					if (p[2].pos == 3)
					{
						p[2].position.y -= 1;
					}
					if (contadorW >= 16)
					{
						girar = 0;
						contadorW = 0;
						for (int i = 0; i < 4; i++)
						{
							p[i].pos++;
							if (p[i].pos == 4)
							{
								p[i].pos = 0;
							}
						}
					}

				}


				if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
				{
					win = true;
				}
				if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
				{
					win = true;
				}
				if (App->input->keys[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN && verde == 0)
				{
					verde++;
				}
			}
		}
		
		else
			{
				if (p[0].active == false && p[1].active == false && p[2].active == false) {
					App->scene->SetTile((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16, p[0].color);
					App->scene->SetTile((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16, p[1].color);
					App->scene->SetTile((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16, p[2].color);
					
					if (App->scene->ReadTile(3, 2) == false || App->scene->ReadTile(4, 2) == false) {
						win = true;
						App->fade->EnableOnly(this, (Module*)App->lose);
					}

					if (PrimerGiro==1)
					{
						PrimerGiro = 2;
					}
				}
			}
	}
		return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	for (int i = 0; i < 3; ++i)
	{
		if (p[i].currentAnimation != nullptr)
		{
			SDL_Rect rect = p[i].currentAnimation->GetCurrentFrame();
			App->render->Blit(texture, p[i].position.x, p[i].position.y - rect.h, &rect);
		}
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

void ModulePlayer::Bomb() {
	bomba++;
}