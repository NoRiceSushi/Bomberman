#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "ModuleParticles.h"
#include "ModuleMenu.h"
#include "ModuleAudio.h"
#include "ModulePlayers.h"
#include "ModulePlayer.h"
#include "ModuleFade.h"
#include "ModuleGameOver.h"
#include "ModuleFonts.h"
#include "ModuleScore.h"
#include "ModuleLose.h"
#include "ModuleRender.h"
#include "ModuleWin.h"
#include "ClearStage1.h"
#include "SceneIntro.h"
#include "IntroInfo.h"
#include "StudioNames.h"
#include "ModuleBombazo.h"





Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] = window = new ModuleWindow(true);
	modules[1] = input = new ModuleInput(true);
	modules[2] = textures = new ModuleTextures(true);
	modules[3] = scene = new ModuleScene(false);
	modules[4] = audio = new ModuleAudio(true);


	//modules[4] = puyo = new Puyo();
	modules[5] = players = new ModulePlayers(true);
	modules[6] = particles = new ModuleParticles(true);
	modules[7] = menu = new ModuleMenu(true);
	modules[8] = gameover = new ModuleGameOver(false);
	modules[9] = player = new ModulePlayer(false);
	modules[10] = fonts = new ModuleFonts(true);
	modules[11] = score = new ModuleScore(false);
	modules[12] = lose = new ModuleLose(false);
	modules[13] = win = new ModuleWin(false);
	modules[14] = clearstage1 = new ClearStage1(false);

	modules[15] = sceneIntro = new SceneIntro(false);
	modules[16] = studio = new StudioNames(false);
	modules[17] = introInfo = new IntroInfo(true);
	modules[18] = Bombazo = new ModuleBombazo(false);
	modules[19] = fade = new ModuleFade(true);
	modules[20] = render = new ModuleRender(true);



}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	// Only active modules will be 'started'
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : update_status::UPDATE_CONTINUE;

	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return ret;

	SDL_Delay(16.666f);

	//return ret;
}

bool Application::CleanUp()
{
	bool ret = true;


	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}