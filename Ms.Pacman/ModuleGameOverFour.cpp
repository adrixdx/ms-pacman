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
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleAudio.h"
#include "ModuleGameOver.h"
#include "ModuleGameOverTwo.h"
#include "ModuleGameOverThree.h"
#include "ModuleGameOverFour.h"
#include "ModuleWin.h"



ModuleGameOverFour::ModuleGameOverFour()
{
	ground04 = { 0, 0, 448, 576 };

}

ModuleGameOverFour::~ModuleGameOverFour()
{}

// Load assets
bool ModuleGameOverFour::Start()
{

	graphics = App->textures->Load("Game/GameOver4.png");
	App->audio->PlayMusic("nothing.ogg", 1.0f);


	App->audio->Disable();
	App->player->Disable();
	App->blinky->Disable();
	return true;
}

// UnLoad assets
bool ModuleGameOverFour::CleanUp()
{
	LOG("Unloading gameover scene");
	App->audio->Disable();


	return true;
}

// Update: draw background
update_status ModuleGameOverFour::Update()
{
	App->render->Blit(graphics, 0, 0, &ground04);


	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN){

		App->fade->FadeToBlack(this, App->start, 1);

	}


	return UPDATE_CONTINUE;
}