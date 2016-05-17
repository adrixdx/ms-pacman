#include "Globals.h"
#include "Application.h"
#include "ModuleLevelOne.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStartScreen.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleSue.h"
#include <stdlib.h>
#include<time.h>





ModuleSue::ModuleSue()
{


	//int direction;
	//direction = rand()%4;
	// idle animation (arcade sprite sheet)


}

ModuleSue::~ModuleSue()
{}

// Load assets
bool ModuleSue::Start()
{
	turn = true;

	srand(time(NULL));
	direction = rand() % 4;


	// Right
	right.PushBack({ 192, 160, 32, 32 });
	right.PushBack({ 224, 160, 32, 32 });

	right.speed = 0.1f;

	// Left
	left.PushBack({ 128, 160, 32, 32 });
	left.PushBack({ 160, 160, 32, 32 });


	left.speed = 0.1f;

	// Up
	up.PushBack({ 0, 160, 32, 32 });
	up.PushBack({ 32, 160, 32, 32 });

	up.speed = 0.1f;

	//Down
	down.PushBack({ 64, 160, 32, 32 });
	down.PushBack({ 96, 160, 32, 32 });

	down.speed = 0.1f;



	scared.PushBack({ 128, 32, 32, 32 });
	scared.PushBack({ 160, 32, 32, 32 });


	scared.speed = 0.1f;

	scared2.PushBack({ 192, 32, 32, 32 });
	scared2.PushBack({ 128, 32, 32, 32 });
	scared2.PushBack({ 224, 32, 32, 32 });
	scared2.PushBack({ 160, 32, 32, 32 });


	scared2.speed = 0.1f;






	position.x = 208;
	position.y = 250;
	LOG("Loadi ngplayer textures");
	bool ret = true;
	graphics = App->textures->Load("characters.png"); // arcade version


	col = App->collision->AddCollider({ position.x + 8, position.y + 8, 16, 16 }, COLLIDER_SUE, this);
	return ret;
}
bool ModuleSue::CleanUp()
{
	LOG("Unloading player");

	//App->textures->Unload(graphics);
	App->collision->EraseCollider(col);

	return true;
}

// Update: draw background
update_status ModuleSue::Update()
{
	Animation* current_animation = &idle;
	int position_x = position.x;
	int position_y = position.y;

	int tilepos_x = ((position_x + 16) / 16) * 16;
	int tilepos_y = ((position_y + 16) / 16) * 16;



	float speed = 2;
	if (turn == true){
		if (direction == 0 && (App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] != 2 || App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] != 2)){
			direction = rand() % 4;

			turn = false;
		}
		else if (direction == 1 && (App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] != 2 || App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] != 2)){
			direction = rand() % 4;
			turn = false;
		}
		else if (direction == 2 && (App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) - 1] != 2 || App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) + 1] != 2)){
			direction = rand() % 4;
			turn = false;
		}

		else if (direction == 3 && (App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) - 1] != 2 || App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) + 1] != 2)){
			direction = rand() % 4;
			turn = false;
		}

		if (direction == 0 && App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) + 1] == 2){
			direction = rand() % 4;
			turn = true;
		}
		else if (direction == 1 && App->level_one->map[(tilepos_y / 16)][(tilepos_x / 16) - 1] == 2){
			direction = rand() % 4;
			turn = true;
		}
		else if (direction == 2 && App->level_one->map[(tilepos_y / 16) - 1][(tilepos_x / 16)] == 2){
			direction = rand() % 4;
			turn = true;
		}

		else if (direction == 3 && App->level_one->map[(tilepos_y / 16) + 1][(tilepos_x / 16)] == 2){
			direction = rand() % 4;
			turn = true;
		}
	}



	if (App->player->power == true || App->player->god == true){
		if (SDL_GetTicks() - App->player->time > 2000 && SDL_GetTicks() - App->player->time < 4000){
			current_animation = &scared2;
		}
		else
			current_animation = &scared;
	}
	else{
		if (App->player->power == true){
			if (SDL_GetTicks() - App->player->time > 2000 && SDL_GetTicks() - App->player->time < 4000){
				current_animation = &scared2;
			}
			else
				current_animation = &scared;
		}
		else{

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

		}
	}






	if (direction == 0 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x + speed;
		position.x = position_x;
		position.y = (position_y / 16) * 16 + 8;
	}
	if (direction == 1 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x - speed;
		position.x = position_x;
		position.y = (position_y / 16) * 16 + 8;

	}
	if (direction == 2 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y - speed;
		position.y = position_y;
		position.x = (position_x / 16) * 16 + 8;
	}
	if (direction == 3 && App->level_one->map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y + speed;
		position.y = position_y;
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
	int tilepos_x_temp = ((position_x + 16) / 16) * 16;
	int tilepos_y_temp = ((position_y + 16) / 16) * 16;

	if (tilepos_x_temp != tilepos_x || tilepos_y_temp != tilepos_y){
		turn = true;
	}

	return UPDATE_CONTINUE;
}


void ModuleSue::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == col && destroyed == false)
	{
		if (c2->type == COLLIDER_PLAYER && App->player->power == true){
			position.x = 208;

			position.y = 250;

		}

		//destroyed = true;
	}
}