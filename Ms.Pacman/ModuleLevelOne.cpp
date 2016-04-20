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
	LOG("Loading background assets");
	bool ret = true;
	graphics1 = App->textures->Load("Maze1.png");

	graphics2 = App->textures->Load("puntos.png");
	
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
	
	App->render->Blit(graphics1, 0, 0, &ground);

	App->render->Blit(graphics1, 0, 0, &ground);
	App->render->Blit(graphics2, 19, 65, &pellet);
	App->render->Blit(graphics2, 35, 65, &pellet);
	App->render->Blit(graphics2, 51, 65, &pellet);
	App->render->Blit(graphics2, 67, 65, &pellet);
	App->render->Blit(graphics2, 83, 65, &pellet);
	App->render->Blit(graphics2, 99, 65, &pellet);
	App->render->Blit(graphics2, 19, 99, &pellet);
	App->render->Blit(graphics2, 19, 116, &pellet);
	App->render->Blit(graphics2, 35, 116, &pellet);
	App->render->Blit(graphics2, 51, 116, &pellet);
	App->render->Blit(graphics2, 67, 116, &pellet);
	App->render->Blit(graphics2, 83, 116, &pellet);
	App->render->Blit(graphics2, 99, 116, &pellet);
	App->render->Blit(graphics2, 99, 99, &pellet);
	App->render->Blit(graphics2, 99, 82, &pellet);
	App->render->Blit(graphics2, 115, 116, &pellet);
	App->render->Blit(graphics2, 131, 116, &pellet);
	App->render->Blit(graphics2, 147, 116, &pellet);
	App->render->Blit(graphics2, 163, 116, &pellet);
	App->render->Blit(graphics2, 179, 116, &pellet);
	App->render->Blit(graphics2, 195, 116, &pellet);
	App->render->Blit(graphics2, 211, 116, &pellet);
	App->render->Blit(graphics2, 227, 116, &pellet);
	App->render->Blit(graphics2, 243, 116, &pellet);
	App->render->Blit(graphics2, 259, 116, &pellet);
	App->render->Blit(graphics2, 275, 116, &pellet);
	App->render->Blit(graphics2, 291, 116, &pellet);
	App->render->Blit(graphics2, 307, 116, &pellet);
	App->render->Blit(graphics2, 323, 116, &pellet);
	App->render->Blit(graphics2, 339, 116, &pellet);
	App->render->Blit(graphics2, 355, 116, &pellet);
	App->render->Blit(graphics2, 371, 116, &pellet);
	App->render->Blit(graphics2, 387, 116, &pellet);
	App->render->Blit(graphics2, 403, 116, &pellet);
	App->render->Blit(graphics2, 419, 116, &pellet);
	App->render->Blit(graphics2, 419, 99, &pellet);
	App->render->Blit(graphics2, 419, 65, &pellet);
	App->render->Blit(graphics2, 403, 65, &pellet);
	App->render->Blit(graphics2, 387, 65, &pellet);
	App->render->Blit(graphics2, 371, 65, &pellet);
	App->render->Blit(graphics2, 355, 65, &pellet);
	App->render->Blit(graphics2, 339, 65, &pellet);
	App->render->Blit(graphics2, 339, 82, &pellet);
	App->render->Blit(graphics2, 339, 99, &pellet);
	App->render->Blit(graphics2, 147, 99, &pellet);
	App->render->Blit(graphics2, 147, 82, &pellet);
	App->render->Blit(graphics2, 147, 65, &pellet);
	App->render->Blit(graphics2, 291, 99, &pellet);
	App->render->Blit(graphics2, 291, 82, &pellet);
	App->render->Blit(graphics2, 291, 65, &pellet);
	App->render->Blit(graphics2, 163, 65, &pellet);
	App->render->Blit(graphics2, 179, 65, &pellet);
	App->render->Blit(graphics2, 195, 65, &pellet);
	App->render->Blit(graphics2, 211, 65, &pellet);
	App->render->Blit(graphics2, 227, 65, &pellet);
	App->render->Blit(graphics2, 243, 65, &pellet);
	App->render->Blit(graphics2, 259, 65, &pellet);
	App->render->Blit(graphics2, 275, 65, &pellet);
	App->render->Blit(graphics2, 51, 133, &pellet);
	App->render->Blit(graphics2, 51, 150, &pellet);
	App->render->Blit(graphics2, 51, 167, &pellet);
	App->render->Blit(graphics2, 51, 184, &pellet);
	App->render->Blit(graphics2, 51, 201, &pellet);
	App->render->Blit(graphics2, 51, 218, &pellet);
	App->render->Blit(graphics2, 51, 235, &pellet);
	App->render->Blit(graphics2, 51, 252, &pellet);
	App->render->Blit(graphics2, 51, 269, &pellet);
	App->render->Blit(graphics2, 51, 286, &pellet);
	App->render->Blit(graphics2, 51, 303, &pellet);
	App->render->Blit(graphics2, 51, 320, &pellet);
	App->render->Blit(graphics2, 51, 337, &pellet);
	App->render->Blit(graphics2, 51, 354, &pellet);
	App->render->Blit(graphics2, 51, 371, &pellet);
	App->render->Blit(graphics2, 51, 388, &pellet);
	App->render->Blit(graphics2, 51, 405, &pellet);
	App->render->Blit(graphics2, 51, 422, &pellet);
	App->render->Blit(graphics2, 387, 422, &pellet);
	App->render->Blit(graphics2, 387, 405, &pellet);
	App->render->Blit(graphics2, 387, 388, &pellet);
	App->render->Blit(graphics2, 387, 371, &pellet);
	App->render->Blit(graphics2, 387, 354, &pellet);
	App->render->Blit(graphics2, 387, 337, &pellet);
	App->render->Blit(graphics2, 387, 320, &pellet);
	App->render->Blit(graphics2, 387, 303, &pellet);
	App->render->Blit(graphics2, 387, 286, &pellet);
	App->render->Blit(graphics2, 387, 269, &pellet);
	App->render->Blit(graphics2, 387, 252, &pellet);
	App->render->Blit(graphics2, 387, 235, &pellet);
	App->render->Blit(graphics2, 387, 218, &pellet);
	App->render->Blit(graphics2, 387, 201, &pellet);
	App->render->Blit(graphics2, 387, 184, &pellet);
	App->render->Blit(graphics2, 387, 167, &pellet);
	App->render->Blit(graphics2, 387, 150, &pellet);
	App->render->Blit(graphics2, 387, 133, &pellet);
	App->render->Blit(graphics2, 19, 422, &pellet);
	App->render->Blit(graphics2, 35, 422, &pellet);
	App->render->Blit(graphics2, 67, 422, &pellet);
	App->render->Blit(graphics2, 83, 422, &pellet);
	App->render->Blit(graphics2, 99, 422, &pellet);
	App->render->Blit(graphics2, 115, 422, &pellet);
	App->render->Blit(graphics2, 131, 422, &pellet);
	App->render->Blit(graphics2, 147, 422, &pellet);
	App->render->Blit(graphics2, 163, 422, &pellet);
	App->render->Blit(graphics2, 179, 422, &pellet);
	App->render->Blit(graphics2, 195, 422, &pellet);
	App->render->Blit(graphics2, 211, 422, &pellet);
	App->render->Blit(graphics2, 227, 422, &pellet);
	App->render->Blit(graphics2, 243, 422, &pellet);
	App->render->Blit(graphics2, 259, 422, &pellet);
	App->render->Blit(graphics2, 275, 422, &pellet);
	App->render->Blit(graphics2, 291, 422, &pellet);
	App->render->Blit(graphics2, 307, 422, &pellet);
	App->render->Blit(graphics2, 323, 422, &pellet);
	App->render->Blit(graphics2, 339, 422, &pellet);
	App->render->Blit(graphics2, 355, 422, &pellet);
	App->render->Blit(graphics2, 371, 422, &pellet);
	App->render->Blit(graphics2, 403, 422, &pellet);
	App->render->Blit(graphics2, 419, 422, &pellet);
	App->render->Blit(graphics2, 19, 438, &pellet);
	App->render->Blit(graphics2, 19, 454, &pellet);
	App->render->Blit(graphics2, 19, 470, &pellet);
	App->render->Blit(graphics2, 19, 486, &pellet);
	App->render->Blit(graphics2, 19, 502, &pellet);
	App->render->Blit(graphics2, 19, 518, &pellet);
	App->render->Blit(graphics2, 419, 438, &pellet);
	App->render->Blit(graphics2, 419, 454, &pellet);
	App->render->Blit(graphics2, 419, 470, &pellet);
	App->render->Blit(graphics2, 419, 486, &pellet);
	App->render->Blit(graphics2, 419, 502, &pellet);
	App->render->Blit(graphics2, 419, 518, &pellet);
	App->render->Blit(graphics2, 35, 518, &pellet);
	App->render->Blit(graphics2, 51, 518, &pellet);
	App->render->Blit(graphics2, 67, 518, &pellet);
	App->render->Blit(graphics2, 83, 518, &pellet);
	App->render->Blit(graphics2, 99, 518, &pellet);
	App->render->Blit(graphics2, 99, 438, &pellet);
	App->render->Blit(graphics2, 99, 454, &pellet);
	App->render->Blit(graphics2, 99, 470, &pellet);
	App->render->Blit(graphics2, 99, 486, &pellet);
	App->render->Blit(graphics2, 99, 502, &pellet);
	App->render->Blit(graphics2, 115, 518, &pellet);
	App->render->Blit(graphics2, 131, 518, &pellet);
	App->render->Blit(graphics2, 147, 518, &pellet);
	App->render->Blit(graphics2, 163, 518, &pellet);
	App->render->Blit(graphics2, 179, 518, &pellet);
	App->render->Blit(graphics2, 195, 518, &pellet);
	App->render->Blit(graphics2, 211, 518, &pellet);
	App->render->Blit(graphics2, 227, 518, &pellet);
	App->render->Blit(graphics2, 243, 518, &pellet);
	App->render->Blit(graphics2, 259, 518, &pellet);
	App->render->Blit(graphics2, 275, 518, &pellet);
	App->render->Blit(graphics2, 291, 518, &pellet);
	App->render->Blit(graphics2, 307, 518, &pellet);
	App->render->Blit(graphics2, 323, 518, &pellet);
	App->render->Blit(graphics2, 339, 518, &pellet);
	App->render->Blit(graphics2, 355, 518, &pellet);
	App->render->Blit(graphics2, 371, 518, &pellet);
	App->render->Blit(graphics2, 387, 518, &pellet);
	App->render->Blit(graphics2, 403, 518, &pellet);
	App->render->Blit(graphics2, 419, 518, &pellet);
	App->render->Blit(graphics2, 339, 502, &pellet);
	App->render->Blit(graphics2, 339, 486, &pellet);
	App->render->Blit(graphics2, 339, 470, &pellet);
	App->render->Blit(graphics2, 339, 454, &pellet);
	App->render->Blit(graphics2, 339, 438, &pellet);
	App->render->Blit(graphics2, 99, 133, &pellet);
	App->render->Blit(graphics2, 99, 150, &pellet);
	App->render->Blit(graphics2, 99, 167, &pellet);
	App->render->Blit(graphics2, 99, 184, &pellet);
	App->render->Blit(graphics2, 115, 184, &pellet);
	App->render->Blit(graphics2, 131, 184, &pellet);
	App->render->Blit(graphics2, 147, 184, &pellet);
	App->render->Blit(graphics2, 163, 184, &pellet);
	App->render->Blit(graphics2, 179, 184, &pellet);
	App->render->Blit(graphics2, 195, 184, &pellet);
	App->render->Blit(graphics2, 195, 167, &pellet);
	App->render->Blit(graphics2, 195, 150, &pellet);
	App->render->Blit(graphics2, 195, 184, &pellet);
	App->render->Blit(graphics2, 195, 184, &pellet);
	App->render->Blit(graphics2, 339, 184, &pellet);
	App->render->Blit(graphics2, 323, 184, &pellet);
	App->render->Blit(graphics2, 307, 184, &pellet);
	App->render->Blit(graphics2, 291, 184, &pellet);
	App->render->Blit(graphics2, 195, 133, &pellet);
	App->render->Blit(graphics2, 275, 184, &pellet);
	App->render->Blit(graphics2, 259, 184, &pellet);
	App->render->Blit(graphics2, 243, 184, &pellet);


	App->render->Blit(graphics2, 15, 77, &powerpellet);
	App->render->Blit(graphics2, 415, 77, &powerpellet);
	App->render->Blit(graphics2, 415, 482, &powerpellet);
	App->render->Blit(graphics2, 15, 482, &powerpellet);
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->level_one,App->start,1);
		
	}


	return UPDATE_CONTINUE;
}