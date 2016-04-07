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

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevelOne::ModuleLevelOne()
{
	// ground
	ground = {0, 0, 448, 576};

	/*// roof
	roof = {91, 7, 765, 49};

	// foreground
	foreground = {164, 66, 336, 51};

	// Background / sky
	background = {120, 128, 671, 199};

	// flag animation
	water.PushBack({8, 447, 283, 9});
	water.PushBack({296, 447, 283, 12});
	water.PushBack({588, 447, 283, 18});
	water.speed = 0.02f;*/
}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Maze1.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	

	return ret;
}

// Load assets
bool ModuleLevelOne::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevelOne::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &ground);
	//App->render->Blit(graphics, 50, -15, &background, 0.75f); // back of the room
	
	//App->render->Blit(graphics, 280, 125, &foreground);
	///App->render->Blit(graphics, 305, 136, &(water.GetCurrentFrame())); // water animation
	//App->render->Blit(graphics, 0, -16, &roof, 0.75f);

	// TODO 3: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		////////////////////////////
		App->fade->FadeToBlack(App->level_one,App->start,1);
		
	}


	return UPDATE_CONTINUE;
}