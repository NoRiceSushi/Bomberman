//#include "ModuleGameOver.h"

//#include "Application.h"
//#include "ModuleTextures.h"
//#include "ModuleRender.h"
//#include "ModuleAudio.h"
//
//ModuleScene::ModuleGameOver()
//{
//
//}
//
//ModuleScene::~ModuleGameOver()
//{
//
//}
//
//// Load assets
//bool ModuleGameOver::Start()
//{
//	LOG("Loading background assets");
//
//	bool ret = true;
//
//	gameover_png = App->textures->Load("Assets/gameover.png");
//	App->audio->PlayMusic("Assets/audio/08_stage_1.ogg", 1.0f);
//	return ret;
//}
//
//update_status ModuleScene::Update()
//{
//
//	return update_status::UPDATE_CONTINUE;
//}
//
//// Update: draw background
//update_status ModuleScene::PostUpdate()
//{
//	// Draw everything --------------------------------------
//	App->render->Blit(bgTexture, -231, 0, 0, 10);
//	App->render->Blit(bgTexture2, 0, 0, 0, 10);
//
//	return update_status::UPDATE_CONTINUE;
//}
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// From another
//#include "Globals.h"
//#include "Application.h"
//#include "ModuleTextures.h"
//#include "ModuleAudio.h"
//#include "ModuleInput.h"
//#include "ModuleRender.h"
//#include "ModuleFadeToBlack.h"
//#include "ModuleSceneGameOver.h"
//#include "ModuleEnemies.h"
//
//// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
//
//ModuleGameOver::ModuleGameOver()
//{}
//
//ModuleGameOver::~ModuleGameOver()
//{}
//
//// Load assets
//bool ModuleGameOver::Start()
//{
//	LOG("Loading game over");
//
//	background = App->textures->Load("Outzone/GameOver.png");
//
//	//App->audio->PlayMusic("rtype/intro.ogg", 1.0f);
////	fx = App->audio->LoadFx("rtype/starting.wav");
//	App->render->camera.x = App->render->camera.y = 0;
//
//	return true;
//}



//// Update: draw background
//update_status ModuleGameOver::Update()
//{
//	App->render->Blit(background, 0, 0, NULL);
//
//	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
//	{
//		App->fade->FadeToBlack((Module*)App->scene_gameover, (Module*)App->scene_intro);
//		App->audio->PlayFx(fx);
//	}
//
//	return UPDATE_CONTINUE;
//}
