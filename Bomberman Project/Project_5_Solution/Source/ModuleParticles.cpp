#include "ModuleParticles.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{

}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	texture = App->textures->Load("Assets/Sprite/SpriteSheetPuyos+Bomb.png");
	float animspeed = 1;
	// Explosion particle
	explosion.anim.PushBack({274, 296, 33, 30});
	explosion.anim.PushBack({313, 296, 33, 30});
	explosion.anim.PushBack({346, 296, 33, 30});
	explosion.anim.PushBack({382, 296, 33, 30});
	explosion.anim.PushBack({419, 296, 33, 30});
	explosion.anim.PushBack({457, 296, 33, 30});
	explosion.anim.loop = false;
	explosion.anim.speed = 0.3f;

	// TODO 2:	Create the template for a new particle "laser"
	//			Remember: not all the code goes here!
	//			Follow the example with the "explosion" particle
	laser.anim.PushBack({ 104, 171, 80, 14 });
	laser.anim.PushBack({ 185, 170, 80, 16 });
	laser.speed = iPoint(5, 0);
	laser.lifetime = 
	laser.anim.speed = 0.3f;

	//white puyo out anim
	WhiteOutAnim.anim.PushBack({ 0,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 16,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 32,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 48,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 64,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 80,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 96,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 112,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 128,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 144,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 160,352,16,16 });
	WhiteOutAnim.anim.PushBack({ 176,352,16,16 });
	WhiteOutAnim.anim.speed = animspeed;
	WhiteOutAnim.anim.loop = false;

	//red puyo out anim
	RedOutAnim.anim.PushBack({ 0,368,16,16 });
	RedOutAnim.anim.PushBack({ 16,368,16,16 });
	RedOutAnim.anim.PushBack({ 32,368,16,16 });
	RedOutAnim.anim.PushBack({ 48,368,16,16 });
	RedOutAnim.anim.PushBack({ 64,368,16,16 });
	RedOutAnim.anim.PushBack({ 80,368,16,16 });
	RedOutAnim.anim.PushBack({ 96,368,16,16 });
	RedOutAnim.anim.PushBack({ 112,368,16,16 });
	RedOutAnim.anim.PushBack({ 128,368,16,16 });
	RedOutAnim.anim.PushBack({ 144,368,16,16 });
	RedOutAnim.anim.PushBack({ 160,368,16,16 });
	RedOutAnim.anim.PushBack({ 176,368,16,16 });
	RedOutAnim.anim.speed = animspeed;
	RedOutAnim.anim.loop = false;

	//blue puyo out anim
	BlueOutAnim.anim.PushBack({ 0,383,16,16 });
	BlueOutAnim.anim.PushBack({ 16,383,16,16 });
	BlueOutAnim.anim.PushBack({ 32,383,16,16 });
	BlueOutAnim.anim.PushBack({ 48,383,16,16 });
	BlueOutAnim.anim.PushBack({ 64,383,16,16 });
	BlueOutAnim.anim.PushBack({ 80,383,16,16 });
	BlueOutAnim.anim.PushBack({ 96,383,16,16 });
	BlueOutAnim.anim.PushBack({ 112,383,16,16 });
	BlueOutAnim.anim.PushBack({ 128,383,16,16 });
	BlueOutAnim.anim.PushBack({ 144,383,16,16 });
	BlueOutAnim.anim.PushBack({ 160,383,16,16 });
	BlueOutAnim.anim.PushBack({ 176,383,16,16 });
	BlueOutAnim.anim.speed = animspeed;
	BlueOutAnim.anim.loop = false;

	//black puyo out anim
	BlackOutAnim.anim.PushBack({ 0,398,16,16 });
	BlackOutAnim.anim.PushBack({ 16,398,16,16 });
	BlackOutAnim.anim.PushBack({ 32,398,16,16 });
	BlackOutAnim.anim.PushBack({ 48,398,16,16 });
	BlackOutAnim.anim.PushBack({ 64,398,16,16 });
	BlackOutAnim.anim.PushBack({ 80,398,16,16 });
	BlackOutAnim.anim.PushBack({ 96,398,16,16 });
	BlackOutAnim.anim.PushBack({ 112,398,16,16 });
	BlackOutAnim.anim.PushBack({ 128,398,16,16 });
	BlackOutAnim.anim.PushBack({ 144,398,16,16 });
	BlackOutAnim.anim.PushBack({ 160,398,16,16 });
	BlackOutAnim.anim.PushBack({ 176,398,16,16 });
	BlackOutAnim.anim.speed = animspeed;
	BlackOutAnim.anim.loop = false;

	//green puyo out anim
	GreenOutAnim.anim.PushBack({ 0,413,16,16 });
	GreenOutAnim.anim.PushBack({ 16,413,16,16 });
	GreenOutAnim.anim.PushBack({ 32,413,16,16 });
	GreenOutAnim.anim.PushBack({ 48,413,16,16 });
	GreenOutAnim.anim.PushBack({ 64,413,16,16 });
	GreenOutAnim.anim.PushBack({ 80,413,16,16 });
	GreenOutAnim.anim.PushBack({ 96,413,16,16 });
	GreenOutAnim.anim.PushBack({ 112,413,16,16 });
	GreenOutAnim.anim.PushBack({ 128,413,16,16 });
	GreenOutAnim.anim.PushBack({ 144,413,16,16 });
	GreenOutAnim.anim.PushBack({ 160,413,16,16 });
	GreenOutAnim.anim.PushBack({ 176,413,16,16 });
	GreenOutAnim.anim.speed = animspeed;
	GreenOutAnim.anim.loop = false;

	//star anim
	Star.anim.PushBack({ 0,428,32,32 });
	Star.anim.PushBack({ 32,428,32,32 });
	Star.anim.PushBack({ 64,428,32,32 });
	Star.anim.PushBack({ 96,428,32,32 });
	Star.anim.PushBack({ 128,428,32,32 });
	Star.anim.speed = 0.2;
	Star.anim.loop = false;

	return true;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(particles[i] != nullptr)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}

update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if(particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if(particle->Update() == false)
		{
			delete particle;
			particles[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleParticles::PostUpdate()
{
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive)
		{
			App->render->Blit(texture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
		}
	}

	return update_status::UPDATE_CONTINUE;
}

Particle* ModuleParticles::AddParticle(const Particle& particle, int x, int y)
{
	Particle* newParticle = new Particle(particle);
	
	//p->frameCount = -(int)delay;			// We start the frameCount as the negative delay
	newParticle->position.x = x;						// so when frameCount reaches 0 the particle will be activated
	newParticle->position.y = y;

	particles[lastParticle++] = newParticle;
	lastParticle %= MAX_ACTIVE_PARTICLES;

	return newParticle;
}