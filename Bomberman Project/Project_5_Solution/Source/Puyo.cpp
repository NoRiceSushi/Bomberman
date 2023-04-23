#include "ModulePlayer.h"
#include "Application.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "Puyo.h"

#include "SDL/include/SDL.h"
#include "SDL/include/SDL_scancode.h"
#include <iostream>

using namespace std;

Puyo::Puyo(){

//	color = rand() % (3+ App->player->verde);
	//downAnim.PushBack({0, color*16, 16,16});

	/*switch (color)
	{
		case 0:
			stayAnim;	//Animacion color y=0, poner Push Back como en la solucion 4 de clase
			moveAnim;
			break;

		case 1:
			//ETCETCETC Cada color es un numero
			break;
	}*/
}

Puyo::~Puyo(){}

bool Puyo::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/SpriteSheetPuyos.png"); // arcade version
	

	return ret;
}


void Puyo::UpdatePuyo() {
	currentAnimation = &downAnim;
	position.y += speed;
}
