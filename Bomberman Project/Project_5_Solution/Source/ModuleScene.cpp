#include "ModuleScene.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFade.h"
#include "ModulePlayer.h"
#include "ModulePlayers.h"
#include "ModuleInput.h"
#include "ModuleScore.h"
#include "SceneIntro.h"
#include "ModuleGameOver.h"
#include "SDL/include/SDL_scancode.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
#include "Animation.h"
#include "SDL/include/SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

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
//green anim border
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
	AnimBorders.loop = true;
	AnimBorders.speed = 0.4f;

	//yellow anim border
	AnimBordersy.PushBack({ 638, 2, 141, 204 });
	AnimBordersy.PushBack({ 494, 2, 141, 204 });
	AnimBordersy.PushBack({ 494, 208, 141, 204 });
	AnimBordersy.PushBack({ 494, 414 , 141, 204 });
	AnimBordersy.PushBack({ 494, 620, 141, 204 });
	AnimBordersy.PushBack({ 494, 826, 141, 204 });
	AnimBordersy.loop = true;
	AnimBordersy.speed = 0.3f;

	//red anim border
	AnimBordersr.PushBack({ 638, 2, 141, 204 });
	AnimBordersr.PushBack({ 638, 208, 141, 204 });
	AnimBordersr.PushBack({ 638, 414 , 141, 204 });
	AnimBordersr.PushBack({ 638, 620, 141, 204 });
	AnimBordersr.PushBack({ 638, 826, 141, 204 });
	AnimBordersr.PushBack({ 206, 208, 141, 204 });
	AnimBordersr.loop = true;
	AnimBordersr.speed = 0.5f;

	//level up
	Animlevelup.PushBack({ 102,517,57,46 });

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

void ModuleScene::PlayBackgroundMusic()
{
	App->audio->PlayMusic("Assets/audio/08_stage_1.ogg", 1.0f);
}

bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	App->sceneIntro->Disable();
	bgTexture = App->textures->Load("Assets/Sprite/background.png");
	bgTexture2 = App->textures->Load("Assets/Sprite/FondoIzquierdaLimpio.png");
	bgBorders = App->textures->Load("Assets/Sprite/SpriteSheetOP.png");
	currentAnimation = &AnimBorders;
	currentAnimY = &AnimBordersy;
	currentAnimR = &AnimBordersr;
	currentAnimLevel = &Animlevelup;
	
	App->audio->PlayMusico("Assets/audio/07_Ready.ogg", 1.0f);
	sfx_rotate = App->audio->LoadFx("Assets/sfx/sfx_rotation.wav");

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
	if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && !musicPlay) {
			PlayBackgroundMusic();
			musicPlay = true;
	}

	if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		App->fade->EnableOnly(this, (Module*)App->lose);
	}
	if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->fade->EnableOnly(this, (Module*)App->win);
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN)
	{
		App->audio->PlayFx(sfx_rotate);
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

	currentAnimR->Update();
	currentAnimY->Update();
	currentAnimLevel->Update();
	currentAnimation->Update();
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	/*if (score >= 50 && score <= 150)
	{
		App->render->Blit(bgTexture, -231, 0, 0, 10);
	}*/
	//App->render->Blit(bgTexture, -231, 0, 0, 10);
	rectG = currentAnimation->GetCurrentFrame();
	App->render->Blit(bgBorders, 19, 10, &rectG);
	bool playYellow = false;
	for (int i = 0; i < 8; i++) {
		if (App->scene->ReadTile(i, 6) == false) {
			playYellow = true;
			break;
		}
		else {
			playYellow = false;
		}
	}
	if (playYellow == true) {
		rectY = currentAnimY->GetCurrentFrame();
		App->render->Blit(bgBorders, 19, 10, &rectY);
	}
	bool playRed = false;
	for (int i = 0; i < 8; i++) {
		if (App->scene->ReadTile(i, 4) == false) {
			playRed = true;
			break;
		}
		else {
			playRed = false;
		}
	}
	if (playRed ==true ) {
		App->fade->EnableOnly(this, (Module*)App->timer);
			rectR = currentAnimR->GetCurrentFrame();
			App->render->Blit(bgBorders, 19, 10, &rectR);
	}
	//rectLevel = currentAnimLevel->GetCurrentFrame();
	//App->render->Blit(bgBorders, 50, 30, &rectLevel);

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


void ModuleScene::DestroyLines()
{
	///*{
	//	for (int i = 0; i < 12; i++)
	//	{
	//		for (int j = 0; j < 8; j++)
	//		{

	//			if (map[i][j] == '0')
	//			{
	//			}

	//			else if (map[i][j] == 'A')
	//			{
	//				if (map[i][j + 1] == 'A')
	//				{
	//					if (map[i][j + 2] == 'A')
	//					{
	//						map[i][j] = '0';
	//						map[i][j + 1] = '0';
	//						map[i][j + 2] = '0';
	//					}
	//					if (map[i][j - 1] == 'A')
	//					{
	//						map[i][j] = '0';
	//						map[i][j + 1] = '0';
	//						map[i][j - 1] = '0';

	//						if (map[i][j - 2] == 'A')
	//						{
	//							map[i][j - 2] = '0';
	//						}
	//					}
	//				}

	//				else if (map[i][j - 1] == 'A')
	//				{
	//					if (map[i][j - 2] == 'A')
	//					{
	//						map[i][j] = '0';
	//						map[i][j - 1] = '0';
	//						map[i][j - 2] = '0';
	//					}
	//				}

	//				else if (map[i + 1][j] == 'A')
	//				{
	//					if (map[i + 2][j] == 'A')
	//					{
	//						Score += 100;
	//					}
	//					if (map[i - 1][j] == 'A')
	//					{
	//						Score += 100;

	//						if (map[i - 2][j] == 'A')
	//						{
	//							Score += 100;
	//						}
	//					}
	//				}

	//				else if (map[i - 1][j] == 'A')
	//				{
	//					if (map[i - 2][j] == 'A')
	//					{
	//						Score += 100;
	//					}
	//				}

	//				else if (map[i + 1][j + 1] == 'A')
	//				{
	//					if (map[i + 2][j + 2] == 'A')
	//					{
	//						Score += 100;
	//					}
	//					if (map[i - 1][j - 1] == 'A')
	//					{
	//						Score += 100;

	//						if (map[i - 2][j - 2] == 'A')
	//						{
	//							Score += 100;
	//						}
	//					}
	//				}

	//				else if (map[i - 1][j - 1] == 'A')
	//				{
	//					if (map[i - 2][j - 2] == 'A')
	//					{
	//						Score += 100;
	//					}
	//				}

	//				else if (map[i - 1][j + 1] == 'A')
	//				{
	//					if (map[i - 2][j + 2] == 'A')
	//					{
	//						map[i][j] = '0';
	//						map[i - 1][j + 1] == '0';
	//						map[i - 2][j + 2] = '0';
	//					}
	//					if (map[i + 1][j - 1] == 'A')
	//					{
	//						map[i][j] = '0';
	//						map[i - 1][j + 1] == '0';
	//						map[i + 1][j - 1] = '0';

	//						if (map[i - 2][j + 2] == 'A')
	//						{
	//							map[i - 2][j + 2] = '0';
	//						}
	//					}
	//				}

	//				else if (map[i + 1][j - 1] == 'A' && i < 7 && j < 11)
	//				{
	//					if (map[i + 2][j - 2] == 'A' && i < 6 && j < 11)
	//					{
	//						map[i][j] = '0';
	//						map[i + 1][j - 1] = '0';
	//						map[i + 2][j - 2] = '0';
	//					}
	//				}
	//			}
	//		}
	//	}
	//}*/
}