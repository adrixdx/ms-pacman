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
#include "ModuleReady.h"



ModuleStartScreen::ModuleStartScreen()
{

	ground = { 30, 0, 481, 639 };


	// square lights animation
	square.PushBack({ 488, 2, 310, 157,});
	square.PushBack({ 488, 161, 310, 157, });
	square.PushBack({ 488, 319, 310, 157, });
	square.PushBack({ 488, 478, 310, 157, });

	square.PushBack({ 803, 2, 310, 157,});
	square.PushBack({ 803, 161, 310, 157, });
	square.PushBack({ 803, 319, 310, 157, });
	square.PushBack({ 803, 478, 310, 157, });

	square.PushBack({ 1116, 2, 310, 157, });
	square.PushBack({ 1116, 161, 310, 157, });
	square.PushBack({ 1116, 319, 310, 157, });
	square.PushBack({ 1116, 478, 310, 157, });

	square.PushBack({ 1430, 2, 310, 157, });
	square.PushBack({ 1430, 161, 310, 157, });
	square.PushBack({ 1430, 319, 310, 157, });
	square.PushBack({ 1430, 478, 310, 157, });

	square.speed = 0.81f;
	
	// ghost name animation
	gname.PushBack({ 1742, 16, 216, 98, });
	gname.PushBack({ 1742, 117, 234, 108, });
	gname.PushBack({ 1745, 224, 241, 108, });
	gname.PushBack({ 1746, 322, 226, 93, });
	gname.PushBack({ 1960, 16, 216, 98, });
	
	gname.speed = 0.004f;

	//ghosts
	blinky.PushBack({ 1742, 16, 216, 98, });

}

ModuleStartScreen::~ModuleStartScreen()
{}

// Load assets
bool ModuleStartScreen::Start()
 {
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("New/start.png");
	App->audio->PlayMusic("game-start.ogg", 1.0f);

	App->player->Disable();
	App->blinky->Disable();
	App->gameover->Disable();
	App->ready->Disable();
	return true;
}

// UnLoad assets
bool ModuleStartScreen::CleanUp()
{
	LOG("Unloading ken scene");
	App->audio->Disable();
	return true;
}

// Update: draw background
update_status ModuleStartScreen::Update()
{
	//Animations
	App->render->Blit(graphics, 0, -20, &ground);
	App->render->Blit(graphics, 90, 167, &(square.GetCurrentFrame()), 0.75f); // square animation
	App->render->Blit(graphics, 110, 190, &(gname.GetCurrentFrame()), 0.75f); // ghost name animation

	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->start, App->ready, 1);

	}


	return UPDATE_CONTINUE;
}