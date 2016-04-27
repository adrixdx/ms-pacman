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
#include "ModuleBlinky.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382
int ModuleLevelOne::map[36][28] = {

	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },//1
	{ 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },//2
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },//3
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//4
	{ 2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 2 },//5
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//6
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//7
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 }, //8
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 },//9
	{ 2, 0, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 0, 2 },//10
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 },//11
	{ 2, 0, 0, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, 0, 2 },//12
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//13
	{ 0, 0, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 1, 2, 0, 2 },//14
	{ 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2 },//15
	{ 0, 0, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 1, 2, 0, 2 },//16
	{ 0, 0, 2, 1, 2, 2, 2, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 2, 2, 2, 1, 2, 0, 2 },//17
	{ 0, 0, 2, 1, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 1, 2, 0, 2 },//178
	{ 0, 0, 2, 1, 2, 2, 0, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 0, 2, 2, 1, 2, 2, 2 },//19
	{ 2, 2, 2, 1, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 1, 2, 2, 2 },//20
	{ 0, 0, 0, 1, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 0, 0 },//21º
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//22
	{ 0, 0, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 0, 2 },//23
	{ 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2 },//24
	{ 0, 0, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 0, 2 },//25
	{ 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2 },//26
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },//27
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//28
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//29
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//30
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//31
	{ 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2 },//32
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },//33
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },//34
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//35
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//36




};

ModuleLevelOne::ModuleLevelOne()
{
	// ground
	ground = {0, 0, 448, 576};

	//pellet
	pellet = { 12, 46, 8, 8 };

	//powerpellet
	powerpellet = { 22, 42, 20, 20 };

}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
 {
	
	 App->player->position.x = 208;
	 pellets = 228;
	 App->player->position.y = 408;

	LOG("Loading background assets");
	bool ret = true;

	graphics1 = App->textures->Load("Maze1.png");

	graphics2 = App->textures->Load("puntos.png");

	fx = App->audio->LoadFx("starting.wav");


	for (int i = 0; i < 28; i++){
		for (int n = 0; n < 35; n++){
			if (map[n][i] == 1){
				App->particles->AddParticle(App->particles->pellet, i * 16 + 3, n * 16 + 3, COLLIDER_PELLET, 0);
				
			}
			
		}
	}



	App->particles->AddParticle(App->particles->powerpellet, 15, 78, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 15, 479, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 78, COLLIDER_POWERPELLET, 0);
	App->particles->AddParticle(App->particles->powerpellet, 415, 479, COLLIDER_POWERPELLET, 0);
	
	App->player->Enable();
	App->enemies->Enable();

	return ret;
}

// Load assets
bool ModuleLevelOne::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();
	App->enemies->Disable();
	App->audio->UnLoadFx(fx);

	return true;
}

// Update: draw background
update_status ModuleLevelOne::Update()
{
	App->render->Blit(graphics1, 0, 0, &ground);
	
 	if (pellets == 0 || App->player->destroyed == true){
		App->level_one->Disable();
		App->start->Enable();
		//App->fade->FadeToBlack(App->level_one, App->start, 1);
		for (int i = 0; i < MAX_ACTIVE_PARTICLES; i++){
			delete App->particles->active[i];
			App->particles->active[i] = nullptr;
		}
	}
	
	return UPDATE_CONTINUE;
}