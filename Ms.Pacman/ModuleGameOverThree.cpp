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
#include "ModuleWin.h"



ModuleGameOverThree::ModuleGameOverThree()
{
	ground03 = { 0, 0, 448, 576 };

}

ModuleGameOverThree::~ModuleGameOverThree()
{}

// Load assets
bool ModuleGameOverThree::Start()
{

	graphics = App->textures->Load("Game/GameOver3.png");
	App->audio->PlayMusic("nothing.ogg", 1.0f);


	App->audio->Disable();
	App->player->Disable();
	App->blinky->Disable();
	return true;
}

// UnLoad assets
bool ModuleGameOverThree::CleanUp()
{
	LOG("Unloading gameover scene");
	App->audio->Disable();


	return true;
}

// Update: draw background
update_status ModuleGameOverThree::Update()
{
	App->render->Blit(graphics, 0, 0, &ground03);


	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN){

		App->fade->FadeToBlack(this, App->start, 1);

	}


	return UPDATE_CONTINUE;
}