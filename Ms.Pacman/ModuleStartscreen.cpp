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


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleStartScreen::ModuleStartScreen()
{

	ground = { 30, 0, 481, 639 };


	// square lights animation
	square.PushBack({ 492, 7, 299, 152,});
	square.PushBack({ 492, 163, 299 , 152, });
	square.PushBack({ 492, 320, 299, 152, });
	square.PushBack({ 492, 479, 299, 152, });

	square.PushBack({ 805, 7, 299, 152, });
	square.PushBack({ 805, 163, 299, 152, });
	square.PushBack({ 805, 320, 299, 152, });
	square.PushBack({ 805, 479, 299, 152, });

	square.PushBack({ 1117, 7, 299, 152, });
	square.PushBack({ 1117, 163, 299, 152, });
	square.PushBack({ 1117, 320, 299, 152, });
	square.PushBack({ 1117, 479, 299, 152, });

	square.PushBack({ 1430, 7, 299, 152, });
	square.PushBack({ 1430, 163, 299, 152, });
	square.PushBack({ 1430, 320, 299, 152, });
	square.PushBack({ 1430, 479, 299, 152, });

	square.speed = 0.85f;
	
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
	
	graphics = App->textures->Load("game/start.png");

	App->player->Disable();
	return true;
}

// UnLoad assets
bool ModuleStartScreen::CleanUp()
{
	LOG("Unloading ken scene");
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

		App->fade->FadeToBlack(App->start, App->level_one, 1);

	}


	return UPDATE_CONTINUE;
}