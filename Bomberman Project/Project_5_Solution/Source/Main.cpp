#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#define fps 60

enum class main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;

int main(int argc, char* argv[])
{
	ReportMemoryLeaks();

	int main_return = EXIT_FAILURE;
	main_states state = main_states::MAIN_CREATION;

	while (state != main_states::MAIN_EXIT)
	{
		if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
		{
			update_status::UPDATE_STOP;
		}
		switch (state)
		{
		case main_states::MAIN_CREATION:
		{
			LOG("Application Creation --------------\n");
			App = new Application();
			state = main_states::MAIN_START;
		}	break;

		case main_states::MAIN_START:
		{
			LOG("Application Start --------------\n");
			if (App->Init() == false)
			{
				LOG("Application Init exits with error -----\n");
				state = main_states::MAIN_EXIT;
			}
			else
			{
				state = main_states::MAIN_UPDATE;
			}
		}	break;

		case main_states::MAIN_UPDATE:
		{
			update_status status = App->Update();

			if (status == update_status::UPDATE_ERROR)
			{
				LOG("Application Update exits with error -----\n");
				state = main_states::MAIN_EXIT;
			}
			else if (status == update_status::UPDATE_STOP)
			{

				LOG("Restarting Application --------------\n");
				if (App->CleanUp() == true)
				{
					delete App;
					App = new Application();
					state = main_states::MAIN_START;
				}
				else
				{
					LOG("Application CleanUp exits with error -----\n");
					state = main_states::MAIN_EXIT;
				}
			}
		}	break;

		case main_states::MAIN_FINISH:
		{
			LOG("Application Finish --------------\n");
			if (App->CleanUp() == true)
			{
				main_return = EXIT_SUCCESS;
			}
			else
			{
				LOG("Application CleanUp exits with error -----\n");
			}
			state = main_states::MAIN_EXIT;
		}
		}
	}

	//Uint32 starting_tick; //Frame rate cap

	//bool running = true;
	//while (running) {
	//	starting_tick = SDL_GetTicks();
	//	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
	//		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	//	}
	//}

	LOG("\nBye :)\n");

	return main_return;
}