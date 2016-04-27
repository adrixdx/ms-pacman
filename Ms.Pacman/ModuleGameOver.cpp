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
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleAudio.h"
#include "ModuleGameOver.h"



ModuleGameOver::ModuleGameOver()
{
	ground = { 0, 0, 448, 576 };

	

	

}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("game/GameOver.png");
	

	App->player->Disable();
	App->blinky->Disable();
	return true;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading gameover scene");
	App->audio->Disable();
	return true;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	App->render->Blit(graphics, 0, 0, &ground);
	//Animations
	
	App->render->Blit(graphics, 90, 167, &(square.GetCurrentFrame()), 0.75f); // square animation
	App->render->Blit(graphics, 110, 190, &(gname.GetCurrentFrame()), 0.75f); // ghost name animation

	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->start, App->gameover, 1);

	}


	return UPDATE_CONTINUE;
}