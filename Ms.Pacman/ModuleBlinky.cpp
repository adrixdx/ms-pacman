#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleBlinky.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModuleGhost.h"
#include "ModuleGhost_Blinky.h"
#include "ModuleGhost_Inky.h"
#include "ModuleGhost_Pinky.h"
#include "ModuleGhost_Sue.h"
#include "ModuleLevelOne.h"
#include "ModulePlayer.h"
#include <stdlib.h>
#include<time.h>





ModuleEnemies::ModuleEnemies()
{
	
	
	//int direction;
	//direction = rand()%4;
	// idle animation (arcade sprite sheet)
	idle.PushBack({ 0, 64, 32, 32 });


	// Right
	right.PushBack({ 192, 64, 32, 32 });
	right.PushBack({ 224, 64, 32, 32 });
	
	right.speed = 0.1f;

	// Left
	left.PushBack({ 128, 64, 32, 32 });
	left.PushBack({ 160, 64, 32, 32 });


	left.speed = 0.1f;

	// Up
	up.PushBack({ 0, 64, 32, 32 });
	up.PushBack({ 32, 64, 32, 32 });

	up.speed = 0.1f;

	//Down
	down.PushBack({ 64, 64, 32, 32 });
	down.PushBack({ 96, 64, 32, 32 });
	
	down.speed = 0.1f;

}

ModuleEnemies::~ModuleEnemies()
{}

// Load assets
bool ModuleEnemies::Start()
{

	position.x = 208;
	position.y = 102;
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("characters.png"); // arcade version
	

	col = App->collision->AddCollider({ position.x + 8, position.y + 8, 16, 16 }, COLLIDER_ENEMY, this);
	return ret;
}
bool ModuleEnemies::CleanUp()
{
	LOG("Unloading player");

	//App->textures->Unload(graphics);
	App->collision->EraseCollider(col);

	return true;
}

// Update: draw background
update_status ModuleEnemies::Update()
{
	Animation* current_animation = &idle;

	srand(time(NULL));

	float speed = 2;
	int direction = rand()%4;


	if (direction == 0){
		current_animation = &right;
		//position.x += speed;

	}
	
	if (direction == 1){
		current_animation = &left;
		//position.x -= speed;
	}


	if (direction == 2){
		current_animation = &up;
		//position.y -= speed;
	}

	if (direction == 3){
		current_animation = &down;
		//position.y += speed;
	}

	

	 int position_x = position.x;
	 int position_y = position.y;

	int tilepos_x = ((position_x + 16) / 16) * 16;
	int tilepos_y = ((position_y + 16) / 16) * 16;


	
	if (direction == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x + speed;
		position.x = position_x;
		position.y = (position_y / 16) * 16 + 8;
	}
	if (direction == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x - speed;
		position.x = position_x ;
		position.y = (position_y / 16) * 16 + 8;

	}
	if (direction == 2 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y - speed;
		position.y = position_y ;
		position.x = (position_x / 16) * 16 + 8;
	}
	if (direction == 3 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y + speed;
		position.y = position_y ;
		position.x = (position_x / 16) * 16 + 8;
	}


	if (direction == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) + 1] == 2){

		position_x = position_x - speed;
		position.x = (position_x / 16) * 16 + 8;

	}


	if (direction == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16) - 1] == 2){

		position_x = position_x + speed;
		position.x = (position_x / 16) * 16 + 8;
	}


	if (direction == 2 && App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] == 2){

		position_y = position_y + speed;
		position.y = (position_y / 16) * 16 + 8;


	}

	if (direction == 3 && App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] == 2){
		position_y = position_y - speed;
		position.y = (position_y / 16) * 16 + 8;

	}



	// Collider--------------

	col->SetPos(tilepos_x, tilepos_y);
	if (destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}


void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
 if (c1 == col && destroyed == false  )
 {
	 if (c2->type == COLLIDER_PLAYER && App->player->power == true){
		 position.x = 208;
		
		 position.y = 408;
		
	 }

 //destroyed = true;
 }
}