#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	position.x = 48;
	position.y = 16;

	// idle animation - just one sprite
	idleAnim.PushBack({ 0, rand() % 3*128, 128, 128 });
}

/*
ModulePlayer::ModulePlayer()
{
	position.x = 64;
	position.y = 16;

	// idle animation - just one sprite
	idleAnim.PushBack({ 0, 129, 128, 128 });
}

ModulePlayer::ModulePlayer()
{
	position.x = 64;
	position.y = 32;

	// idle animation - just one sprite
	idleAnim.PushBack({ 0, 129, 128, 128 });
}
*/

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/SpriteSheetPuyos.png"); // arcade version
	currentAnimation = &idleAnim;

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	if (position.y<207)
	{
	App->player->position.y += 0.5;
	}
	

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && position.x > 0)
	{
		position.x -= 16;
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && position.x<112)
	{
		position.x += 16;
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < 207)
	{
		position.y += speed;
	}

	// TODO 3: Shoot lasers when the player hits SPACE
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 10, position.y - 25, 0);
		App->particles->AddParticle(App->particles->laser, position.x + 10, position.y - 5, 0);
	}

	// Spawn explosion particles when pressing B
	if (App->input->keys[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 30);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 60);
		App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 90);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;

	currentAnimation->Update();

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, position.x, position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}