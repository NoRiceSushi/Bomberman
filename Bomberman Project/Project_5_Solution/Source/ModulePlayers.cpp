#include "ModulePlayers.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleBombazo.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleScore.h"
#include "SDL/include/SDL_scancode.h"

ModulePlayers::ModulePlayers(bool startEnabled) : Module(startEnabled)
{
    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        players[i] = nullptr;

    }

    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        bombazo[i] = nullptr;

    }
}

ModulePlayers::~ModulePlayers()
{
}

bool ModulePlayers::Start()
{
    LOG("Loading players textures");

    texture = App->textures->Load("Assets/SpriteSheetPuyos.png");
    texture = App->textures->Load("Assets/SpriteSheetPuyos.png");

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            players[i]->Start();

        }

    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        if (bombazo[i] != nullptr)
        {

            bombazo[i]->Start();

        }

    }



    return true;
}

update_status ModulePlayers::Update()
{
    HandleEnemiesSpawn();


    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {
            LOG("siiiii");
            players[i]->Update();
        }

    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        if (bombazo[i] != nullptr)
        {

            bombazo[i]->Update();
        }

    }



    return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayers::PostUpdate()
{

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {
            players[i]->PostUpdate();
        }


    }

    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        if (bombazo[i] != nullptr)
        {
            bombazo[i]->PostUpdate();
        }


    }
    return update_status::UPDATE_CONTINUE;
}

bool ModulePlayers::CleanUp()
{
    LOG("Freeing all enemies");

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {
            delete players[i];
            players[i] = nullptr;
        }
    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        if (bombazo[i] != nullptr)
        {
            delete bombazo[i];
            bombazo[i] = nullptr;
        }
    }

    return true;
}

bool ModulePlayers::AddEnemy(int x, int y)
{
    bool ret = false;

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        {
            spawnQueue[i].x = x;
            spawnQueue[i].y = y;
            ret = true;
            break;
        }
    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        {
            spawnQueue2[i].x = x;
            spawnQueue2[i].y = y;
            ret = true;
            break;
        }
    }

    return ret;
}

void ModulePlayers::HandleEnemiesSpawn()
{
    // Iterate all the enemies queue
    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {

        {

            // Spawn a new enemy if the screen has reached a spawn position

            {
                LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

                SpawnEnemy(spawnQueue[i]);
                // Removing the newly spawned enemy from the queue
            }


        }
    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {

        {

            // Spawn a new enemy if the screen has reached a spawn position

            {
                LOG("Spawning enemy at %d", spawnQueue2[i].x * SCREEN_SIZE);

                SpawnEnemy(spawnQueue2[i]);
                // Removing the newly spawned enemy from the queue
            }


        }
    }
}

void ModulePlayers::SpawnEnemy(const EnemySpawnpoint& info)
{
    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] == nullptr)
        {
            if (players[i] == players[0])
            {
                players[i] = new ModulePlayer(true); // use new constructor with boolean parameter

                players[i]->texture = texture;
            }
            else
            {
                if (players[i - 1]->p[0].active == false && players[i - 1]->p[1].active == false && players[i - 1]->p[2].active == false)
                {
                    players[i] = new ModulePlayer(true); // use new constructor with boolean parameter

                    players[i]->texture = texture;
                }
            }

            break;
        }
    }
    for (uint i = 0; i < MAX_BOMBAZOS; ++i)
    {
        if (bombazo[i] == nullptr && players[i] == nullptr)
        {
            if (players[i] == players[0])
            {
                players[i] = new ModulePlayer(true); // use new constructor with boolean parameter

                players[i]->texture = texture;
            }

            else
            {
                {


                    if ((App->score->coins == 5) && players[i - 1]->p[0].active == false && players[i - 1]->p[1].active == false && players[i - 1]->p[2].active == false)
                    {



                        if (bombazo[i] == bombazo[0])
                        {
                            bombazo[i] = new ModuleBombazo(true); // use new constructor with boolean parameter

                            bombazo[i]->texture = texture;
                        }
                        else
                        {

                            {
                                bombazo[i] = new ModuleBombazo(true); // use new constructor with boolean parameter

                                bombazo[i]->texture = texture;
                            }
                        }
                    }

                }

            }

        }
    }
}