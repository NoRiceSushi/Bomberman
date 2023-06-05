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
#include "ModuleScene.h"
#include "ModuleParticles.h"

int contador = 0;

ModulePlayers::ModulePlayers(bool startEnabled) : Module(startEnabled)
{
    if (contador != 10)
    {
        for (uint i = 0; i < MAX_PLAYERS; ++i)
        {
            players[i] = nullptr;

        }
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
    

    animaciones = 0;

    return true;
}

update_status ModulePlayers::Update()
{
    HandleEnemiesSpawn();

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            players[i]->Update();


        }

    }

    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            if (players[i]->p[0].active == false && players[i]->p[1].active == false && players[i]->p[2].active == false)
            {
                for (int a = 0; a < 12; a++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (App->scene->map[a][j] == 'Z')
                        {

                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; s++)
                                    {


                                        if (players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color == 'X' && App->scene->map[a][j] == 'Z' && players[n]->p[s].active == false || players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].color == 'X' && App->scene->map[a][j] == 'Z' && players[n]->p[s].active == false)
                                        {

                                            players[n]->p[s] = {};
                                            App->scene->map[a][j] = '0';
                                        }
                                        if (players[n]->p[s].color == 'Z')
                                        {
                                            players[n]->p[s] = {};
                                            App->scene->map[a][j] = '0';
                                        }


                                        
                                    }
                                }
                            }
                            


                        }

                        if (App->scene->map[a][j] == App->scene->map[a][j + 1] && App->scene->map[a][j] == App->scene->map[a][j + 2] && j < 7 && App->scene->map[a][j] != '0' && App->scene->map[a][j] != 'X' && App->scene->map[a][j] != 'Z')
                        {
                            App->scene->map[a][j] = '0';
                            App->scene->map[a][j + 1] = '0';
                            App->scene->map[a][j + 2] = '0';

                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; s++)
                                    {
                                        if ((players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].currentAnimation != nullptr) ||
                                            (players[n]->p[s].position.x == ((j + 1) * 16) + 25 && players[n]->p[s].position.y == ((a) * 16) + 32 && players[n]->p[s].currentAnimation != nullptr) ||
                                            (players[n]->p[s].position.x == ((j + 2) * 16) + 25 && players[n]->p[s].position.y == ((a) * 16) + 32 && players[n]->p[s].currentAnimation != nullptr))
                                        {
                                            outAnim(players[n]->p[s].position.x, players[n]->p[s].position.y-16, players[n]->p[s].color);
                                            Particle* newParticle = App->particles->AddParticle(App->particles->Star, players[n]->p[s].position.x-8, players[n]->p[s].position.y -24);
                                            players[n]->p[s] = {};
                                            App->score->score += 50;

                                        }
                                    }
                                }

                            }

                            for (a; a > 0; a--)
                            {
                                App->scene->map[a][j] = App->scene->map[a - 1][j];
                                App->scene->map[a][j+1] = App->scene->map[a - 1][j+1];
                                App->scene->map[a][j+2] = App->scene->map[a - 1][j+2];
                            }



                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; s++)
                                    {
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].currentAnimation != nullptr || players[n]->p[s].position.x == ((j + 1) * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].currentAnimation != nullptr || players[n]->p[s].position.x == ((j + 2) * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].currentAnimation != nullptr)
                                        {
                                        
                                            for (a; a > 0; a--)
                                            {
                                                players[n]->p[s].position.y +=16;
                                            }
                                        }
                                    }
                                }

                            }
                            

                           

                            

                        }
                        /*if (a < 12 && App->scene->map[a][j] == App->scene->map[a + 1][j] && App->scene->map[a][j] == App->scene->map[a + 2][j] && App->scene->map[a][j] != '0')
                        {
                            App->scene->map[a][j] = '0';
                            App->scene->map[a + 1][j] = '0';
                            App->scene->map[a + 2][j] = '0';

                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; s++)
                                    {
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 || players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == ((a+1) * 16) + 32 || players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == ((a+2) * 16) + 32)
                                        {
                                            outAnim(players[n]->p[s].position.x, players[n]->p[s].position.y-16, players[n]->p[s].color);
                                            Particle* newParticle = App->particles->AddParticle(App->particles->Star, players[n]->p[s].position.x - 8, players[n]->p[s].position.y - 24);
                                            players[n]->p[s].currentAnimation = nullptr;
                                            App->score->score += 50;
                                        }
                                    }
                                }

                            }

                            for (a; a < 12; a++)
                            {
                                App->scene->map[a][j] = App->scene->map[a + 3][j];
                            }
                        }*/
                       
                    }
                }
            }
        }
    }
    for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            if (players[i]->p[0].active == false && players[i]->p[1].active == false && players[i]->p[2].active == false)
            {
                for (int a = 0; a < 12; a++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((App->scene->map[a][j] == App->scene->map[a + 1][j] && App->scene->map[a][j] == App->scene->map[a + 2][j] && a < 12 && App->scene->map[a][j] != '0' && App->scene->map[a][j] != 'X'))
                        {

                            App->scene->map[a][j] = '0';
                            App->scene->map[a + 1][j] = '0';
                            App->scene->map[a + 2][j] = '0';
                            
                            /*for (a; a > 3; a--)
                            {
                                App->scene->map[a][j] = App->scene->map[a - 3][j];
                            }*/

                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; ++s)
                                    {
                                        if ((players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].currentAnimation != nullptr) ||
                                            (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == ((a + 1) * 16) + 32 && players[n]->p[s].currentAnimation != nullptr) ||
                                            (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == ((a + 2) * 16) + 32 && players[n]->p[s].currentAnimation != nullptr))
                                        {
                                            outAnim(players[n]->p[s].position.x, players[n]->p[s].position.y - 16, players[n]->p[s].color);
                                            Particle* newParticle = App->particles->AddParticle(App->particles->Star, players[n]->p[s].position.x - 8, players[n]->p[s].position.y - 24);
                                            players[n]->p[s] = {};
                                            App->score->score += 50;

                                            
                                        }
                                    }
                                }
                            }

                            
                        }

                    }
                }
            }
        }
    }
    int randomplayer = rand() % 10;
    if (players[randomplayer] != nullptr) {
        if (players[randomplayer]->p[0].active==false && players[randomplayer]->p[0].color=='B' && players[randomplayer]->p[0].currentAnimation!= &players[randomplayer]->p[0].WhiteidleAnim)
        {
            players[randomplayer]->p[0].currentAnimation = &players[randomplayer]->p[0].WhiteidleAnim;
        }
        if (players[randomplayer]->p[0].active == false && players[randomplayer]->p[0].color == 'N' && players[randomplayer]->p[0].currentAnimation != &players[randomplayer]->p[0].BlackidleAnim)
        {
            players[randomplayer]->p[0].currentAnimation = &players[randomplayer]->p[0].BlackidleAnim;
        }
        if (players[randomplayer]->p[0].active == false && players[randomplayer]->p[0].color == 'A' && players[randomplayer]->p[0].currentAnimation != &players[randomplayer]->p[0].BlueidleAnim)
        {
            players[randomplayer]->p[0].currentAnimation = &players[randomplayer]->p[0].BlueidleAnim;
        }
        if (players[randomplayer]->p[0].active == false && players[randomplayer]->p[0].color == 'R' && players[randomplayer]->p[0].currentAnimation != &players[randomplayer]->p[0].RedidleAnim)
        {
            players[randomplayer]->p[0].currentAnimation = &players[randomplayer]->p[0].RedidleAnim;
        }
        if (players[randomplayer]->p[0].active == false && players[randomplayer]->p[0].color == 'V' && players[randomplayer]->p[0].currentAnimation != &players[randomplayer]->p[0].GreenidleAnim)
        {
            players[randomplayer]->p[0].currentAnimation = &players[randomplayer]->p[0].GreenidleAnim;
        }
    }
    

    /*for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {

            if (players[i]->p[0].active == false && players[i]->p[1].active == false && players[i]->p[2].active == false)
            {
                for (int a = 0; a < 12; a++)
                {
                   /* for (int j = 0; j < 8; j++)
                    {
                        if (App->scene->map[a][j] != '0' && App->scene->map[a][j] != 'X')
                        {

                            for (uint n = 0; n < MAX_PLAYERS; ++n)
                            {
                                if (players[n] != nullptr)
                                {
                                    for (int s = 0; s < 3; ++s)
                                    {
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color=='B'){
                                            players[n]->p[s].currentAnimation = &players[n]->p[s].WhiteidleAnim;
                                        }
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color == 'N') {
                                            players[n]->p[s].currentAnimation = &players[n]->p[s].BlackidleAnim;
                                        }
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color == 'R') {
                                            players[n]->p[s].currentAnimation = &players[n]->p[s].RedidleAnim;
                                        }
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color == 'A') {
                                            players[n]->p[s].currentAnimation = &players[n]->p[s].BlueidleAnim;
                                        }
                                        if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == (a * 16) + 32 && players[n]->p[s].color == 'V') {
                                            players[n]->p[s].currentAnimation = &players[n]->p[s].GreenidleAnim;
                                        }
                                    }
                                }
                            }

                        }

                    }*/
    //            }
    //        }
    //    }
    //}*/


    if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
    {
        for (uint i = 0; i < MAX_PLAYERS; ++i)
        {
            if (players[i] != nullptr)
            {
                delete players[i];
                players[i] = nullptr;
            }
        }
    }
        
    /*for (uint i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i] != nullptr)
        {
            for (int a = 0; a < 12; a++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (App->scene->map[a][j] == '0' && App->scene->map[a+1][j] != '0')
                    {

                        for (uint n = 0; n < MAX_PLAYERS; ++n)
                        {
                            if (players[n] != nullptr)
                            {
                                for (int s = 0; s < 3; ++s)
                                {
                                    if (players[n]->p[s].position.x == (j * 16) + 25 && players[n]->p[s].position.y == ((a+1) * 16) + 32 && players[n]->p[s].active == false)
                                    {
                                        players[n]->p[s].position.y = (a * 16) + 32;
                                    }
                                    
                                        

                                }
                            }
                        }
                    }
                }
            }
        }
    }*/


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
                    //LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

                    SpawnEnemy(spawnQueue[i]);
                    // Removing the newly spawned enemy from the queue
                }


            }
        }
    

    
    {
        for (uint i = 0; i < MAX_BOMBAZOS; ++i)
        {

            {

                // Spawn a new enemy if the screen has reached a spawn position

                {
                    //LOG("Spawning enemy at %d", spawnQueue2[i].x * SCREEN_SIZE);

                    SpawnEnemy(spawnQueue2[i]);
                    // Removing the newly spawned enemy from the queue
                }


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

                    contador++;
                }
                else
                {
                    if (players[i - 1]->p[0].active == false && players[i - 1]->p[1].active == false && players[i - 1]->p[2].active == false)
                    {
                        players[i] = new ModulePlayer(true); // use new constructor with boolean parameter

                        players[i]->texture = texture;

                        contador++;
                    }
                }
                break;


            }

        }
    
}


void ModulePlayers::outAnim(int x,int y,char color) {
    if (color == 'B')
    {
        Particle* newParticle = App->particles->AddParticle(App->particles->WhiteOutAnim, x, y);
    }
    if (color == 'A')
    {
        Particle* newParticle = App->particles->AddParticle(App->particles->BlueOutAnim, x, y);
    }
    if (color == 'R')
    {
        Particle* newParticle = App->particles->AddParticle(App->particles->RedOutAnim, x, y);
    }
    if (color == 'N')
    {
        Particle* newParticle = App->particles->AddParticle(App->particles->BlackOutAnim, x, y);
    }
    if (color == 'V')
    {
        Particle* newParticle = App->particles->AddParticle(App->particles->GreenOutAnim, x, y);
    }
    
}