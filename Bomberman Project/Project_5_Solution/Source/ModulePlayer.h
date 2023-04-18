#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"

#include <string>

struct SDL_Texture;

class ModulePlayer : public Module
{
public:

	ModulePlayer();

	~ModulePlayer();

	void setCurrentTime(Uint32 t)
	{
		currentTime = t;
	}

	bool isrunning()
	{
		return running;
	}

	bool Start() override;
	bool isvalid();

	update_status Update() override;
	update_status PostUpdate() override;

	void setRectPos(SDL_Rect& rect, int x = 0, int y = 0, int w = BlockW, int h = BlockH);
	void moveRectPos(SDL_Rect& rect, int x, int y);


	void nextTetrimino();
	void gameplay();
	void updateRender();
	void clean();

public:

	int speed = 1;
	bool down = true;

	int ACT_PUYOS = 0;
	int MAX_PUYOS=100;

	SDL_Texture* texture = nullptr;
	
	Animation* currentAnimation = nullptr;
	Animation idleAnim;
	Animation ESPACIO_ANIMACION; /*Hacer este tipo de declaraciones para meter una animación en el player*/

private:

	enum { ScreenW = 320, ScreenH = 224 };
	enum { BlockW = 16, BlockH = 16 };
	enum { Lines = 12, Cols = 8 };

	SDL_Window* window = NULL;
	SDL_Renderer* render = NULL;
	SDL_Texture* background = NULL, * puyos = NULL, * leftbackground = NULL;
	SDL_Rect srcR = { 0, 0, BlockW, BlockH }, destR = { 0, 0, BlockW, BlockH };

	bool running = false;
	int field[Lines][Cols] = { 0 };
	static const int figures[4];

	struct Point
	{
		int x, y;
	} items[4], backup[4];

	int color = 1;
	int dx = 0;
	bool rotate = false;
	unsigned int delay = 300;

	Uint32 startTime = 0, currentTime = 0;
};

#endif //!__MODULE_PLAYER_H__
