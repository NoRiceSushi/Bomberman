#include "ModulePlayer.h"
#include <ctime>
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL.h"

#include "SDL/include/SDL_scancode.h"
#include <iostream>

const int ModulePlayer::figures[4] =
{
	0,1,1,1
};

bool ModulePlayer::Start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		window = SDL_CreateWindow(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenW, ScreenH, SDL_WINDOW_SHOWN);
		if (window != NULL)
		{
			render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (render != NULL)
			{
				SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
				int imgFlags = IMG_INIT_PNG;
				int initted = IMG_Init(imgFlags);
				if ((initted & imgFlags) != imgFlags)
					std::cout << "Failed to init required png support\n" << "IMG_Init() Error : " << IMG_GetError() << std::endl;
				
				SDL_Surface* loadBackground = IMG_Load("Game/Assets/background.png");
				background = SDL_CreateTextureFromSurface(render, loadBackground);
				SDL_FreeSurface(loadBackground);

				SDL_Surface* loadLeftBackground = IMG_Load("Game/Assets/FondoIzquierdaLimpio.png");
				leftbackground = SDL_CreateTextureFromSurface(render, loadLeftBackground);
				SDL_FreeSurface(loadLeftBackground);
				
				SDL_Surface* loadPuyos = IMG_Load("Game/Assets/SpriteSheetPuyos.png");
				puyos = SDL_CreateTextureFromSurface(render, loadPuyos);
				SDL_FreeSurface(loadPuyos);

				nextTetrimino();
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;

	running = true;
	return true;
}

void ModulePlayer::nextTetrimino()
{
	color = 1 + rand() % 7;
	int n = rand() % 7;
	for (int i = 0; i < 4; i++)
	{
		items[i].x = figures[i] % 4;
		items[i].y = int(figures[i] / 4);
	}
}

update_status ModulePlayer::Update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				rotate = true;
				break;
			case SDLK_LEFT:
				dx = -1;
				break;
			case SDLK_RIGHT:
				dx = 1;
				break;

			default:
				break;
			}
		default:
			break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_DOWN])
		delay = 50;

	return update_status::UPDATE_CONTINUE;
}

ModulePlayer::ModulePlayer()
{
	
}
/*ModulePlayer::~ModulePlayer()
{

}*/

void ModulePlayer::setRectPos(SDL_Rect& rect, int x, int y, int w, int h)
{
	rect = { x, y, w, h };
}

void ModulePlayer::moveRectPos(SDL_Rect& rect, int x, int y)
{
	rect.x += x;
	rect.y += y;
}

bool ModulePlayer::isvalid()
{
	for (int i = 0; i < 4; i++)
		if (items[i].x < 0 || items[i].x >= Cols || items[i].y >= Lines)
			return false;

		else if (field[items[i].y][items[i].x])
			return false;
	return true;
}

void ModulePlayer::gameplay()
{

	////////// backup
	for (int i = 0; i < 4; i++)
		backup[i] = items[i];
	////////// move
	if (dx)
	{
		for (int i = 0; i < 4; i++)
		{
			items[i].x += dx;
		}
		if (!isvalid())
			for (int i = 0; i < 4; i++)
				items[i] = backup[i];
	}

	///////// rotate
	if (rotate)
	{
		Point p = items[2];	// center of rotation
		for (int i = 0; i < 4; i++)
		{
			int x = items[i].y - p.y;
			int y = items[i].x - p.x;
			items[i].x = p.x - x;
			items[i].y = p.y + y;
		}
		if (!isvalid())
			for (int i = 0; i < 4; i++)
				items[i] = backup[i];
	}
	///////// tick
	if (currentTime - startTime > delay)
	{
		for (int i = 0; i < 4; i++)
			backup[i] = items[i];
		for (int i = 0; i < 4; i++)
			items[i].y++;
		if (!isvalid())
		{
			for (int i = 0; i < 4; i++)
				field[backup[i].y][backup[i].x] = color;
			nextTetrimino();
		}

		startTime = currentTime;
	}

	//////// check lines
	int k = Lines - 1;
	for (int i = k; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < Cols; j++)
		{
			if (field[i][j])
				count++;
			field[k][j] = field[i][j];
		}
		if (count < Cols)
			k--;
	}
	dx = 0;
	rotate = false;
	delay = 300;

}

update_status ModulePlayer::PostUpdate()
{
	SDL_RenderCopy(render, background, NULL, NULL);
	for (int i = 0; i < Lines; i++)
		for (int j = 0; j < Cols; j++)
			if (field[i][j])
			{
				setRectPos(srcR, field[i][j] * BlockW);
				setRectPos(destR, j * BlockW, i * BlockH);
				moveRectPos(destR, BlockW, ScreenH - (Lines + 1) * BlockH);
				SDL_RenderCopy(render, puyos, &srcR, &destR);
			}
	for (int i = 0; i < 4; i++)
	{
		setRectPos(srcR, color * BlockW);
		setRectPos(destR, items[i].x * BlockW, items[i].y * BlockH);
		moveRectPos(destR, BlockW, ScreenH - (Lines + 1) * BlockH);
		SDL_RenderCopy(render, puyos, &srcR, &destR);
	}

	SDL_RenderPresent(render);

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::clean()
{
	SDL_DestroyTexture(puyos);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(leftbackground);
	SDL_DestroyRenderer(render);
	IMG_Quit();
	SDL_Quit();
}