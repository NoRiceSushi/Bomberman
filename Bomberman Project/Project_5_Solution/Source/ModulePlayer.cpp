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
int bomba2 = 0;
int verde = 0;
bool win = false;
float contadorW = 0;
int PrimerGiro = 1;
int girar;

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	srand(time(0));
	air = rand() % 4;

	//black puyo idle anim
	p->BlackidleAnim.PushBack({0,0,16,16});
	p->BlackidleAnim.PushBack({ 16,0,16,16 });
	p->BlackidleAnim.PushBack({ 32,0,16,16 });
	p->BlackidleAnim.PushBack({ 48,0,16,16 });
	p->BlackidleAnim.PushBack({ 64,0,16,16 });
	p->BlackidleAnim.PushBack({ 80,0,16,16 });
	p->BlackidleAnim.PushBack({ 96,0,16,16 });
	p->BlackidleAnim.PushBack({ 112,0,16,16 });
	p->BlackidleAnim.PushBack({ 128,0,16,16 });
	p->BlackidleAnim.PushBack({ 144,0,16,16 });
	p->BlackidleAnim.PushBack({ 160,0,16,16 });
	p->BlackidleAnim.PushBack({ 176,0,16,16 });
	p->BlackidleAnim.PushBack({ 0,0,16,16 });
	p->BlackidleAnim.speed = 0.1;
	p->BlackidleAnim.loop = false;

	//blue puyo idle anim
	p->BlueidleAnim.PushBack({ 0,16,16,16 });
	p->BlueidleAnim.PushBack({ 0,16,16,16 });
	p->BlueidleAnim.PushBack({ 16,16,16,16 });
	p->BlueidleAnim.PushBack({ 16,16,16,16 });
	p->BlueidleAnim.PushBack({ 32,16,16,16 });
	p->BlueidleAnim.PushBack({ 32,16,16,16 });
	p->BlueidleAnim.PushBack({ 0,16,16,16 });
	p->BlueidleAnim.speed = 0.1;
	p->BlueidleAnim.loop = false;

	//white puyo idle anim
	p->WhiteidleAnim.PushBack({ 0,32,16,16 });
	p->WhiteidleAnim.PushBack({ 16,32,16,16 });
	p->WhiteidleAnim.PushBack({ 32,32,16,16 });
	p->WhiteidleAnim.PushBack({ 48,32,16,16 });
	p->WhiteidleAnim.PushBack({ 64,32,16,16 });
	p->WhiteidleAnim.PushBack({ 80,32,16,16 });
	p->WhiteidleAnim.PushBack({ 96,32,16,16 });
	p->WhiteidleAnim.PushBack({ 112,32,16,16 });
	p->WhiteidleAnim.PushBack({ 128,32,16,16 });
	p->WhiteidleAnim.speed = 0.1;
	p->WhiteidleAnim.loop = false;

	//red puyo idle anim
	p->RedidleAnim.PushBack({ 0,48,16,16 });
	p->RedidleAnim.PushBack({ 16,48,16,16 });
	p->RedidleAnim.PushBack({ 32,48,16,16 });
	p->RedidleAnim.PushBack({ 48,48,16,16 });
	p->RedidleAnim.PushBack({ 64,48,16,16 });
	p->RedidleAnim.PushBack({ 80,48,16,16 });
	p->RedidleAnim.PushBack({ 96,48,16,16 });
	p->RedidleAnim.PushBack({ 112,48,16,16 });
	p->RedidleAnim.PushBack({ 0,48,16,16 });
	p->RedidleAnim.speed = 0.1;
	p->RedidleAnim.loop = false;

	//green puyo idle anim
	p->GreenidleAnim.PushBack({ 0,64,16,16 });
	p->GreenidleAnim.PushBack({ 16,64,16,16 });
	p->GreenidleAnim.PushBack({ 16,64,16,16 });
	p->GreenidleAnim.PushBack({ 16,64,16,16 });
	p->GreenidleAnim.PushBack({ 16,64,16,16 });
	p->GreenidleAnim.PushBack({ 0,64,16,16 });
	p->GreenidleAnim.speed = 0.1;
	p->GreenidleAnim.loop = false;


	//white puyo out anim
	p->WhiteOutAnim.PushBack({0,352,16,16});
	p->WhiteOutAnim.PushBack({ 16,352,16,16 });
	p->WhiteOutAnim.PushBack({ 32,352,16,16 });
	p->WhiteOutAnim.PushBack({ 48,352,16,16 });
	p->WhiteOutAnim.PushBack({ 64,352,16,16 });
	p->WhiteOutAnim.PushBack({ 80,352,16,16 });
	p->WhiteOutAnim.PushBack({ 96,352,16,16 });
	p->WhiteOutAnim.PushBack({ 112,352,16,16 });
	p->WhiteOutAnim.PushBack({ 128,352,16,16 });
	p->WhiteOutAnim.PushBack({ 144,352,16,16 });
	p->WhiteOutAnim.PushBack({ 160,352,16,16 });
	p->WhiteOutAnim.PushBack({ 176,352,16,16 });
	p->WhiteidleAnim.speed = 0.1;

	//red puyo out anim
	p->RedOutAnim.PushBack({ 0,368,16,16 });
	p->RedOutAnim.PushBack({ 16,368,16,16 });
	p->RedOutAnim.PushBack({ 32,368,16,16 });
	p->RedOutAnim.PushBack({ 48,368,16,16 });
	p->RedOutAnim.PushBack({ 64,368,16,16 });
	p->RedOutAnim.PushBack({ 80,368,16,16 });
	p->RedOutAnim.PushBack({ 96,368,16,16 });
	p->RedOutAnim.PushBack({ 112,368,16,16 });
	p->RedOutAnim.PushBack({ 128,368,16,16 });
	p->RedOutAnim.PushBack({ 144,368,16,16 });
	p->RedOutAnim.PushBack({ 160,368,16,16 });
	p->RedOutAnim.PushBack({ 176,368,16,16 });
	p->RedOutAnim.speed = 0.1;

	//blue puyo out anim
	p->BlueOutAnim.PushBack({ 0,383,16,16 });
	p->BlueOutAnim.PushBack({ 16,383,16,16 });
	p->BlueOutAnim.PushBack({ 32,383,16,16 });
	p->BlueOutAnim.PushBack({ 48,383,16,16 });
	p->BlueOutAnim.PushBack({ 64,383,16,16 });
	p->BlueOutAnim.PushBack({ 80,383,16,16 });
	p->BlueOutAnim.PushBack({ 96,383,16,16 });
	p->BlueOutAnim.PushBack({ 112,383,16,16 });
	p->BlueOutAnim.PushBack({ 128,383,16,16 });
	p->BlueOutAnim.PushBack({ 144,383,16,16 });
	p->BlueOutAnim.PushBack({ 160,383,16,16 });
	p->BlueOutAnim.PushBack({ 176,383,16,16 });
	p->BlueOutAnim.speed = 0.1;

	//black puyo out anim
	p->BlackOutAnim.PushBack({ 0,398,16,16 });
	p->BlackOutAnim.PushBack({ 16,398,16,16 });
	p->BlackOutAnim.PushBack({ 32,398,16,16 });
	p->BlackOutAnim.PushBack({ 48,398,16,16 });
	p->BlackOutAnim.PushBack({ 64,398,16,16 });
	p->BlackOutAnim.PushBack({ 80,398,16,16 });
	p->BlackOutAnim.PushBack({ 96,398,16,16 });
	p->BlackOutAnim.PushBack({ 112,398,16,16 });
	p->BlackOutAnim.PushBack({ 128,398,16,16 });
	p->BlackOutAnim.PushBack({ 144,398,16,16 });
	p->BlackOutAnim.PushBack({ 160,398,16,16 });
	p->BlackOutAnim.PushBack({ 176,398,16,16 });
	p->BlackOutAnim.speed = 0.1;

	//green puyo out anim
	p->GreenOutAnim.PushBack({ 0,413,16,16 });
	p->GreenOutAnim.PushBack({ 16,413,16,16 });
	p->GreenOutAnim.PushBack({ 32,413,16,16 });
	p->GreenOutAnim.PushBack({ 48,413,16,16 });
	p->GreenOutAnim.PushBack({ 64,413,16,16 });
	p->GreenOutAnim.PushBack({ 80,413,16,16 });
	p->GreenOutAnim.PushBack({ 96,413,16,16 });
	p->GreenOutAnim.PushBack({ 112,413,16,16 });
	p->GreenOutAnim.PushBack({ 128,413,16,16 });
	p->GreenOutAnim.PushBack({ 144,413,16,16 });
	p->GreenOutAnim.PushBack({ 160,413,16,16 });
	p->GreenOutAnim.PushBack({ 176,413,16,16 });
	p->GreenOutAnim.speed = 0.1;

	//Bomb explosion animation
	p->bomb2.PushBack({ 487,1122,79,79 });
	p->bomb2.PushBack({ 406,1122,79,79 });
	p->bomb2.PushBack({ 325,1122,79,79 });
	p->bomb2.PushBack({ 406,1122,79,79 });
	p->bomb2.PushBack({ 244,1122,79,79 });
	p->bomb2.PushBack({ 163,1122,79,79 });
	p->bomb2.PushBack({ 82,1122,79,79 });
	p->bomb2.PushBack({ 1,1122,79,79 });
	p->bomb2.loop = true;
	p->bomb2.speed = 0.2;

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
		else if (bomba2 == 8)
		{
			bomba2 = 0;

			p[0].position.x = 73;
			p[0].position.y = 32;
			p[0].downAnim.PushBack({ 128, 86, 28,25 });

			p[0].color = 'Z';

			p[1].position.x = 73;
			p[1].position.y = 32;
			p[1].downAnim.PushBack({ 128, 86, 28,25 });

			p[1].color = 'Z';

			p[2].position.x = 73;
			p[2].position.y = 32;
			p[2].downAnim.PushBack({ 128, 86, 28,25 });

			p[2].color = 'Z';

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
	bool ret = true;

	bgBorders = App->textures->Load("Assets/SpriteSheetOP.png");
	sfx_down = App->audio->LoadFx("Assets/sfx/sfx_down.wav");
	sfx_combo = App->audio->LoadFx("Assets/sfx/sfx_combo.wav");

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
			if ((girar == 1 && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true) || App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_A] != KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_D] != KEY_STATE::KEY_DOWN && App->scene->isDownEmpty((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16) == true && App->scene->isDownEmpty((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16) == true && p[0].color != 'X' && p[0].color != 'Z' && p[0].position.y<100)
			{
				if (girar == 0) {
					
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
			if (p[0].active == false && p[1].active == false && p[2].active == false && App->players->contador > 1) {

				App->scene->SetTile((p[0].position.x - 25) / 16, (p[0].position.y - 32) / 16, p[0].color);
				App->scene->SetTile((p[1].position.x - 25) / 16, (p[1].position.y - 32) / 16, p[1].color);
				App->scene->SetTile((p[2].position.x - 25) / 16, (p[2].position.y - 32) / 16, p[2].color);

				if (App->scene->ReadTile(3, 2) == false || App->scene->ReadTile(4, 2) == false) {
					win = true;
					App->fade->EnableOnly(this, (Module*)App->lose);
				}

				if (PrimerGiro == 1)
				{
					PrimerGiro = 2;
				}
			}
				p->BlackidleAnim.Update();
				p->WhiteidleAnim.Update();
				p->GreenidleAnim.Update();
				p->RedidleAnim.Update();
				p->BlueidleAnim.Update();
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
	bomba2++;
}