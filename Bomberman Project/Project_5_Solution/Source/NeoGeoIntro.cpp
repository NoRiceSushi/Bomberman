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
	if (SDL_GetTicks() - timerStart > 4000 && SDL_GetTicks() - timerStart < 4150) {

		App->render->Blit(Starting1, 0, 0, NULL);
		App->audio->PlayFx(sfx_explosion);
	}
	else if (SDL_GetTicks() - timerStart > 4150) {

		App->render->Blit(Starting2, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4300) {

		App->render->Blit(Starting3, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4450) {

		App->render->Blit(Starting4, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4600) {

		App->render->Blit(Starting5, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4750) {

		App->render->Blit(Starting6, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 4900) {

		App->render->Blit(Starting7, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5050) {

		App->render->Blit(Starting8, 0, 0, NULL);
	}
	if (SDL_GetTicks() - timerStart > 5200) {

		App->render->Blit(Starting9, 0, 0, NULL);
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 70);
	}
	return update_status::UPDATE_CONTINUE;
}