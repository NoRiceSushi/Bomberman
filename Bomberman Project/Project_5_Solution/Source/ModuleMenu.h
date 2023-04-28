#ifndef __MODULE_MENU_H__
#define __MODULE_MENU_H__

#include "Module.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class ModuleMenu : public Module
{
public:
	ModuleMenu(bool startEnabled);
	~ModuleMenu();

	bool Start() override;
	update_status Update() override;
	update_status PostUpdate() override;
	bool CleanUp() override;

public:
	fPoint position;

	
	SDL_Texture* menuTexture = nullptr;

	
	bool isMenuOpen = false;

	
	int x;
	int y;
	int menuLayer = 0;


	SDL_Texture* continueTexture = nullptr;
	SDL_Texture* exitTexture = nullptr;
	

	SDL_Texture* continueHighlightedTexture = nullptr;
	SDL_Texture* exitHighlightedTexture = nullptr;

	SDL_Rect backgroundRect;
	SDL_Rect continueRect;
	SDL_Rect exitRect;



	bool isMouseOverContinue = false;
	bool isMouseOverExit = false;

};

#endif // __MODULE_MENU_H__