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
#include "ModulePinky.h"
#include "ModulePlayer.h"
#include <stdlib.h>
#include<time.h>





ModulePinky::ModulePinky()
{


	//int direction;
	//direction = rand()%4;
	// idle animation (arcade sprite sheet)


}

ModulePinky::~ModulePinky()
{}

// Load assets
bool ModulePinky::Start()
{
	turn = true;

	
	direction = 2;


	// Right
	right.PushBack({ 192, 96, 32, 32 });
	right.PushBack({ 224, 96, 32, 32 });

	right.speed = 0.1f;

	// Left
	left.PushBack({ 128, 96, 32, 32 });
	left.PushBack({ 160, 96, 32, 32 });


	left.speed = 0.1f;

	// Up
	up.PushBack({ 0, 96, 32, 32 });
	up.PushBack({ 32, 96, 32, 32 });

	up.speed = 0.1f;

	//Down
	down.PushBack({ 64, 96, 32, 32 });
	down.PushBack({ 96, 96, 32, 32 });

	down.speed = 0.1f;



	scared.PushBack({ 128, 32, 32, 32 });
	scared.PushBack({ 160, 32, 32, 32 });


	scared.speed = 0.1f;

	scared2.PushBack({ 192, 32, 32, 32 });
	scared2.PushBack({ 128, 32, 32, 32 });
	scared2.PushBack({ 224, 32, 32, 32 });
	scared2.PushBack({ 160, 32, 32, 32 });


	scared2.speed = 0.1f;

	a_hor.PushBack({ 203, 433, 32, 28 });
	a_hor.speed = 0.0f;

	a_vert.PushBack({ 233, 340, 30, 32 });
	a_vert.speed = 0.0f;
	square.PushBack({ 8, 390, 16, 16 });





	time = SDL_GetTicks();
	position.x = 192;
	position.y = 250;
	LOG("Loadi ngplayer textures");
	bool ret = true;
	graphics = App->textures->Load("Game/characters.png"); // arcade version


	col = App->collision->AddCollider({ position.x + 8, position.y + 8, 16, 16 }, COLLIDER_PINKY, this);
	return ret;
}
bool ModulePinky::CleanUp()
{
	LOG("Unloading player");

	//App->textures->Unload(graphics);
	App->collision->EraseCollider(col);

	return true;
}

// Update: draw background
update_status ModulePinky::Update()
{
	Animation* current_animation = &idle;

	Animation* horitzontal = &a_hor;
	Animation* vertical = &a_vert;
	Animation* a_square = &square;
	float position_x = position.x;
	float position_y = position.y;
	int i_position_x = position.x;
	int i_position_y = position.y;

	int p_i_position_x = App->player->position.x;
	int p_i_position_y = App->player->position.y;

	int tilepos_x = ((i_position_x + 16) / 16) * 16;
	int tilepos_y = ((i_position_y + 16) / 16) * 16;

	int p_tilepos_x = ((p_i_position_x + 16) / 16) * 16;
	int p_tilepos_y = ((p_i_position_y + 16) / 16) * 16;

	int d_up = 1000;
	int d_down = 1000;
	int d_right = 1000;
	int d_left = 1000;
	int pl_max_moves = 0;
	int i = 0;
	int n = 0;


	if (App->player->dir == 0){
		while (App->player->s_map[(p_tilepos_y / 16)][(p_tilepos_x / 16) + i + 1] != 2){
			i++;
		}
	}
	if (App->player->dir == 1){
		while (App->player->s_map[(p_tilepos_y / 16)][(p_tilepos_x / 16) + i - 1] != 2){
			i--;
		}
	}
	if (App->player->dir == 2){
		while (App->player->s_map[(p_tilepos_y / 16) + n - 1][(p_tilepos_x / 16)] != 2){
			n--;
		}
	}
	if (App->player->dir == 3){
		while (App->player->s_map[(p_tilepos_y / 16) + n + 1][(p_tilepos_x / 16)] != 2){
			n++;
		}
	}


	float speed = 1.5;

	if (SDL_GetTicks() - time <= 950){
		direction = 2;
	}
	else if (SDL_GetTicks() - time <= 980){
		direction = 1;
	}
	else {
		if (turn == true){

			if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -1 || App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -2){
				if (App->player->s_map[(tilepos_y / 16) - 1][(tilepos_x / 16)] != 2){
					d_up = SDL_sqrt(((tilepos_x)-(p_tilepos_x + i * 16))*(tilepos_x - (p_tilepos_x + i * 16)) + ((tilepos_y - 16) - (p_tilepos_y + n * 16))*((tilepos_y - 16) - (p_tilepos_y + n * 16)));
				}

				if (App->player->s_map[(tilepos_y / 16) + 1][(tilepos_x / 16)] != 2){
					d_down = SDL_sqrt(((tilepos_x)-(p_tilepos_x + i * 16))*(tilepos_x - (p_tilepos_x + i * 16)) + ((tilepos_y + 16) - (p_tilepos_y + n * 16))*((tilepos_y + 16) - (p_tilepos_y + n * 16)));
				}

				if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16) - 1] != 2){
					d_left = SDL_sqrt(((tilepos_x - 16) - (p_tilepos_x + i * 16))*((tilepos_x - 16) - (p_tilepos_x + i * 16)) + ((tilepos_y)-(p_tilepos_y + n * 16))*((tilepos_y)-(p_tilepos_y + n * 16)));
				}

				if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16) + 1] != 2){
					d_right = SDL_sqrt(((tilepos_x + 16) - (p_tilepos_x + i * 16))*((tilepos_x + 16) - (p_tilepos_x + i * 16)) + ((tilepos_y)-(p_tilepos_y + n * 16))*((tilepos_y)-(p_tilepos_y + n * 16)));
				}

				if (direction == 0){
					d_left = 1000;
				}
				if (direction == 1){
					d_right = 1000;
				}
				if (direction == 2){
					d_down = 1000;
				}
				if (direction == 3){
					d_up = 1000;
				}

				if (d_up <= d_down && d_up <= d_right && d_up <= d_left){
					direction = 2; turn = false;
				}
				else if (d_right <= d_down && d_right <= d_left && d_right <= d_up){
					direction = 0; turn = false;
				}
				else if (d_down <= d_up && d_down <= d_right && d_down <= d_left){
					direction = 3; turn = false;
				}

				else if(d_left <= d_up && d_left<= d_right && d_left<=d_down){
					direction = 1; turn = false;
				}

			}
			if (App->player->power == true){

				d_up = 0;
				d_down = 0;
				d_right = 0;
				d_left = 0;

				if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -1 || App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -2){
					if (App->player->s_map[(tilepos_y / 16) - 1][(tilepos_x / 16)] != 2){
						d_up = SDL_sqrt(((tilepos_x)-App->player->position.x)*(tilepos_x - App->player->position.x) + ((tilepos_y - 16) - App->player->position.y)*((tilepos_y - 16) - App->player->position.y));
					}

					if (App->player->s_map[(tilepos_y / 16) + 1][(tilepos_x / 16)] != 2){
						d_down = SDL_sqrt(((tilepos_x)-App->player->position.x)*(tilepos_x - App->player->position.x) + ((tilepos_y + 16) - App->player->position.y)*((tilepos_y + 16) - App->player->position.y));
					}

					if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16) - 1] != 2){
						d_left = SDL_sqrt(((tilepos_x - 16) - App->player->position.x)*((tilepos_x - 16) - App->player->position.x) + ((tilepos_y)-App->player->position.y)*((tilepos_y)-App->player->position.y));
					}

					if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16) + 1] != 2){
						d_right = SDL_sqrt(((tilepos_x + 16) - App->player->position.x)*((tilepos_x + 16) - App->player->position.x) + ((tilepos_y)-App->player->position.y)*((tilepos_y)-App->player->position.y));
					}


				


					if (d_up >= d_down && d_up >= d_right && d_up >= d_left){
						direction = 2; turn = false;
					}
					else if (d_down >=  d_up && d_down >= d_right && d_down >= d_left){
						direction = 3; turn = false;
					}
					else if (d_right >= d_down && d_right >= d_left && d_right >= d_up){
						direction = 0; turn = false;
					}
					else if (d_left >= d_up && d_left >= d_right && d_left >= d_down){
						direction = 1; turn = false;
					}

				}

			}

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






	if (direction == 0 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x + speed;
		position.x = position_x;
		position.y = (i_position_y / 16) * 16 + 8;
	}
	if (direction == 1 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_x = position_x - speed;
		position.x = position_x;
		position.y = (i_position_y / 16) * 16 + 8;

	}
	if (direction == 2 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y - speed;
		position.y = position_y;
		position.x = (i_position_x / 16) * 16 + 8;
	}
	if (direction == 3 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16)] != 2){

		position_y = position_y + speed;
		position.y = position_y;
		position.x = (i_position_x / 16) * 16 + 8;
	}


	if (direction == 0 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16) + 1] == 2){

		position_x = position_x - speed;
		position.x = (i_position_x / 16) * 16 + 8;

	}


	if (direction == 1 && App->player->s_map[tilepos_y / 16][(tilepos_x / 16) - 1] == 2){

		position_x = position_x + speed;
		position.x = (i_position_x / 16) * 16 + 8;
	}


	if (direction == 2 && App->player->s_map[(tilepos_y / 16) - 1][(tilepos_x / 16)] == 2){

		position_y = position_y + speed;
		position.y = (i_position_y / 16) * 16 + 8;


	}

	if (direction == 3 && App->player->s_map[(tilepos_y / 16) + 1][(tilepos_x / 16)] == 2){
		position_y = position_y - speed;
		position.y = (i_position_y / 16) * 16 + 8;

	}
	float t_positionx = position.x;
	float t_positiony = position.y;
	float t_position_x = t_positionx;
	float t_position_y = t_positiony;
	int p_position_x = App->player->position.x;
	int p_position_y = App->player->position.y;
	int player_position_x = ((p_position_x + 16) / 16) * 16;
	int player_position_y = ((p_position_y + 16) / 16) * 16;
	bool t_turn = true;

	
	int temp_dir = direction;
	bool ret = false;
	int cont = 0;
	if (debug == true){
		App->render->Blit(graphics, (p_tilepos_x + i * 16), (p_tilepos_y + n * 16), &(a_square->GetCurrentFrame()));
		while (ret != true){
			d_up = 1000;
			d_down = 1000;
			d_left = 1000;
			d_right = 1000;
			//t_position_x + i != App->player->position.x  && t_position_y + n != App->player->position.y
			float t_position_x = t_positionx;
			float t_position_y = t_positiony;
			int t_i_position_x = t_positionx;
			int t_i_position_y = t_positiony;
			int t_tilepos_y = ((t_i_position_y + 16) / 16) * 16;
			int t_tilepos_x = ((t_i_position_x + 16) / 16) * 16;


			if (t_turn == true){

				if (App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16)] == -1 || App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16)] == -2){
					if (App->player->s_map[(t_tilepos_y / 16) - 1][(t_tilepos_x / 16)] != 2){
						d_up = SDL_sqrt(((t_tilepos_x)-(p_tilepos_x + i * 16))*(t_tilepos_x - (p_tilepos_x + i * 16)) + ((t_tilepos_y - 16) - (p_tilepos_y + n * 16))*((t_tilepos_y - 16) - (p_tilepos_y + n * 16)));
					}

					if (App->player->s_map[(t_tilepos_y / 16) + 1][(t_tilepos_x / 16)] != 2){
						d_down = SDL_sqrt(((t_tilepos_x)-(p_tilepos_x + i * 16))*(t_tilepos_x - (p_tilepos_x + i * 16)) + ((t_tilepos_y + 16) - (p_tilepos_y + n * 16))*((t_tilepos_y + 16) - (p_tilepos_y + n * 16)));
					}

					if (App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16) - 1] != 2){
						d_left = SDL_sqrt(((t_tilepos_x - 16) - (p_tilepos_x + i * 16))*((t_tilepos_x - 16) - (p_tilepos_x + i * 16)) + ((t_tilepos_y)-(p_tilepos_y + n * 16))*((t_tilepos_y)-(p_tilepos_y + n * 16)));
					}

					if (App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16) + 1] != 2){
						d_right = SDL_sqrt(((t_tilepos_x + 16) - (p_tilepos_x + i * 16))*((t_tilepos_x + 16) - (p_tilepos_x + i * 16)) + ((t_tilepos_y)-(p_tilepos_y + n * 16))*((t_tilepos_y)-(p_tilepos_y + n * 16)));
					}

					if (temp_dir == 0){
						d_left = 1000;
					}
					if (temp_dir == 1){
						d_right = 1000;
					}
					if (temp_dir == 2){
						d_down = 1000;
					}
					if (temp_dir == 3){
						d_up = 1000;
					}


					if (d_up <= d_down && d_up <= d_right && d_up <= d_left){
						temp_dir = 2; t_turn = false;
					}
					else if (d_right <= d_down && d_right <= d_left && d_right <= d_up){
						temp_dir = 0; t_turn = false;
					}
					else if (d_down <= d_up && d_down <= d_right && d_down <= d_left){
						temp_dir = 3; t_turn = false;
					}

					else if (d_left <= d_up && d_left <= d_right && d_left <= d_down){
						temp_dir = 1; t_turn = false;
					}

				}


			}
			if (temp_dir == 0 && App->player->s_map[t_tilepos_y / 16][(t_tilepos_x / 16)] != 2){

				t_position_x = t_position_x + speed;
				t_positionx = t_position_x;
				t_positiony = (t_i_position_y / 16) * 16 + 8;
			}
			if (temp_dir == 1 && App->player->s_map[t_tilepos_y / 16][(t_tilepos_x / 16)] != 2){

				t_position_x = t_position_x - speed;
				t_positionx = t_position_x;
				t_positiony = (t_i_position_y / 16) * 16 + 8;

			}
			if (temp_dir == 2 && App->player->s_map[t_tilepos_y / 16][(t_tilepos_x / 16)] != 2){

				t_position_y = t_position_y - speed;
				t_positiony = t_position_y;
				t_positionx = (t_i_position_x / 16) * 16 + 8;
			}
			if (temp_dir == 3 && App->player->s_map[t_tilepos_y / 16][(t_tilepos_x / 16)] != 2){

				t_position_y = t_position_y + speed;
				t_positiony = t_position_y;
				t_positionx = (t_i_position_x / 16) * 16 + 8;
			}


			if (temp_dir == 0 && App->player->s_map[t_tilepos_y / 16][(t_tilepos_x / 16) + 1] == 2){

				t_position_x = t_position_x - speed;
				t_positionx = (t_i_position_x / 16) * 16 + 8;

			}


			if (temp_dir == 0 || temp_dir == 1){
				App->render->Blit(graphics, t_tilepos_x, t_tilepos_y, &(horitzontal->GetCurrentFrame()));
			}
			else App->render->Blit(graphics, t_tilepos_x, t_tilepos_y, &(vertical->GetCurrentFrame()));

			if (temp_dir == 0){
				t_tilepos_x += 16;
			}
			if (temp_dir == 1){
				t_tilepos_x -= 16;
			}
			if (temp_dir == 2){
				t_tilepos_y -= 16;
			}
			if (temp_dir == 3){
				t_tilepos_y += 16;
			}
			if (App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16)] != -1 && App->player->s_map[(t_tilepos_y / 16)][(t_tilepos_x / 16)] != -2)
			{

				t_turn = true;
			}
			if ((t_tilepos_y == player_position_y && t_tilepos_x == player_position_x) || cont >= 100){
				ret = true;
				t_turn = true;
				temp_dir = direction;
			}
			cont++;
		}
	}


	// Collider--------------

	col->SetPos(tilepos_x, tilepos_y);




	if (destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -3)
	{
		position.x = 0;
	}
	if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] == -4)
	{
		position.x = 410;
	}
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//App->render->Blit(graphics, position.x, position.y - r.h, &r);
	if (App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] != -1 && App->player->s_map[(tilepos_y / 16)][(tilepos_x / 16)] != -2)
	{
		turn = true;
	}
	return UPDATE_CONTINUE;
}


void ModulePinky::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == col && destroyed == false)
	{
		if (c2->type == COLLIDER_PLAYER && (App->player->power == true || App->player->god== true)){
			position.x = 208;

			position.y = 260;
			time = SDL_GetTicks();

		}

		//destroyed = true;
	}
}