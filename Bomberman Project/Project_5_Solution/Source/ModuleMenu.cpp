#include "ModuleMenu.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_scancode.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleScene.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL.h"

#include "SDL/include/SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleMenu::ModuleMenu(bool startEnabled) : Module(startEnabled)
{
    backgroundRect = { 50,0, SCREEN_WIDTH, SCREEN_HEIGHT };
    continueRect = { 100, 70, 495, 125 };
    exitRect = { 110, y + SCREEN_HEIGHT / 2, 396, 162 };
    

}

ModuleMenu::~ModuleMenu()
{
}

bool ModuleMenu::Start()
{
    LOG("Loading menu assets");

    if (App != nullptr && App->textures != nullptr)
    {
        menuTexture = App->textures->Load("Assets/menu.png");
        continueTexture = App->textures->Load("Assets/continue.png");
        exitTexture = App->textures->Load("Assets/exit.png");
        sfx_Menu = App->audio->LoadFx("Assets/sfx/sfx_Menu.wav");
        
       

    }



    return true;
}

update_status ModuleMenu::Update()
{
    if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
    {
        App->audio->PlayFx(sfx_Menu);
        isMenuOpen = true;
        
    }

    if (App->input->keys[SDL_SCANCODE_N] == KEY_STATE::KEY_DOWN)
    {
        App->audio->PlayFx(sfx_Menu);
        isMenuOpen = false;
    }

    if (isMenuOpen)
    {
        App->render->Blit(menuTexture, x, y);

        int mouseX;
        int mouseY;


        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        SDL_Point mousePos = { mouseX, mouseY };

        isMouseOverContinue = (mousePos.x - 200 >= continueRect.x && mousePos.x - 200 < continueRect.x + continueRect.w - 125 &&
            mousePos.y - 130 >= continueRect.y && mousePos.y - 130 < continueRect.y + continueRect.h - 22);

        isMouseOverExit = (mousePos.x - 220 >= exitRect.x && mousePos.x - 220 < exitRect.x + exitRect.w - 99 &&
            mousePos.y - 223 >= exitRect.y && mousePos.y - 223 < exitRect.y + exitRect.h - 43);



        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            App->audio->PlayFx(sfx_Menu);

            LOG("siii");
            if (mousePos.x - 200 >= continueRect.x &&
                mousePos.x - 200 < continueRect.x + continueRect.w - 125 &&
                mousePos.y - 130 >= continueRect.y &&
                mousePos.y - 130 < continueRect.y + continueRect.h - 22)
            {
                LOG("Continue button clicked");
                isMenuOpen = false;

            }

            else if (mousePos.x - 200 >= exitRect.x &&
                mousePos.x - 200 < exitRect.x + exitRect.w - 99 &&
                mousePos.y - 223 >= exitRect.y &&
                mousePos.y - 223 < exitRect.y + exitRect.h - 43)
            {
                App->audio->PlayFx(sfx_Menu);
                LOG("Exit button clicked");
                return update_status::UPDATE_ERROR;
            }

        }







    }
    else
    {
        LOG("isMenuOpen is false");

    }

    return update_status::UPDATE_CONTINUE;
}

update_status ModuleMenu::PostUpdate()
{

    if (isMenuOpen)
    {
        App->render->Blit(menuTexture, x, y, nullptr);


        App->render->Blit(continueTexture, continueRect.x, continueRect.y, nullptr);


        App->render->Blit(exitTexture, exitRect.x, exitRect.y, nullptr);

        int mouseX;
        int mouseY;
        
        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        SDL_Point mousePos = { mouseX, mouseY };

        if (mousePos.x - 400 >= continueRect.x && mousePos.x - 220 < continueRect.x + continueRect.w - 125 &&
            mousePos.y - 130 >= continueRect.y && mousePos.y - 130 < continueRect.y + continueRect.h - 22)
        {
           
            // Crear un objeto SDL_Rect para el rectángulo amarillo
            SDL_Rect highlightRect = { 99,70,125,33 };

            // Dibujar el rectángulo amarillo
            App->render->DrawRectangle(highlightRect, 255, 255, 0, 255);
            
           
        }

        if (mousePos.x - 220 >= exitRect.x && mousePos.x - 220 < exitRect.x + exitRect.w - 99 &&
            mousePos.y - 223 >= exitRect.y && mousePos.y - 223 < exitRect.y + exitRect.h - 43)
        {
            
            // Crear un objeto SDL_Rect para el rectángulo amarillo
            SDL_Rect highlightRect = { 109,111,100,41 };

            // Dibujar el rectángulo amarillo
            App->render->DrawRectangle(highlightRect, 255, 255, 0, 255);
            
            
        }

    }

    return update_status::UPDATE_CONTINUE;
}

bool ModuleMenu::CleanUp()
{
    return true;
}