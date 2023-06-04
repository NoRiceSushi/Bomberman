#ifndef __MODULE_PLAYERS_H__
#define __MODULE_PLAYERS_H__

#include "Module.h"
#include "ModulePlayer.h"
#include "Animation.h"

#define MAX_PLAYERS 200
#define MAX_BOMBAZOS 20

struct SDL_Texture;

class ModulePlayer;
class ModuleBombazo;
struct EnemySpawnpoint
{
    int x = 48 + 25;
    int y = 32;
};
class ModulePlayers : public Module
{
public:
    // Constructor
    ModulePlayers(bool startEnabled);

    // Destructor
    ~ModulePlayers();

    // Called when the module is activated
    // Loads the necessary textures for the players
    bool Start() override;

    // Called at the middle of the application loop
    // Processes new input and handles players movement
    update_status Update() override;

    // Called at the end of the application loop
    // Performs the render call of the players sprites
    update_status PostUpdate() override;

    bool CleanUp() override;

    void HandleEnemiesSpawn();

    bool AddEnemy(int x, int y);

    SDL_Texture* texture = nullptr;

    fPoint position[5];

    Animation* currentAnimation = nullptr;

    Animation idleAnim;
    Animation upAnim;
    Animation downAnim;

    void SpawnEnemy(const EnemySpawnpoint& info);

    int enemyDestroyedFx = 0;

    void outAnim(int x, int y,char color);




private:

    EnemySpawnpoint spawnQueue[MAX_PLAYERS];

    EnemySpawnpoint spawnQueue2[MAX_BOMBAZOS];

    ModulePlayer* players[MAX_PLAYERS] = { nullptr };
    ModuleBombazo* bombazo[MAX_BOMBAZOS] = { nullptr };
};

#endif // !__MODULE_PLAYERS_H__