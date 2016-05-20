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
#include "ModuleGameOverFour.h"
#include "ModuleLevelThree.h"
#include "ModuleReady.h"
#include "ModuleLevelFour.h"

#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"

#include "ModuleWin.h"



int ModuleLevelFour::map[36][28] = {

	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//1
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//2
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//3
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//4  --START
	{ 2, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 2 },//5
	{ 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2 },//6
	{ 2, 0, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 0, 2 },//7
	{ 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, -1, 1, 1, -1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2 },//8
	{ 2, 1, 2, 2, -1, 1, -1, 1, 1, -1, 2, 2, 1, 2, 2, 1, 2, 2, -1, 1, 1, -1, 1, -1, 2, 2, 1, 2 },//9
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//10
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//11
	{ 2, -1, 1, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 2, 2, -1, 1, 1, -1, 1, -1, 2 },//12
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//13
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//14
	{ 2, 2, 2, -1, 1, 1, -1, 2, 2, -2, 0, 0, -2, 0, 0, -2, 0, 0, -2, 2, 2, -1, 1, 1, -1, 2, 2, 2 },//15
	{ 2, 2, 2, 0, 2, 2, 1, 2, 2, 0, 2, 2, 2, 3, 3, 2, 2, 2, 0, 2, 2, 1, 2, 2, 0, 2, 2, 2 },//16
	{ -4, 0, 0, -2, 2, 2, 1, 2, 2, 0, 2, 0, 0, 3, 3, 0, 0, 2, 0, 2, 2, 1, 2, 2, -2, 0, 0, -3 },//17
	{ 2, 2, 2, 2, 2, 2, -1, 0, 0, -2, 2, 0, 0, 0, 0, 0, 0, 2, -2, 0, 0, -1, 2, 2, 2, 2, 2, 2 },//18
	{ 2, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 2 },//19
	{ -4, 0, 0, -2, 2, 2, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 1, 2, 2, -2, 0, 0, -3 },//20
	{ 2, 2, 2, 0, 2, 2, 1, 2, 2, -2, 0, 0, -2, 0, 0, -2, 0, 0, -2, 2, 2, 1, 2, 2, 0, 2, 2, 2 },//21
	{ 2, 2, 2, -1, 1, 1, -1, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, -1, 1, 1, -1, 2, 2, 2 },//22
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 },//23
	{ 2, 2, 2, 1, 2, 2, -1, 1, 1, -1, 0, 0, -2, 2, 2, -2, 0, 0, -1, 1, 1, -1, 2, 2, 1, 2, 2, 2 },//24
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//25
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//26
	{ 2, -1, 1, -1, 1, 1, -1, 1, 1, -1, 2, 2, -2, 0, 0, -2, 2, 2, -1, 1, 1, -1, 1, 1, -1, 1, -1, 2 },//27
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//28
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//29
	{ 2, 1, 2, 2, -1, 1, -1, 2, 2, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 2, 2, -1, 1, -1, 2, 2, 1, 2 },//30
	{ 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2 },//31
	{ 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2 },//32
	{ 2, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, -1, 2, 2, -1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, -1, 2 },//33
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//4  --START
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//35
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//36




};

ModuleLevelFour::ModuleLevelFour()
{
	// ground
	ground = { 0, 0, 448, 576 };

	//pellet
	pellet = { 12, 46, 8, 8 };

	//powerpellet
	powerpellet = { 22, 42, 20, 20 };

}

ModuleLevelFour::~ModuleLevelFour()
{}

// Load assets
bool ModuleLevelFour::Start()
{
	App->player->power == false;
	App->player->position.x = 208;
	pellets = 224;
	App->player->position.y = 408;
	App->player->n_map = 3;
	App->audio->PlayMusic("effect.ogg", 1.0f);

	App->inky->time = SDL_GetTicks();
	App->pinky->time = SDL_GetTicks();
	App->sue->time = SDL_GetTicks();

	LOG("Loading background assets");
	bool ret = true;

	graphics1 = App->textures->Load("Maze4.png");

	graphics2 = App->textures->Load("puntos.png");

	fx = App->audio->LoadFx("starting.wav");


	for (int i = 0; i < 28; i++){
		for (int n = 0; n < 35; n++){
			if (map[n][i] == 1 || map[n][i] == -1){
				App->particles->AddParticle(App->particles->pellet, i * 16 + 3, n * 16 + 3, COLLIDER_PELLET, 0);

			}


		}

	}




	App->particles->AddParticle(App->particles->powerpellet, 15, 94, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 15, 479, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 94, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 479, COLLIDER_POWERPELLET, 0);

	App->player->Enable();
	App->blinky->Enable();
	App->sue->Enable();
	App->pinky->Enable();
	App->inky->Enable();


	return ret;
}

// Load assets
bool ModuleLevelFour::CleanUp()
{
	LOG("Unloading level one stage");
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
update_status ModuleLevelFour::Update()
{
	App->render->Blit(graphics1, 0, 0, &ground);


	if (pellets == 0 || App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(this, App->ready, 1);
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
		App->fade->FadeToBlack(this, App->gameover_four, 1);
	}

	return UPDATE_CONTINUE;
}