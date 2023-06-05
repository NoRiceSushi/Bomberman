#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 23

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModulePlayer;
class ModulePlayers;
class ModuleScene;
class ModuleParticles;
class ModuleRender;
class ModuleAudio;
class ModuleMenu;
class ModuleFade;
class ModuleGameOver;
class ModuleFonts;
class ModuleScore;
class ModuleLose;
class ModuleWin;
class ClearStage1;
class SceneIntro;
class IntroInfo;
class StudioNames;
class ModuleBombazo;
class ModuleTimer;
class NeoGeoIntro;


class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	update_status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually


	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;
	ModulePlayers* players = nullptr;
	ModulePlayer* player = nullptr;
	ModuleScene* scene = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleMenu* menu = nullptr;
	ModuleFade* fade = nullptr;
	ModuleGameOver* gameover = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleScore* score = nullptr;
	ModuleLose* lose = nullptr;
	ModuleWin* win = nullptr;
	ClearStage1* clearstage1 = nullptr;
	ModuleRender* render = nullptr;
	SceneIntro* sceneIntro = nullptr;
	IntroInfo* introInfo = nullptr;
	StudioNames* studio = nullptr;
	ModuleBombazo* Bombazo = nullptr;
	ModuleTimer* timer = nullptr;
	NeoGeoIntro* neogeo = nullptr;
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__