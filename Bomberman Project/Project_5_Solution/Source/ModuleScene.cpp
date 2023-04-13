#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

ModuleScene::ModuleScene()
{

}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");

	return ret;
}

update_status ModuleScene::Update()
{

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	position.x = 1500;
	position.y = 120;
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, 0, 1);

	return update_status::UPDATE_CONTINUE;
}