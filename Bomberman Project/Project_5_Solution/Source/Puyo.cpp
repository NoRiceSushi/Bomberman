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

using namespace std;

Puyo::Puyo() {
	color = rand() % (3+ App->player->verde);
	downAnim.PushBack({0, color*16, 16,16});

	switch (color)
	{
		case 0:
			stayAnim;/*Animacion color y=0, poner Push Back como en la solucion 4 de clase*/
			moveAnim;
			break;

		case 1:
			//ETCETCETC
	}


}

void Puyo::UpdatePuyo() {
	position.y += speed;
}
