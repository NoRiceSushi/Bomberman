#include "ModuleMenu.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_scancode.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleScene.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

ModuleMenu::ModuleMenu() : isMenuOpen(false)
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

    }



    return true;
}

update_status ModuleMenu::Update()
{
    if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
    {
        isMenuOpen = true;
    }

    if (App->input->keys[SDL_SCANCODE_N] == KEY_STATE::KEY_DOWN)
    {
        isMenuOpen = false;
    }

    if (isMenuOpen)
    {
        App->render->Blit(menuTexture, x, y);

        int mouseX;
        int mouseY;


        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        SDL_Point mousePos = { mouseX, mouseY };





        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
        {


            LOG("siii");
            if (mousePos.x - 300 >= continueRect.x &&
                mousePos.x - 300 < continueRect.x + continueRect.w &&
                mousePos.y - 212 >= continueRect.y &&
                mousePos.y - 212 < continueRect.y + continueRect.h)
            {
                LOG("Continue button clicked");
                isMenuOpen = false;

            }

            else if (mousePos.x - 329 >= exitRect.x &&
                mousePos.x - 329 < exitRect.x + exitRect.w &&
                mousePos.y - 335 >= exitRect.y &&
                mousePos.y - 335 < exitRect.y + exitRect.h)
            {
                LOG("Exit button clicked");
                return update_status::UPDATE_STOP;
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

    }

    return update_status::UPDATE_CONTINUE;
}

bool ModuleMenu::CleanUp()
{
    return true;
}