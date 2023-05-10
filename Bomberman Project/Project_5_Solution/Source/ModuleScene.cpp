#include "ModuleScene.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFade.h"
#include "ModuleInput.h"
#include "ModuleGameOver.h"
#include "SDL/include/SDL_scancode.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
#include "Animation.h"

#include<iostream>


using namespace std;
/*{	-,-,-,X,X,-,-,-
	-,-,-,X,X,-,-,-
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0 }
*/
ModuleScene::ModuleScene(bool startEnabled) : Module(startEnabled)
{

	AnimBorders.PushBack({ 351, 2, 141, 204 });
	AnimBorders.PushBack({ 350, 208, 141, 204 });
	AnimBorders.PushBack({ 350, 414 , 141, 204 });
	AnimBorders.PushBack({ 350, 620, 141, 204 });
	AnimBorders.PushBack({ 48, 787, 141, 204 });
	AnimBorders.PushBack({ 48, 580, 141, 204 });
	AnimBorders.PushBack({ 206, 413, 141, 204 });
	AnimBorders.PushBack({ 206, 620, 141, 204 });
	AnimBorders.PushBack({ 206,826 , 141, 204 });
	AnimBorders.PushBack({ 350, 826, 141, 204 });
	AnimBorders.PushBack({ 350, 826, 141, 204 });
	AnimBorders.PushBack({ 350, 826, 141, 204 });
	AnimBorders.PushBack({ 206, 826, 141, 204 });
	AnimBorders.PushBack({ 206, 620, 141, 204 });
	AnimBorders.PushBack({ 206, 413, 141, 204 });
	AnimBorders.PushBack({ 48, 580, 141, 204 });
	AnimBorders.PushBack({ 48, 787, 141, 204 });
	AnimBorders.PushBack({ 350, 620, 141, 204 });
	AnimBorders.PushBack({ 350, 414 , 141, 204 });
	AnimBorders.PushBack({ 350, 208, 141, 204 });
	AnimBorders.PushBack({ 351, 2, 141, 204 });
	AnimBorders.PushBack({ 351, 2, 141, 204 });
	AnimBorders.PushBack({ 351, 2, 141, 204 });
	AnimBorders.speed = 0.2f;


	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = '0';
		}
	}
}

ModuleScene::~ModuleScene()
{

}

bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
	bgTexture2 = App->textures->Load("Assets/FondoIzquierdaLimpio.png");
	bgBorders = App->textures->Load("Assets/SpriteSheetOP.png");
	currentAnimation = &AnimBorders;
	App->audio->PlayMusic("Assets/audio/08_stage_1.ogg", 1.0f);
	App->fade->EnableOnly(this, (Module*)App->score);
	App->fade->EnableOnly(this, (Module*)App->player);
	App->fade->EnableOnly(this, (Module*)App->players);
	App->fade->EnableOnly(this, (Module*)App->Bombazo);

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = '0';
		}
	}

	return ret;

}

update_status ModuleScene::Update()
{
	if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		App->fade->EnableOnly(this, (Module*)App->lose);
	}
	if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->fade->EnableOnly(this, (Module*)App->win);
	}

	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				map[i][j] = '0';
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 8; j++) {
			cout << "[" << map[i][j] << "] ";
		}
		cout << endl;
	}
	cout << endl; cout << endl; cout << endl; cout << endl;

	/*currentAnimation = &AnimBorders;*/


	currentAnimation->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	/*for (int i = 0; i < 8; i++) {
		if (App->scene->ReadTile(i, 5) == false) {
			App->audio->PlayMusic("Assets/audio/23_Danger.ogg", 1.0f);

		}
	}*/
	App->render->Blit(bgTexture, -231, 0, 0, 10);
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(bgBorders, 19, 10, &rect);

	App->render->Blit(bgTexture2, 0, 0, 0, 10);

	return update_status::UPDATE_CONTINUE;
}

void ModuleScene::SetTile(int x, int y, char value)
{
	map[y][x] = value;
}

bool ModuleScene::ReadTile(int x, int y) {
	if (map[y][x] == '0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ModuleScene::isLeftEmpty(int x, int y)
{
	if (map[y + 1][x - 1] == '0' && x > 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool ModuleScene::isRightEmpty(int x, int y)
{
	if (map[y + 1][x + 1] == '0' && x < 7)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool ModuleScene::isDownEmpty(int x, int y)
{
	if (map[y + 2][x] == '0' && y < 10)
	{
		return true;
	}

	else
	{
		return false;
	}
}


void ModuleScene::DestroyLines() {
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (map[i][j] == '0')
				{
				}

				else if (map[i][j] == 'A')
				{
					if (map[i][j + 1] == 'A')
					{
						if (map[i][j + 2] == 'A')
						{
							map[i][j] = '0';
							map[i][j + 1] = '0';
							map[i][j + 2] = '0';
						}
						if (map[i][j - 1] == 'A')
						{
							map[i][j] = '0';
							map[i][j + 1] = '0';
							map[i][j - 1] = '0';

							if (map[i][j - 2] == 'A')
							{
								map[i][j - 2] = '0';
							}
						}
					}

					else if (map[i][j - 1] == 'A')
					{
						if (map[i][j - 2] == 'A')
						{
							map[i][j] = '0';
							map[i][j - 1] = '0';
							map[i][j - 2] = '0';
						}
					}

					else if (map[i + 1][j] == 'A')
					{
						if (map[i + 2][j] == 'A')
						{
							Score += 100;
						}
						if (map[i - 1][j] == 'A')
						{
							Score += 100;

							if (map[i - 2][j] == 'A')
							{
								Score += 100;
							}
						}
					}

					else if (map[i - 1][j] == 'A')
					{
						if (map[i - 2][j] == 'A')
						{
							Score += 100;
						}
					}

					else if (map[i + 1][j + 1] == 'A')
					{
						if (map[i + 2][j + 2] == 'A')
						{
							Score += 100;
						}
						if (map[i - 1][j - 1] == 'A')
						{
							Score += 100;

							if (map[i - 2][j - 2] == 'A')
							{
								Score += 100;
							}
						}
					}

					else if (map[i - 1][j - 1] == 'A')
					{
						if (map[i - 2][j - 2] == 'A')
						{
							Score += 100;
						}
					}

					else if (map[i - 1][j + 1] == 'A')
					{
						if (map[i - 2][j + 2] == 'A')
						{
							map[i][j] = '0';
							map[i - 1][j + 1] == '0';
							map[i - 2][j + 2] = '0';
						}
						if (map[i + 1][j - 1] == 'A')
						{
							map[i][j] = '0';
							map[i - 1][j + 1] == '0';
							map[i + 1][j - 1] = '0';

							if (map[i - 2][j + 2] == 'A')
							{
								map[i - 2][j + 2] = '0';
							}
						}
					}

					else if (map[i + 1][j - 1] == 'A' && i < 7 && j < 11)
					{
						if (map[i + 2][j - 2] == 'A' && i < 6 && j < 11)
						{
							map[i][j] = '0';
							map[i + 1][j - 1] = '0';
							map[i + 2][j - 2] = '0';
						}
					}
				}
			}
		}
	}
}