#include "ModuleScore.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include <stdio.h>
#include "..//External_Libraries/SDL_image/include/SDL_image.h"
#include <sstream>
#include <string.h>
#include <iostream>
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_scancode.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleMenu.h"
#include "Animation.h"
using namespace std;

ModuleScore::ModuleScore(bool startEnabled) : Module(startEnabled)
{
	//blink animation
	Blink.PushBack({0,40,96,8});
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,32,96,8 });
	Blink.loop = true;
	Blink.speed = 0.1;

	Out.PushBack({ 0,32,96,8 });
	Out.loop = false;

	readyIn.PushBack({ 0,72,80,16 });
	readyOut.PushBack({ 0,32,80,16 });

	rect2 = { 0,72, 80, 16 };
}


ModuleScore::~ModuleScore()
{
}

bool ModuleScore::Init()
{
	return true;
}

bool ModuleScore::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	sfx_coin = App->audio->LoadFx("Assets/sfx/sfx_coins.wav");
	char lookupTable[] = { "0123456789" };
	scoreFont = App->fonts->Load("Assets/test.png", lookupTable, 1);

	textureCoins = App->textures->Load("Assets/Credits.png");

	insertCoins = App->textures->Load("Assets/Numeros+SpritesLetras.png");
	coinCurrentAnim = &Blink;

	ready = App->textures->Load("Assets/Numeros+SpritesLetras.png");
	readyAnim = &readyOut;

	position.x = 50;
	position.y = 260;
	readyScreen = false;
	readyOnPos = false;
	posSpeed = 7;

	return ret;


}

update_status ModuleScore::Update()
{
	if (App->input->keys[SDL_SCANCODE_C] != KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
	{
		App->audio->PlayFx(sfx_coin);
		App->score->coins += 1;
	}
	if (coins == 0) { coinCurrentAnim = &Blink; }
	else coinCurrentAnim = &Out;

	if (coins > 0 && position.y >= 110 && readyOnPos == false) {
		position.y -= posSpeed;
		if (posSpeed > 1) { posSpeed -= 0.2; }
		if (position.y >= 110 && position.y <= 114) readyOnPos = true;
	}
	//else
	//{
	//	readyOnPos = true;
	//}


	coinCurrentAnim->Update();
	readyAnim->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScore::PostUpdate()
{
	if (!App->menu->isMenuOpen) {

		rect1 = coinCurrentAnim->GetCurrentFrame();

		sprintf_s(scoreText, MAX_SCORE_LENGTH, "%6d", score);
		App->fonts->BlitText(20, 16, scoreFont, scoreText);
		sprintf_s(scoreText, MAX_SCORE_LENGTH, "%2d", coins);
		App->fonts->BlitText(282, 209, scoreFont, scoreText);
		App->render->Blit(textureCoins, 216, 209, 0, 2);
		App->render->Blit(insertCoins, 110, 90,&rect1);

		if (!readyOnPos) {
			App->render->Blit(ready, position.x, position.y, &rect2);
		}
	}
	return update_status::UPDATE_CONTINUE;
}


