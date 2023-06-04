#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFade.h"
#include "StudioNames.h"
#include "SDL/include/SDL_scancode.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,40,96,8 });
	Blink.PushBack({ 0,32,96,8 });
	Blink.loop = true;
	Blink.speed = 0.25f;

	Fire.PushBack({ 161,517,17,23 });
	Fire.PushBack({ 161,543,17,20 });
	Fire.PushBack({ 161,565,17,20 });
	Fire.PushBack({ 161,543,17,20 });
	Fire.loop = true;
	Fire.speed = 0.1f;
}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	Starting1 = App->textures->Load("Assets/IntroAnim/Starting1.png");
	Starting2 = App->textures->Load("Assets/IntroAnim/Starting2.png");
	Starting3 = App->textures->Load("Assets/IntroAnim/Starting3.png");
	Starting4 = App->textures->Load("Assets/IntroAnim/Starting4.png");
	Starting5 = App->textures->Load("Assets/IntroAnim/Starting5.png");
	Starting6 = App->textures->Load("Assets/IntroAnim/Starting6.png");
	Starting7 = App->textures->Load("Assets/IntroAnim/Starting7.png");
	Starting8 = App->textures->Load("Assets/IntroAnim/Starting8.png");
	Starting9 = App->textures->Load("Assets/IntroAnim/Starting9.png");
	bgTexture = App->textures->Load("Assets/StartingScreen.png");
	App->audio->PlayMusic("Assets/audio/02_Title.ogg", 1.0f); 
	sfx_explosion = App->audio->LoadFx("Assets/sfx/sfx_start_explosion.wav");
	InsertA = App->textures->Load("Assets/Numeros+SpritesLetras.png");
	AnimBlink= &Blink;
	bgBorders = App->textures->Load("Assets/SpriteSheetOP.png");
	AnimFire = &Fire;

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status SceneIntro::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 70);
	}
	AnimFire->Update();
	AnimBlink->Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	rectFire = AnimFire->GetCurrentFrame();
	App->render->Blit(bgBorders, 240, 85, &rectFire);
	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() -  timerStart > 4000 && SDL_GetTicks() - timerStart < 4300) {
		
		App->render->Blit(Starting1, 0, 0, NULL);
		App->audio->PlayFx(sfx_explosion);
	}
	else if (SDL_GetTicks() - timerStart > 4300) {

		App->render->Blit(Starting2, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4500) {

		App->render->Blit(Starting3, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4700) {

		App->render->Blit(Starting4, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4900) {

		App->render->Blit(Starting5, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5100) {

		App->render->Blit(Starting6, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5300) {

		App->render->Blit(Starting7, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5500) {

		App->render->Blit(Starting8, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5700) {

		App->render->Blit(Starting9, 0, 0, NULL);
		App->fade->FadeToBlack(this, (Module*)App->scene, 70);
	}
	rectBlink = AnimBlink ->GetCurrentFrame();
	App->render->Blit(InsertA, 110, 140, &rectBlink);
	return update_status::UPDATE_CONTINUE;
}