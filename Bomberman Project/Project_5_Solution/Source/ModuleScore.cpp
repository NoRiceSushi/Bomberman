#include "ModuleScore.h"
#include "Application.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "..//External_Libraries/SDL_image/include/SDL_image.h"
#include <sstream>
#include <string.h>
using namespace std;

ModuleScore::ModuleScore(bool startEnabled) : Module(startEnabled)
{
}


ModuleScore::~ModuleScore()
{
}

bool ModuleScore::Init()
{
	return true;
}

bool ModuleScore::Start()
{
	LOG("Loading player textures");

	bool ret = true;


	char lookupTable[] = { "0123456789" };
	scoreFont = App->fonts->Load("Assets/test.png", lookupTable, 1);



	return ret;

}

update_status ModuleScore::Update()
{
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScore::PostUpdate()
{

	sprintf_s(scoreText, MAX_SCORE_LENGTH, "%6d", score);
	App->fonts->BlitText(20, 16, scoreFont, scoreText);
	return update_status::UPDATE_CONTINUE;
}


