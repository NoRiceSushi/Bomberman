#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

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
	bgTexture2 = App->textures->Load("Assets/FondoIzquierdaLimpio.png");
	App->audio->PlayMusic("Assets/audio/08_stage_1.ogg", 1.0f);
	return ret;
}

update_status ModuleScene::Update()
{

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, -231, 0, 0, 10);
	App->render->Blit(bgTexture2, 0, 0, 0, 10);

	return update_status::UPDATE_CONTINUE;
}

void ModuleScene::SetTile(int x, int y, char value)
{
	map[x][y] = value;
}