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
#include "ModuleBlinky.h"
#include "ModuleGameOverThree.h"

#include "ModuleLevelThree.h"
#include "ModuleLevelTwo.h"
#include "ModuleLevelFour.h"
#include "ModuleReadyFour.h"

#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"

#include "ModuleWin.h"



int ModuleLevelThree::map[36][28] = {

	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//1
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//2
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//3
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//4  --START
	{ 2, -1, 1, 1, 1, 1, 1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, 1, 1, 1, 1, 1, -1, 2 },//5
	{ 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2 },//6
	{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 0, 2 },//7
	{ 2, 1, 2, 2, -1, 1, 1, -1, 1, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 1, -1, 1, 1, -1, 2, 2, 1, 2 },//8
	{ 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2 },//9
	{ 2, -1, 1, 1, -1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, -1, 1, 1, -1, 2 },//10
	{ 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2 },//11
	{ 2, 2, 2, 2, 1, 2, 2, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 2, 2, 1, 2, 2, 2, 2 },//12
	{ -4, -1, 1, 1, -1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, -1, 1, 1, -1, -3 },//13
	{ 2, 1, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 1, 2 },//14
	{ 2, 1, 2, 2, -2, 0,-2, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, -2, 0, -2, 2, 2, 1, 2 },//15
	{ 2, 1, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 3, 3, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 1, 2 },//16
	{ 2, 1, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 3, 3, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 1, 2 },//17
	{ 2, -1, 0, 0, -2, 0, -2, 2, 2, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 2, 2, -2, 0, -2, 0, 0, -1, 2 },//18
	{ 2, 1, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 1, 2 },//19
	{ 2, 1, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 1, 2 },//20
	{ 2, 1, 2, 2, -2, 0, -2, 0, 0, -2, 0, 0, -2, 0, 0, -2, 0, 0, -2, 0, 0, -2, 0, -2, 2, 2, 1, 2 },//21
	{ 2, 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1, 2 },//22
	{ 2, 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1, 2 },//23
	{ 2, -1, 1, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 1, -1, 2 },//24
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2 },//25
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2 },//26
	{ 2, -2, 1, -1, 2, 2, -1, 1, 1, -1, 1, 1, -1, 0, 0, -1, 1, 1, -1, 1, 1, -1, 2, 2, -1, 1, -2, 2 },//27
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//28
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//29
	{ 2, -1, 1, 1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, 1, 1, -1, 2 },//30
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//31
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//32
	{ 2, -1, 1, 1, 1, 1, -1, 2, 2, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 2, 2, -1, 1, 1, 1, 1, -1, 2 },//33
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//34 --END
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//35
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//36




};

ModuleLevelThree::ModuleLevelThree()
{
	// ground
	ground = { 0, 0, 448, 576 };

	//pellet
	pellet = { 12, 46, 8, 8 };

	//powerpellet
	powerpellet = { 22, 42, 20, 20 };

}

ModuleLevelThree::~ModuleLevelThree()
{}

// Load assets
bool ModuleLevelThree::Start()
{

	App->player->power == false;
	App->player->position.x = 208;
	pellets = 242;
	App->player->position.y = 408;
	App->player->n_map = 2;
	App->audio->PlayMusic("Game/effect.ogg", 1.0f);

	App->inky->time = SDL_GetTicks();
	App->pinky->time = SDL_GetTicks();

	LOG("Loading background assets");
	bool ret = true;

	graphics1 = App->textures->Load("Game/Maze3.png");

	graphics2 = App->textures->Load("Game/puntos.png");

	fx = App->audio->LoadFx("Game/starting.wav");


	for (int i = 0; i < 28; i++){
		for (int n = 0; n < 35; n++){
			if (map[n][i] == 1 || map[n][i] == -1){
				App->particles->AddParticle(App->particles->pellet, i * 16 + 3, n * 16 + 3, COLLIDER_PELLET, 0);

			}


		}

	}




	App->particles->AddParticle(App->particles->powerpellet, 15, 94, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 15, 416, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 94, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 416, COLLIDER_POWERPELLET, 0);
	
	App->player->Enable();
	App->blinky->Enable();
	App->sue->Enable();
	App->pinky->Enable();
	App->inky->Enable();


	return ret;
}

// Load assets
bool ModuleLevelThree::CleanUp()
{
	LOG("Unloading level three stage");
	App->player->Disable();
	App->enemies->Disable();
	App->audio->Disable();
	App->blinky->Disable();
	App->sue->Disable();
	App->pinky->Disable();
	App->inky->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevelThree::Update()
{

	App->render->Blit(graphics1, 0, 0, &ground);

	
	if (pellets == 0 || App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
	
		App->fade->FadeToBlack(this, App->ready_four, 1);
		for (int i = 0; i < MAX_ACTIVE_PARTICLES; i++){
			delete App->particles->active[i];
			App->particles->active[i] = nullptr;
		}
	}
	else if (App->player->destroyed == true){



		for (int i = 0; i < MAX_ACTIVE_PARTICLES; i++){
			delete App->particles->active[i];
			App->particles->active[i] = nullptr;
		}
		App->fade->FadeToBlack(this, App->gameover_three, 1);
	}


	return UPDATE_CONTINUE;
}