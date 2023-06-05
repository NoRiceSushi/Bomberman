#include "ModuleGameOver.h"
#include "ModuleInput.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"
#include "ModulePlayer.h"
#include "ModulePlayers.h"
#include "ModuleFade.h"
#include "ModuleScore.h"
#include "ModuleLose.h"
#include "Animation.h"
#include "SDL/include/SDL.h"

ModuleGameOver::ModuleGameOver(bool startEnabled) : Module(startEnabled)
{
	AnimLettersG.PushBack({ 0,1074, 45, 46 }); //G

	AnimLettersA.PushBack({ 48,1074, 45, 46 }); //A

	AnimLettersM.PushBack({ 96,1074, 45, 46 });  //M

	AnimLettersE.PushBack({ 144,1074, 45, 46 }); //E

	AnimLettersO.PushBack({ 192,1074, 45, 46 });//O

	AnimLettersV.PushBack({ 240,1074, 45, 46 });//V

	AnimLettersE2.PushBack({ 288,1074, 45, 46 });//E

	AnimLettersR.PushBack({ 336,1074, 45, 46 });//R
	//AnimLetters.speed = 0.4f;

}
ModuleGameOver::~ModuleGameOver()
{

}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	gameover_png = App->textures->Load("Assets/Sprite/Game_over.png");
	App->audio->PlayMusic("Assets/audio/24_Game_Over.ogg", 1.0f);
	letter = App->textures->Load("Assets/Sprite/SpriteSheetOP.png");
	LettersAnimationG = &AnimLettersG;
	LettersAnimationA = &AnimLettersA;
	LettersAnimationM = &AnimLettersM;
	LettersAnimationE = &AnimLettersE;
	LettersAnimationO = &AnimLettersO;
	LettersAnimationV = &AnimLettersV;
	LettersAnimationE2 = &AnimLettersE2;
	LettersAnimationR = &AnimLettersR;
	App->players->Disable();
	App->player->Disable();
	App->lose->Disable();
	App->scene->Disable();
	App->score->Disable();
	//if (App->scene->ReadTile(4, 0) == false || App->scene->ReadTile(5, 0) == false)
	//{
	//	gameover_png = App->textures->Load("Assets/Game_over.png");
	//	App->audio->PlayMusic("Assets/audio/19_Lose.ogg", 1.0f);
	//	/*App->fade->FadeToBlack(this, (Module*)App->gameover, 90);*/
	//}
	LetterAOnPos = false;
	return true;
}

update_status ModuleGameOver::Update()
{
	
	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart < 5000) {
		if (lettersPosG < targetPosG && moveLettersG) {
			lettersPosG += 1;
		}
		else {
			moveLettersG = false;
		}
		if (SDL_GetTicks() - timerStart > 200) {
			if (lettersPosA < targetPosA && moveLettersA) {
				lettersPosA += 1;
			}
			else {
				moveLettersA = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 400) {
			if (lettersPosM < targetPosM && moveLettersM) {
				lettersPosM += 1;
			}
			else {
				moveLettersM = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 600) {
			if (lettersPosE < targetPosE && moveLettersE) {
				lettersPosE += 1;
			}
			else {
				moveLettersE = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 800) {
			if (lettersPosO < targetPosO && moveLettersO) {
				lettersPosO += 1;
			}
			else {
				moveLettersO = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 1000) {
			if (lettersPosV < targetPosV && moveLettersV) {
				lettersPosV += 1;
			}
			else {
				moveLettersV = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 1200) {
			if (lettersPosE2 < targetPosE2 && moveLettersE2) {
				lettersPosE2 += 1;
			}
			else {
				moveLettersE = false;
			}
		}
		if (SDL_GetTicks() - timerStart > 1400) {
			if (lettersPosR < targetPosR && moveLettersR) {
				lettersPosR += 1;
			}
			else {
				moveLettersR = false;
			}
		}
	}
	if (SDL_GetTicks() - timerStart > 4999 && SDL_GetTicks() - timerStart < 9000) {
		
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 50);
	}
	if (SDL_GetTicks() - timerStart > 9000) {
		timerStart = 0;
		timerStarted = false;
		return update_status::UPDATE_STOP;
	}
	
	LettersAnimationG->Update();
	LettersAnimationA->Update();
	LettersAnimationM->Update();
	LettersAnimationE->Update();
	LettersAnimationO->Update();
	LettersAnimationV->Update();
	LettersAnimationE2->Update();
	LettersAnimationR->Update();
	return update_status::UPDATE_CONTINUE;
	
}

// Update: draw background
update_status ModuleGameOver::PostUpdate()
{
	// Draw everything --------------------------------------


	App->render->Blit(gameover_png, 0, 0, NULL);
	SDL_Rect rectG = LettersAnimationG->GetCurrentFrame();
	App->render->Blit(letter, 58, lettersPosG, &rectG);
	SDL_Rect rectA = LettersAnimationA->GetCurrentFrame();
	App->render->Blit(letter, 105, lettersPosA, &rectA);
	SDL_Rect rectM = LettersAnimationM->GetCurrentFrame();
	App->render->Blit(letter, 154, lettersPosM, &rectM);
	SDL_Rect rectE = LettersAnimationE->GetCurrentFrame();
	App->render->Blit(letter, 201, lettersPosE, &rectE);
	SDL_Rect rectO = LettersAnimationO->GetCurrentFrame();
	App->render->Blit(letter, 73, lettersPosO, &rectO);
	SDL_Rect rectV = LettersAnimationV->GetCurrentFrame();
	App->render->Blit(letter, 121, lettersPosV, &rectV);
	SDL_Rect rectE2 = LettersAnimationE2->GetCurrentFrame();
	App->render->Blit(letter, 169, lettersPosE2, &rectE2);
	SDL_Rect rectR = LettersAnimationR->GetCurrentFrame();
	App->render->Blit(letter, 218, lettersPosR, &rectR);
	return update_status::UPDATE_CONTINUE;
}