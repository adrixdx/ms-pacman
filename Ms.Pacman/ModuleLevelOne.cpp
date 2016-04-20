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

}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Maze1.png");

	
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
	
	App->render->Blit(graphics, 0, 0, &ground);
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->level_one,App->start,1);
		
	}


	return UPDATE_CONTINUE;
}