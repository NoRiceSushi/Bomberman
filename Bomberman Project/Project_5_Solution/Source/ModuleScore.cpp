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
#include "ModuleTimer.h"
#include "SDL/include/SDL_audio.h"
#include "ModuleMenu.h"
#include "ModuleFade.h"
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
	Blink.speed = 0.25f;

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
	bombaIdle.speed = 0.25f;
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
	explosionBomb.speed = 0.3f;

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

	//bomb1 
	bomb1.PushBack({ 0,1031,38,38 });
	bomb1.PushBack({ 41,1033,38,38 });
	bomb1.PushBack({ 81,1033,38,38 });
	bomb1.PushBack({ 41,1033,38,38 });
	bomb1.loop = true;
	bomb1.speed = 0.2;

	bomb2.PushBack({ 121,1033,38,38 });
	bomb2.PushBack({ 161,1033,38,38 });
	bomb2.PushBack({ 201,1033,38,38 });
	bomb2.PushBack({ 241,1033,38,38 });
	bomb2.PushBack({ 201,1033,38,38 });
	bomb2.PushBack({ 161,1033,38,38 });
	bomb2.loop = true;
	bomb2.speed = 0.2;

	bomb3.PushBack({ 281,1033,38,38 });
	bomb3.PushBack({ 321,1033,38,38 });
	bomb3.PushBack({ 361,1033,38,38 });
	bomb3.PushBack({ 321,1033,38,38 });
	bomb3.loop = true;
	bomb3.speed = 0.2;

	bomb4.PushBack({ 401,1034,38,36 });
	bomb4.PushBack({ 441,1033,38,38 });
	bomb4.PushBack({ 481,1033,38,38 });
	bomb4.PushBack({ 441,1033,38,38 });
	bomb4.loop = true;
	bomb4.speed = 0.2;

	bomb5.PushBack({ 521,1033,38,38 });
	bomb5.PushBack({ 561,1033,38,38 });
	bomb5.PushBack({ 601,1033,38,38 });
	bomb5.PushBack({ 561,1033,38,38 });
	bomb5.loop = true;
	bomb5.speed = 0.2;

	bomb6.PushBack({ 642,1033,36,38 });
	bomb6.PushBack({ 681,1033,38,38 });
	bomb6.PushBack({ 681,1033,38,38 });
	bomb6.PushBack({ 681,1033,38,38 });
	bomb6.loop = true;
	bomb6.speed = 0.2;

	bomb7.PushBack({ 721,1033,38,38 });
	bomb7.PushBack({ 762,1033,36,38 });
	bomb7.PushBack({ 762,1033,36,38 });
	bomb7.PushBack({ 762,1033,36,38 });
	bomb7.loop = true;
	bomb7.speed = 0.2;

	Animlevelup.PushBack({ 102,518,57,45 });


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
	bgTexture = App->textures->Load("Assets/Sprite/background.png");
	sfx_coin = App->audio->LoadFx("Assets/sfx/sfx_coins.wav");
	char lookupTable[] = { "0123456789" };
	scoreFont = App->fonts->Load("Assets/Sprite/test.png", lookupTable, 1);

	textureCoins = App->textures->Load("Assets/Sprite/Credits.png");

	insertCoins = App->textures->Load("Assets/Sprite/Numeros+SpritesLetras.png");
	coinCurrentAnim = &Blink;

	ready = App->textures->Load("Assets/Sprite/Numeros+SpritesLetras.png");
	readyAnim = &readyIn;

	bombazaText = App->textures->Load("Assets/Sprite/SpriteSheetPuyos+Bomb.png");
	bombaAnim = &bombaOut;

	explosionText = App->textures->Load("Assets/Sprite/SpriteSheetPuyos+Bomb.png");
	explosionAnim = &explosionOut;

	goText = App->textures->Load("Assets/Sprite/SpriteSheetPuyos+Bomb.png");
	goAnim = &goOut;

	bgBorders = App->textures->Load("Assets/Sprite/SpriteSheetOP.png");
	currentAnimLevel = &Animlevelup;
	sfx_explosion = App->audio->LoadFx("Assets/sfx/sfx_start_explosion.wav");

	bomb = App->textures->Load("Assets/Sprite/SpriteSheetOP.png");
	bomb1Anim = &bomb1;
	bomb2Anim = &bomb2;
	bomb3Anim = &bomb3;
	bomb4Anim = &bomb4;
	bomb5Anim = &bomb5;
	bomb6Anim = &bomb6;
	bomb7Anim = &bomb7;

	position.x = 50;
	position.y = 260;
	readyScreenEnd = false;
	readyOnPos = false;
	bombOnPos = false;
	LevelOnPos = false;
	posSpeed = 8;
	posSpeedLevel = 8;
	posSpeedBomba = 10;
	posSpeedGo = 0;
	positionBomba.x = 72;
	positionBomba.y = -96;
	positionLevel.x = 72;
	positionLevel.y = -96;
	positionGo.x = 57;
	positionGo.y = 92;

	return ret;


}

update_status ModuleScore::Update()
{
	if (score >= 0 && score <= 2000)
	{
		App->render->Blit(bgTexture, -103, 0, 0, 0);
	}
	if (score >= 2000 && score <= 4000)
	{
		App->render->Blit(bgTexture, -231, 0, 0, 0);
	}
	if (score >= 4000 && score <= 6000)
	{
		App->render->Blit(bgTexture, -359, 0, 0, 0);
	}
	if (score >= 6000 /*&& score <= 150*/)
	{
		App->render->Blit(bgTexture, -487, 0, 0, 0);
	}
	if (score >= 8000 /*&& score <= 150*/)
	{
		App->render->Blit(bgTexture, -615, 0, 0, 0);
	}
	if (score >= 10000/* && score <= 150*/)
	{
		App->render->Blit(bgTexture, -743, 0, 0, 0);
	}
	if (score >= 12000/* && score <= 150*/)
	{
		App->render->Blit(bgTexture, -871, 0, 0, 0);
	}
	if (score >= 14000/* && score <= 150*/)
	{
		App->render->Blit(bgTexture, -999, 0, 0, 0);
	}
	if (App->input->keys[SDL_SCANCODE_C] != KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
	{
		App->audio->PlayFx(sfx_coin);
		coins += 1;
	}
	if (App->input->keys[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		score = score + 1000;
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
	if (score >= 20 && score <= 150) {
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
		App->audio->PlayFx(sfx_explosion);
	}
	if (explosionAnim->HasFinished() && explosionAnim == &explosionBomb) readyScreenEnd = true;
	
	if (goAnim == &goIdle) {
		positionGo.y += posSpeedGo;
		if (posSpeedGo < 5) {
			posSpeedGo += 0.13;
		}
		if (positionGo.y >= 300) {
			goAnim = &goOut;
		}
	}
	if (LevelPosY < targetPosLevel && moveLevel) {
		LevelPosY += 2;
	}
	else {
		moveLevel = false;
	}

	currentAnimLevel->Update();
	bomb1Anim->Update();
	bomb2Anim->Update();
	bomb3Anim->Update();
	bomb4Anim->Update();
	bomb5Anim->Update();
	bomb6Anim->Update();
	bomb7Anim->Update();
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
		if (score >= 1000)
		{
			rectlevel = currentAnimLevel->GetCurrentFrame();
			App->render->Blit(bgBorders, 100, LevelPosY, &rectlevel);
		}
		rect1 = coinCurrentAnim->GetCurrentFrame();
		rect2 = readyAnim->GetCurrentFrame();
		rectBomb = bombaAnim->GetCurrentFrame();
		rectExplosion = explosionAnim->GetCurrentFrame();
		rectGo = goAnim->GetCurrentFrame();
		if (score >= 2100 )
		{
			rectbomb1 = bomb1Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb1);
		}
		if (score >= 1500 && score <= 2100)
		{
			rectbomb2 = bomb2Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb2);
		}
		if (score >= 1000 && score <= 1500)
		{
			rectbomb3 = bomb3Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb3);
		}
		if (score >= 600 && score <= 1000)
		{
			rectbomb4 = bomb4Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb4);
		}
		if (score >= 300 && score <= 600)
		{
			rectbomb5 = bomb5Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb5);
		}
		if (score >= 150 && score <= 300)
		{
			rectbomb6 = bomb6Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 6, &rectbomb6);
		}
		if (score >= 20 && score <= 150)
		{
			rectbomb7 = bomb7Anim->GetCurrentFrame();
			App->render->Blit(bomb, 107, 7, &rectbomb7);
		}



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


