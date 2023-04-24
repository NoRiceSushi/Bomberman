#include "ModulePlayer.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleScene.h"
#include "SDL/include/SDL.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	air = rand() % 4;

	switch (air)
	{
	case 0:
		p[0][0].col = rand() % 4;
		p[0][0].position.x = 73;
		p[0][0].position.y = 32;
		p[0][0].downAnim.PushBack({ 0, p[0][0].col * 16, 16,16 });

		p[1][0].col = rand() % 4;
		p[1][0].position.x = 89;
		p[1][0].position.y = 32;
		p[1][0].downAnim.PushBack({ 0, p[1][0].col * 16, 16,16 });

		p[0][1].col = rand() % 4;
		p[0][1].position.x = 73;
		p[0][1].position.y = 48;
		p[0][1].downAnim.PushBack({ 0, p[0][1].col * 16, 16,16 });

		break;
	case 1:
		p[0][0].col = rand() % 4;
		p[0][0].position.x = 73;
		p[0][0].position.y = 32;
		p[0][0].downAnim.PushBack({ 0, p[0][0].col * 16, 16,16 });

		p[1][0].col = rand() % 4;
		p[1][0].position.x = 89;
		p[1][0].position.y = 32;
		p[1][0].downAnim.PushBack({ 0, p[1][0].col * 16, 16,16 });

		p[1][1].col = rand() % 4;
		p[1][1].position.x = 89;
		p[1][1].position.y = 48;
		p[1][1].downAnim.PushBack({ 0, p[1][1].col * 16, 16,16 });

		break;
	case 2:
		p[0][0].col = rand() % 4;
		p[0][0].position.x = 73;
		p[0][0].position.y = 32;
		p[0][0].downAnim.PushBack({ 0, p[0][0].col * 16, 16,16 });

		p[0][1].col = rand() % 4;
		p[0][1].position.x = 73;
		p[0][1].position.y = 48;
		p[0][1].downAnim.PushBack({ 0, p[0][1].col * 16, 16,16 });

		p[1][1].col = rand() % 4;
		p[1][1].position.x = 89;
		p[1][1].position.y = 48;
		p[1][1].downAnim.PushBack({ 0, p[1][1].col * 16, 16,16 });

		break;
	case 3:
		p[1][0].col = rand() % 4;
		p[1][0].position.x = 89;
		p[1][0].position.y = 32;
		p[1][0].downAnim.PushBack({ 0, p[1][0].col * 16, 16,16 });

		p[0][1].col = rand() % 4;
		p[0][1].position.x = 73;
		p[0][1].position.y = 48;
		p[0][1].downAnim.PushBack({ 0, p[0][1].col * 16, 16,16 });

		p[1][1].col = rand() % 4;
		p[1][1].position.x = 89;
		p[1][1].position.y = 48;
		p[1][1].downAnim.PushBack({ 0, p[1][1].col * 16, 16,16 });

		break;
	}

	for (int j = 0; j < 2; j++)
	{ 
		for (int i = 0; i < 2; i++)
		{
			switch (p[i][j].col)
			{
				case 0:
					p[i][j].color = 'N';
					break;
				case 1:
					p[i][j].color = 'A';
					break;
				case 2:
					p[i][j].color = 'B';
					break;
				case 3:
					p[i][j].color = 'R';
					break;
				case 4:
					p[i][j].color = 'V';
					break;
			}
		}	
<<<<<<< Updated upstream
=======
	}
	
	if (p[0][0].color != '0') {
		ModuleScene::field[4][0]= p[0][0].color; }
	if (p[1][0].color != '0') {
		ModuleScene::field[5][0] = p[1][0].color;
	}
	if (p[0][1].color != '0') {
		ModuleScene::field[4][1] = p[0][1].color;
	}
	if (p[1][1].color != '0') {
		ModuleScene::field[5][1] = p[1][1].color;
>>>>>>> Stashed changes
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
	if (p[0][0].active && p[1][0].active && p[0][1].active && p[1][1].active)
	{
		p[0][0].currentAnimation = &p[0][0].downAnim;
		p[1][0].currentAnimation = &p[1][0].downAnim;
		p[0][1].currentAnimation = &p[0][1].downAnim;
		p[1][1].currentAnimation = &p[1][1].downAnim;

		if (p[0][0].position.y < 208 && p[1][1].position.y < 208 && p[0][1].position.y < 208 && p[1][1].position.y < 208)
		{
			p[0][0].position.y += speed;
			p[1][0].position.y += speed;
			p[0][1].position.y += speed;
			p[1][1].position.y += speed;
		}
		

		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && p[0][0].position.x > 40 && p[1][0].position.x > 40 && p[0][1].position.x > 40 && p[1][1].position.x > 40)
		{
			p[0][0].position.x -= 16;
			p[1][0].position.x -= 16;
			p[0][1].position.x -= 16;
			p[1][1].position.x -= 16;
		}
		else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && p[0][0].position.x < 128 && p[1][0].position.x < 128 && p[0][1].position.x < 128 && p[1][1].position.x < 128)
		{
			p[0][0].position.x += 16;
			p[1][0].position.x += 16;
			p[0][1].position.x += 16;
			p[1][1].position.x += 16;
		}
		else if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && p[0][0].position.y < 208 && p[1][0].position.y < 208 && p[0][1].position.y < 208 && p[1][1].position.y < 208)
		{
			p[0][0].position.y += speed;
			p[1][0].position.y += speed;
			p[0][1].position.y += speed;
			p[1][1].position.y += speed;
		}
		else if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			p[0][0].position.y -= 2;
			p[1][0].position.y -= 2;
			p[0][1].position.y -= 2;
			p[1][1].position.y -= 2;
		}
	}

	else
	{
		//ModuleScene::SetTile((p[0][0].position.y-25)/16,posicion en y. p[0].color)
	}
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = p[0][0].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[0][0].position.x, p[0][0].position.y - rect.h, &rect);
	rect = p[1][0].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[1][0].position.x, p[1][0].position.y - rect.h, &rect);
	rect = p[0][1].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[0][1].position.x, p[0][1].position.y - rect.h, &rect);
	rect = p[1][1].currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, p[1][1].position.x, p[1][1].position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}
