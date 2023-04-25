#include "ModulePlayers.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"


ModulePlayers::ModulePlayers()
{
    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        players[i] = nullptr;

    }

}

ModulePlayers::~ModulePlayers()
{
}

bool ModulePlayers::Start()
{
    LOG("Loading players textures");

    texture = App->textures->Load("Assets/SpriteSheetPuyos.png");

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            players[i]->Start();
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
}

void ModulePlayers::SpawnEnemy(const EnemySpawnpoint& info)
{

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] == nullptr)
        {
            if (players[i] == players[0])
            {
                players[i] = new ModulePlayer(info.x, info.y);

                players[i]->texture = texture;
            }
            else
            {
                if (players[i - 1]->p[0].position.y >= 208 || players[i - 1]->p[1].position.y >= 208)
                {
                    players[i] = new ModulePlayer(info.x, info.y);

                    players[i]->texture = texture;
                }

            }


            break;
        }
    }
}