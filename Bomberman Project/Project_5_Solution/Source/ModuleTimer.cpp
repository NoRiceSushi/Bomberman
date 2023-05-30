////time syncr
// bool end = false;
//while (!end)
//{
//	t1 = GetTime();
//	input();
//	logic(dt);
//	render();
//	dt = GetTime() - t1;
//}
//}

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
#include "ModuleFade.h"
#include "ModuleScore.h"
#include "ModuleScene.h"
#include "ClearStage1.h"
 #include "ModuleTimer.h"
#include "Animation.h"
 #include "SDL/include/SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleTimer::ModuleTimer(bool startEnabled) : Module(startEnabled)
{

}

ModuleTimer::~ModuleTimer()
{

}

// Load assets
bool ModuleTimer::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	App->audio->PlayMusic("Assets/audio/23_Danger.ogg", 1.0f);

	return true;
}

update_status ModuleTimer::Update()
{
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status  ModuleTimer::PostUpdate()
{
	// Draw everything --------------------------------------
	
	return update_status::UPDATE_CONTINUE;
}