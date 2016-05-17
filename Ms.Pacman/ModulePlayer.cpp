#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleLevelOne.h"
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	
	position.x = 208;
	position.y = 408;
	// idle animation (arcade sprite sheet)
	idle.PushBack({ 32, 32, 32, 32}); 


	// Right
	right.PushBack({ 32, 32, 32, 32 });
	right.PushBack({ 64, 32, 32, 32 });
	right.PushBack({ 96, 32, 32, 32 });
	right.speed = 0.15f;

	// Left
	left.PushBack({ 192, 0, 32, 32 });
	left.PushBack({ 224, 0, 32, 32 });
	left.PushBack({ 0, 32, 32, 32 });
	
	left.speed = 0.15f;

	// Up
	up.PushBack({ 0, 0, 32, 32 });
	up.PushBack({ 32, 0, 32, 32 });
	up.PushBack({ 64, 0, 32, 32 });
	up.speed = 0.15f;

	//Down
	down.PushBack({ 96, 0, 32, 32 });
	down.PushBack({ 128, 0, 32, 32 });
	down.PushBack({ 160, 0, 32, 32 });
	down.speed = 0.15f;

	//God UP
	g_up.PushBack({ 0, 256, 32, 32 });
	g_up.PushBack({ 32, 256, 32, 32 });
	g_up.PushBack({ 64, 256, 32, 32 });
	g_up.PushBack({ 96, 256, 32, 32 });
	g_up.PushBack({ 128, 256, 32, 32 });
	g_up.PushBack({ 160, 256, 32, 32 });
	g_up.speed = 0.15f;

	//GOD left
	g_left.PushBack({ 0, 288, 32, 32 });
	g_left.PushBack({ 32, 288, 32, 32 });
	g_left.PushBack({ 64, 288, 32, 32 });
	g_left.PushBack({ 96, 288, 32, 32 });
	g_left.PushBack({ 128, 288, 32, 32 });
	g_left.PushBack({ 160, 288, 32, 32 });
	g_left.speed = 0.15f;

	//GOD down

	g_down.PushBack({ 0, 320, 32, 32 });
	g_down.PushBack({ 32, 320, 32, 32 });
	g_down.PushBack({ 64, 320, 32, 32 });
	g_down.PushBack({ 96, 320, 32, 32 });
	g_down.PushBack({ 128, 320, 32, 32 });
	g_down.PushBack({ 160, 320, 32, 32 });
	g_down.speed = 0.15f;


	//GOD right


	g_right.PushBack({ 0, 352, 32, 32 });
	g_right.PushBack({ 32, 352, 32, 32 });
	g_right.PushBack({ 64, 352, 32, 32 });
	g_right.PushBack({ 96, 352, 32, 32 });
	g_right.PushBack({ 128, 352, 32, 32 });
	g_right.PushBack({ 160, 352, 32, 32 });
	g_right.speed = 0.15f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	unsigned int time = SDL_GetTicks();
	destroyed = false;
	position.x = 208;

	position.y = 408;
	
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("characters.png");
	// arcade version



	col = App->collision->AddCollider({position.x+ 8, position.y + 8, 16, 16 }, COLLIDER_PLAYER, this);
	
	return ret;
}
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	//App->textures->Unload(graphics);
	App->collision->EraseCollider(col);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;
	bool colision = false;
	float speed = 2;
	static int direction = -1;
	int position_x = position.x;
	int position_y = position.y;
	static int dir = 1;
	static int s_dir = 1;
	int tilepos_x = ((position_x + 16) / 16) * 16;
	int tilepos_y = ((position_y + 16) / 16) * 16;
	
	App->input;


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1)
	{
		s_dir= 0;
		
	}
	if (dir == 0){
		current_animation = &right;

	}


	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1)
	{
		s_dir= 1;
	
	}
	if (dir == 1){
		current_animation = &left;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == 1)
	{
		s_dir = 2;
	
		

	}
	if (dir == 2){
		current_animation = &up;
	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1)
	{
		s_dir = 3;
	}	

	if (dir == 3){
		current_animation = &down;
		
	}

	if (dir == 0 && s_dir == 1){
		dir = s_dir;
	}
	if (dir == 1 && s_dir == 0){
		dir = s_dir;
	}
	if (dir == 2 && s_dir == 3){
		dir = s_dir;
	}
	if (dir == 3 && s_dir == 2){
		dir = s_dir;
	}

	if (App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] == -1 || App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] == -2){
		if (s_dir == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) + 1] != 2){
			dir = s_dir;

		}
		if (s_dir == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) - 1] != 2){
			dir = s_dir;

		}
		if (s_dir == 2 && App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] != 2){
			dir = s_dir;

		}
		if (s_dir == 3 && App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] != 2){
			dir = s_dir;

		}

	}
	if (god == true){
		if (dir == 0){
			current_animation = &g_right;
			
		}
		if (dir == 1){
			current_animation = &g_left;
			
		}
		if (dir == 2){
			current_animation = &g_up;
			
		}
		if (dir == 3){
			current_animation = &g_down;
		
		}
	}



	// Collider--------------

	

	col->SetPos(tilepos_x, tilepos_y);

	
	if (dir == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] < 2){

		position_x = position_x + speed;
		position.x = position_x;
		position.y = (position_y / 16) * 16 + 8;
	}
	if (dir == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] < 2){

		position_x = position_x - speed;
		position.x = position_x;
		position.y = (position_y / 16) * 16 + 8;

	}
	if (dir == 2 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] < 2){

		position_y = position_y - speed;
		position.y = position_y;
		position.x = (position_x / 16) * 16 + 8;
	}
	if (dir== 3 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] < 2){

		position_y = position_y + speed;
		position.y = position_y;
		position.x = (position_x / 16) * 16 + 8;
	}


	if (dir == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) + 1] >= 2){

		position_x = position_x - speed;
		position.x = (position_x / 16) * 16 +8;
		position.y = (position_y / 16) * 16 + 8;
		
		
	}


	if (dir == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) - 1] >= 2){

		position_x = position_x + speed;
		position.x = (position_x / 16) * 16 + 8;
		position.y = (position_y / 16) * 16 + 8;
	}
			
	
	if (dir == 2 && App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] >= 2){

			position_y = position_y + speed;
			position.y = (position_y / 16) * 16 + 8;
			position.x = (position_x / 16) * 16 + 8;
			
			
		}

	if (dir == 3 && App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] >= 2){
		position_y = position_y - speed;
		position.y = (position_y / 16) * 16 + 8;
		position.x = (position_x / 16) * 16 + 8;
				
				}
	if (App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16)] == -3 )
	{
		position.x = 0;
	}
	if (App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16)] == -4 )
	{
		position.x = 410;
	}

		
		if (destroyed == false)
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));


		// Draw everything --------------------------------------
		SDL_Rect r = current_animation->GetCurrentFrame();

	

		if (SDL_GetTicks() - time > 4000){
			power = false;
		}

		

		return UPDATE_CONTINUE;
	}



void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
	if (c1 == col && destroyed == false )
	{
		if (c2->type == COLLIDER_BLINKY ){
			if (power == false  && god == false){
				destroyed = true;
			}
			else { App->blinky->position.x = 208;
			App->blinky->position.y = 408;
			}
		}
		if (c2->type == COLLIDER_INKY){
			if (power == false && god == false){
				destroyed = true;
			}
			else {
				App->inky->position.x = 208;
				App->inky->position.y = 408;
			}
		}
		if (c2->type == COLLIDER_PINKY){
			if (power == false && god == false){
				destroyed = true;
			}
			else {
				App->pinky->position.x = 208;
				App->pinky->position.y = 408;
			}
		}
		if (c2->type == COLLIDER_SUE){
			if (power == false && god == false){
				destroyed = true;
			}
			else {
				App->sue->position.x = 208;
				App->sue->position.y = 408;
			}
		}
		if (c2->type == COLLIDER_POWERPELLET){
			time = SDL_GetTicks();
			power = true;
			
		}
		
	}
}