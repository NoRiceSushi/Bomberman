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
	//insertcoin blink animation
	Blink.PushBack({0,40,96,8});
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,32,96,8 });
	Blink.loop = true;
	Blink.speed = 0.1f;

	//insertcoin out
	Out.PushBack({ 0,32,96,8 });
	Out.loop = false;

	//ready anim in
	readyIn.PushBack({ 0,72,80,16 });
	readyIn.loop = false;
	//ready anim out
	readyOut.PushBack({ 0,0,0,0 });
	readyOut.loop = false;

	//bomb anim idle
	bombaIdle.PushBack({ 0,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.PushBack({ 96,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.PushBack({ 0,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.PushBack({ 96,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.PushBack({ 0,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.PushBack({ 96,112,48,48 });
	bombaIdle.PushBack({ 48,112,48,48 });
	bombaIdle.speed = 0.1f;
	bombaIdle.loop = false;

	//bomb anim out
	bombaOut.PushBack({ 0,0,0,0 });
	bombaOut.loop = false;

	//explosion anim
	explosionBomb.PushBack({0,160,128,128});
	explosionBomb.PushBack({ 128,160,128,128 });
	explosionBomb.PushBack({ 256,160,128,128 });
	explosionBomb.PushBack({ 384,160,128,128 });
	explosionBomb.PushBack({ 512,160,128,128 });
	explosionBomb.PushBack({ 640,160,128,128 });
	explosionBomb.PushBack({ 768,160,128,128 });
	explosionBomb.PushBack({ 896,160,128,128 });
	explosionBomb.PushBack({ 1024,160,128,128 });
	explosionBomb.PushBack({ 1152,160,128,128 });
	explosionBomb.PushBack({ 0,0,0,0 });
	explosionBomb.loop = false;
	explosionBomb.speed = 0.4f;

	//explosion out
	explosionOut.PushBack({ 0,0,0,0 });
	explosionOut.loop = false;

	//go! idle anim
	goIdle.PushBack({0,288,64,64});
	goIdle.PushBack({ 64,288,64,64 });
	goIdle.PushBack({ 128,288,64,64 });
	goIdle.PushBack({ 192,288,64,64 });
	goIdle.PushBack({ 256,288,64,64 });
	goIdle.PushBack({ 320,288,64,64 });
	goIdle.PushBack({ 384,288,64,64 });
	goIdle.PushBack({ 448,288,64,64 });
	goIdle.PushBack({ 384,288,64,64 });
	goIdle.PushBack({ 320,288,64,64 });
	goIdle.PushBack({ 256,288,64,64 });
	goIdle.PushBack({ 192,288,64,64 });
	goIdle.PushBack({ 128,288,64,64 });
	goIdle.PushBack({ 64,288,64,64 });

	goIdle.loop = true;
	goIdle.speed = 0.5;

	//go! out anim
	goOut.PushBack({ 0,0,0,0 });
	goOut.loop = false;


	rect2 = { 0,72, 80, 16 };
	rectBomb = {0,112,48,48 };
	rectExplosion = {0,160,128,288};
	rectGo = { 0,288,64,64 };

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
	readyAnim = &readyIn;

	bombazaText = App->textures->Load("Assets/SpriteSheetPuyos+Bomb.png");
	bombaAnim = &bombaOut;

	explosionText = App->textures->Load("Assets/SpriteSheetPuyos+Bomb.png");
	explosionAnim = &explosionOut;

	goText = App->textures->Load("Assets/SpriteSheetPuyos+Bomb.png");
	goAnim = &goOut;

	position.x = 50;
	position.y = 260;
	readyScreenEnd = false;
	readyOnPos = false;
	bombOnPos = false;
	posSpeed = 8;
	posSpeedBomba = 10;
	posSpeedGo = 0;
	positionBomba.x = 72;
	positionBomba.y = -96;
	positionGo.x = 57;
	positionGo.y = 92;

	return ret;


}

update_status ModuleScore::Update()
{
	if (App->input->keys[SDL_SCANCODE_C] != KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
	{
		App->audio->PlayFx(sfx_coin);
		coins += 1;
	}
	if (coins == 0) { coinCurrentAnim = &Blink; }
	else coinCurrentAnim = &Out;

	if (coins > 0 && position.y >= 110 && readyOnPos == false) {
		position.y -= posSpeed;
		if (posSpeed > 1) { posSpeed -= 0.2; }
		if (position.y >= 110 && position.y <= 114) readyOnPos = true;
	}

	if (readyOnPos == true ) {
		if (positionBomba.y < 92) {
			positionBomba.y += posSpeedBomba;
			if (posSpeedBomba > 1) { posSpeedBomba -= 0.2; }
			bombaAnim = &bombaIdle;
		}
	}

	if (bombaAnim->HasFinished() && bombaAnim == &bombaIdle) {
		explosionAnim = &explosionBomb;
		bombaAnim = &bombaOut;
		readyAnim = &readyOut;
		goAnim = &goIdle;
	}
	if (explosionAnim->HasFinished() && explosionAnim == &explosionBomb) readyScreenEnd = true;
	
	if (goAnim == &goIdle) {
		positionGo.y += posSpeedGo;
		if (posSpeedGo < 5) {
			posSpeedGo += 0.025;
		}
		if (positionGo.y >= 300) {
			goAnim = &goOut;
		}
	}

	coinCurrentAnim->Update();
	readyAnim->Update();
	bombaAnim->Update();
	explosionAnim->Update();
	goAnim->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScore::PostUpdate()
{
	if (!App->menu->isMenuOpen) {

		rect1 = coinCurrentAnim->GetCurrentFrame();
		rect2 = readyAnim->GetCurrentFrame();
		rectBomb = bombaAnim->GetCurrentFrame();
		rectExplosion = explosionAnim->GetCurrentFrame();
		rectGo = goAnim->GetCurrentFrame();

		sprintf_s(scoreText, MAX_SCORE_LENGTH, "%6d", score);
		App->fonts->BlitText(20, 16, scoreFont, scoreText);
		sprintf_s(scoreText, MAX_SCORE_LENGTH, "%2d", coins);
		App->fonts->BlitText(282, 209, scoreFont, scoreText);
		App->render->Blit(textureCoins, 216, 209, 0, 2);
		App->render->Blit(insertCoins, 110, 90,&rect1);

		if (!readyScreenEnd) {
			App->render->Blit(ready, position.x, position.y, &rect2);
		}

		App->render->Blit(bombazaText, positionBomba.x, positionBomba.y, &rectBomb);
		App->render->Blit(goText, positionGo.x, positionGo.y, &rectGo);
		App->render->Blit(explosionText, 20, 60, &rectExplosion);
	}
	return update_status::UPDATE_CONTINUE;
}


