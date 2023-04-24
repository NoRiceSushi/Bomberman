#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

/*{	-,-,-,X,X,-,-,-
	-,-,-,X,X,-,-,-
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0 }
*/
ModuleScene::ModuleScene()
{
	
}

ModuleScene::~ModuleScene()
{

}

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

update_status ModuleScene::PostUpdate()
{
	App->render->Blit(bgTexture, -231, 0, 0, 10);
	App->render->Blit(bgTexture2, 0, 0, 0, 10);

	return update_status::UPDATE_CONTINUE;
}

void ModuleScene::SetTile(int x, int y, char value)
{
	map[x][y] = value;
}

bool ModuleScene::isYEmpty(int x, int y)
{
	if (map[x][y - 1] == '0') 
	{
		return true;
	}

	else
	{
		return false;
	}
}