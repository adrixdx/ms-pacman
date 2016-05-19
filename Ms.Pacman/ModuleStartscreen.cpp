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
#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"
#include "ModuleAudio.h"
#include "ModuleGameOver.h"
#include "ModuleReady.h"
#include "ModuleLevelThree.h"
#include "ModuleLevelFour.h"
#include "ModuleLevelTwo.h"
#include "ModuleReadyTwo.h"
#include "ModuleReadyThree.h"



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
	gname.PushBack({ 1960, 16, 216, 98, });
	gname.PushBack({ 1960, 16, 216, 98, });
	
	gname.speed = 0.004f;

	//ghosts blinky
	blinky.PushBack({ 2015, 219, 31, 30, });
	blinky.PushBack({ 2050, 219, 31, 30, });
	blinky.speed = 0.15f;

	//ghosts inky
	inky.PushBack({ 2015, 254, 31, 30, });
	inky.PushBack({ 2050, 254, 31, 30, });
	inky.speed = 0.15f;

	//ghosts pinky
	pinky.PushBack({ 2015, 288, 31, 30, });
	pinky.PushBack({ 2050, 288, 31, 30, });
	pinky.speed = 0.15f;

	//ghosts sue
	sue.PushBack({ 2015, 323, 31, 30, });
	sue.PushBack({ 2050, 323, 31, 30, });
	sue.speed = 0.15f;

	// Ms. Pac-Man
	mspacman.PushBack({ 2012, 182, 37, 35, });
	mspacman.PushBack({ 2048, 181, 37, 35, });
	mspacman.PushBack({ 2083, 181, 37, 35, });
	mspacman.PushBack({ 2048, 181, 37, 35, });
	mspacman.speed = 0.2f;

}

ModuleStartScreen::~ModuleStartScreen()
{}

// Load assets
bool ModuleStartScreen::Start()
 {

	LOG("Loading ken scene");
	
	graphics = App->textures->Load("start.png");
	App->audio->PlayMusic("nothing.ogg", 1.0f);


	App->player->Disable();

	App->blinky->Disable();
	App->sue->Disable();
	App->pinky->Disable();
	App->inky->Disable();

	App->gameover->Disable();
	App->level_one->Disable();
	App->level_three->Disable();
	App->level_four->Disable();
	App->level_two->Disable();
	App->ready->Disable();
	App->ready_two->Disable();
	App->ready_three->Disable();
	return true;
}

// UnLoad assets
bool ModuleStartScreen::CleanUp()
{
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

	App->render->Blit(graphics, 55, 170, &(blinky.GetCurrentFrame()), 0.75f); // blinky
	App->render->Blit(graphics, 55, 208, &(inky.GetCurrentFrame()), 0.75f); // inky
	App->render->Blit(graphics, 55, 240, &(pinky.GetCurrentFrame()), 0.75f); // pinky
	App->render->Blit(graphics, 55, 275, &(sue.GetCurrentFrame()), 0.75f); // sue
	App->render->Blit(graphics, 210, 325, &(mspacman.GetCurrentFrame()), 0.75f); // mspacman

	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->start, App->ready, 1);

	}


	return UPDATE_CONTINUE;
}