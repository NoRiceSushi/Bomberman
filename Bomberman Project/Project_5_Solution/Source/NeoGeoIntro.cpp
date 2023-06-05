#include "NeoGeoIntro.h"

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

NeoGeoIntro::NeoGeoIntro(bool startEnabled) : Module(startEnabled)
{

}

NeoGeoIntro::~NeoGeoIntro()
{

}

// Load assets
bool NeoGeoIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	Starting1 = App->textures->Load("Assets/NeoGeoIntro/0.gif");
	Starting2 = App->textures->Load("Assets/NeoGeoIntro/1.gif");
	Starting3 = App->textures->Load("Assets/NeoGeoIntro/2.gif");
	Starting4 = App->textures->Load("Assets/NeoGeoIntro/3.gif");
	Starting5 = App->textures->Load("Assets/NeoGeoIntro/4.gif");
	Starting6 = App->textures->Load("Assets/NeoGeoIntro/5.gif");
	Starting7 = App->textures->Load("Assets/NeoGeoIntro/6.gif");
	Starting8 = App->textures->Load("Assets/NeoGeoIntro/7.gif");
	Starting9 = App->textures->Load("Assets/NeoGeoIntro/8.gif"); 
	Starting10 = App->textures->Load("Assets/NeoGeoIntro/9.gif");
	Starting11 = App->textures->Load("Assets/NeoGeoIntro/10.gif");
	Starting12 = App->textures->Load("Assets/NeoGeoIntro/11.gif");
	Starting13 = App->textures->Load("Assets/NeoGeoIntro/12.gif");
	Starting14 = App->textures->Load("Assets/NeoGeoIntro/13.gif");
	Starting15 = App->textures->Load("Assets/NeoGeoIntro/14.gif");
	Starting16 = App->textures->Load("Assets/NeoGeoIntro/15.gif");
	Starting17 = App->textures->Load("Assets/NeoGeoIntro/16.gif");
	Starting18 = App->textures->Load("Assets/NeoGeoIntro/17.gif");
	Starting19 = App->textures->Load("Assets/NeoGeoIntro/18.gif");
	Starting20 = App->textures->Load("Assets/NeoGeoIntro/19.gif");
	Starting21 = App->textures->Load("Assets/NeoGeoIntro/20.gif");
	Starting22 = App->textures->Load("Assets/NeoGeoIntro/21.gif");
	Starting23 = App->textures->Load("Assets/NeoGeoIntro/22.gif");
	Starting24 = App->textures->Load("Assets/NeoGeoIntro/23.gif");
	Starting25 = App->textures->Load("Assets/NeoGeoIntro/24.gif");
	Starting26 = App->textures->Load("Assets/NeoGeoIntro/25.gif");
	Starting27 = App->textures->Load("Assets/NeoGeoIntro/26.gif");
	Starting28 = App->textures->Load("Assets/NeoGeoIntro/27.gif");
	Starting29 = App->textures->Load("Assets/NeoGeoIntro/28.gif");
	Starting30 = App->textures->Load("Assets/NeoGeoIntro/29.gif");
	Starting31 = App->textures->Load("Assets/NeoGeoIntro/30.gif");
	Starting32 = App->textures->Load("Assets/NeoGeoIntro/31.gif");
	Starting33 = App->textures->Load("Assets/NeoGeoIntro/32.gif");
	Starting34 = App->textures->Load("Assets/NeoGeoIntro/33.gif");
	Starting35 = App->textures->Load("Assets/NeoGeoIntro/34.gif");
	Starting36 = App->textures->Load("Assets/NeoGeoIntro/35.gif");


	App->audio->PlayMusic("Assets/audio/01_NeoGeo_Title.ogg", 1.0f);


	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status NeoGeoIntro::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 70);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status NeoGeoIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	if (!timerStarted) {
		timerStarted = true;
		timerStart = SDL_GetTicks();
	}
	if (SDL_GetTicks() - timerStart > 150 && SDL_GetTicks() - timerStart < 150) {

		App->render->Blit(Starting1, 0, 0, NULL);

	}
	else if (SDL_GetTicks() - timerStart > 300) {

		App->render->Blit(Starting2, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 450) {

		App->render->Blit(Starting3, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 600) {

		App->render->Blit(Starting4, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 750) {

		App->render->Blit(Starting5, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 900) {

		App->render->Blit(Starting6, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1050) {

		App->render->Blit(Starting7, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1200) {

		App->render->Blit(Starting8, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1350) {

		App->render->Blit(Starting9, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1500) {

		App->render->Blit(Starting10, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1650) {

		App->render->Blit(Starting11, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1800) {

		App->render->Blit(Starting12, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 1950) {

		App->render->Blit(Starting13, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2100) {

		App->render->Blit(Starting14, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2250) {

		App->render->Blit(Starting15, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2400) {

		App->render->Blit(Starting16, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2550) {

		App->render->Blit(Starting17, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2700) {

		App->render->Blit(Starting18, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 2850) {

		App->render->Blit(Starting19, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3000) {

		App->render->Blit(Starting20, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3150) {

		App->render->Blit(Starting21, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3300) {

		App->render->Blit(Starting22, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3450) {

		App->render->Blit(Starting23, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3600) {

		App->render->Blit(Starting24, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3750) {

		App->render->Blit(Starting25, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 3900) {

		App->render->Blit(Starting26, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4050) {

		App->render->Blit(Starting27, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4200) {

		App->render->Blit(Starting28, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4350) {

		App->render->Blit(Starting29, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4500) {

		App->render->Blit(Starting30, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4650) {

		App->render->Blit(Starting31, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4800) {

		App->render->Blit(Starting32, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4950) {

		App->render->Blit(Starting33, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5100) {

		App->render->Blit(Starting34, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5250) {

		App->render->Blit(Starting35, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5400) {

		App->render->Blit(Starting36, 0, 0, NULL);
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 70);
	}
	return update_status::UPDATE_CONTINUE;
}