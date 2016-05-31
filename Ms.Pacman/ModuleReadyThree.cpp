#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleStartScreen.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevelOne.h"
#include "ModuleLevelTwo.h"
#include "ModuleLevelFour.h"
#include "ModuleLevelThree.h"
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleAudio.h"
#include "ModuleReadyThree.h"
#include "ModuleInky.h"
#include "ModulePinky.h"
#include "ModuleSue.h"



ModuleReadyThree::ModuleReadyThree()
{
	ground3 = { 0, 0, 448, 576 };

}

ModuleReadyThree::~ModuleReadyThree()
{}

// Load assets
bool ModuleReadyThree::Start()
{
	time = SDL_GetTicks();
	graphics = App->textures->Load("Game/P3Ready.png");
	App->audio->PlayMusic("Game/game-start.ogg", 1.0f);

	App->player->Disable();
	App->blinky->Disable();

	App->pinky->Disable();
	App->sue->Disable();
	App->inky->Disable();

	return true;
}

// UnLoad assets
bool ModuleReadyThree::CleanUp()
{
	LOG("Unloading gameover scene");
	App->audio->Disable();
	App->player->Disable();
	App->blinky->Disable();

	App->level_one->Disable();
	App->level_two->Disable();
	App->level_three->Disable();
	App->level_four->Disable();


	return true;
}

// Update: draw background
update_status ModuleReadyThree::Update()
{
	App->render->Blit(graphics, 0, 0, &ground3);


	//FADE TO BLACK
	//if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN){
	if (SDL_GetTicks() - time > 4500){

		App->ready_three->Disable();
		App->level_three->Enable();

		//App->fade->FadeToBlack(this, App->level_two, 1);

	}


	return UPDATE_CONTINUE;
}