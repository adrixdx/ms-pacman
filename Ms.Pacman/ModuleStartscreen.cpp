#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleStartScreen.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"
#include "ModuleAudio.h"

#include "ModuleLevelOne.h"
#include "ModuleLevelTwo.h"
#include "ModuleLevelThree.h"
#include "ModuleLevelFour.h"

#include "ModuleReady.h"
#include "ModuleReadyTwo.h"
#include "ModuleReadyThree.h"
#include "ModuleReadyFour.h"

#include "ModuleGameOver.h"
#include "ModuleGameOverTwo.h"
#include "ModuleGameOverThree.h"
#include "ModuleGameOverFour.h"



ModuleStartScreen::ModuleStartScreen()
{

	ground = { 30, 0, 481, 639 };
	mspacman = { 2048, 181, 37, 35 };
	blinky = { 2015, 219, 31, 30 };
	pinky = { 2015, 288, 31, 30 };
	inky = { 521, 97, 14, 14 };
	sue = { 2015, 323, 31, 30 };


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
	
	gname.speed = 0.002f;

	//ghosts blinky
	/*
	blinky.PushBack({ 2015, 219, 31, 30, });
	blinky.PushBack({ 2050, 219, 31, 30, });
	blinky.speed = 0.15f;*/
	blinky_left.PushBack({ 2086, 219, 31, 30 });
	blinky_left.PushBack({ 2121, 219, 31, 30 });
	blinky_up.speed = 0.1f;
	blinky_up.PushBack({ 2015, 219, 31, 30 });
	blinky_up.PushBack({ 2050, 219, 31, 30 });
	blinky_up.speed = 0.1f;
	position_r.x = 448;
	position_r.y = 371;


	//ghosts inky
	/*
	inky.PushBack({ 2015, 254, 31, 30, });
	inky.PushBack({ 2050, 254, 31, 30, });
	inky.speed = 0.15f;*/
	//ghosts pinky
	pinky_left.PushBack({ 2086, 288, 31, 30 });
	pinky_left.PushBack({ 2121, 288, 31, 30 });
	pinky_left.speed = 0.1f;
	pinky_up.PushBack({ 2015, 288, 31, 30 });
	pinky_up.PushBack({ 2050, 288, 31, 30 });
	pinky_up.speed = 0.1f;
	position_p.x = 448;
	position_p.y = 371;

	//ghosts pinky
	/*
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
	*/
	//ghosts inky
	inky_left.PushBack({ 2086, 254, 31, 30 });
	inky_left.PushBack({ 2121, 254, 31, 30 });
	inky_left.speed = 0.1f;
	inky_up.PushBack({ 2015, 254, 31, 30 });
	inky_up.PushBack({ 2050, 254, 31, 30 });
	inky_up.speed = 0.1f;
	position_b.x = 448;
	position_b.y = 371;


	//ghosts sue
	sue_left.PushBack({ 2086, 323, 31, 30 });
	sue_left.PushBack({ 2121, 323, 31, 30 });
	sue_left.speed = 0.1f;
	sue_up.PushBack({ 2015, 323, 31, 30 });
	sue_up.PushBack({ 2050, 323, 31, 30 });
	sue_up.speed = 0.1f;
	position_o.x = 448;
	position_o.y = 371;

	// Ms. Pac-Man
	backward.PushBack({ 2012, 182, 37, 35 });
	backward.PushBack({ 2048, 181, 37, 35 });
	backward.PushBack({ 2083, 181, 37, 35 });
	backward.PushBack({ 2048, 181, 37, 35 });
	backward.speed = 0.3f;
	position_ms.x = 448;
	position_ms.y = 371;



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

	App->level_one->Disable();
	App->level_two->Disable();
	App->level_three->Disable();
	App->level_four->Disable();

	App->ready->Disable();
	App->ready_two->Disable();
	App->ready_three->Disable();
	App->ready_four->Disable();

	App->gameover->Disable();
	App->gameover_two->Disable();
	App->gameover_three->Disable();
	App->gameover_four->Disable();

	time_blinky = SDL_GetTicks();
	time_pinky = 10000000;
	time_inky = 1000000;
	time_sue = 1000000;
	time_pacman = 100000;

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

/*	App->render->Blit(graphics, 55, 170, &(blinky.GetCurrentFrame()), 0.75f); // blinky
	App->render->Blit(graphics, 55, 208, &(inky.GetCurrentFrame()), 0.75f); // inky
	App->render->Blit(graphics, 55, 240, &(pinky.GetCurrentFrame()), 0.75f); // pinky
	App->render->Blit(graphics, 55, 275, &(sue.GetCurrentFrame()), 0.75f); // sue
	App->render->Blit(graphics, 210, 325, &(mspacman.GetCurrentFrame()), 0.75f); // mspacman
	*/
	float speed = 2;

	//BLINKY
	if (SDL_GetTicks() - time_blinky < 10000){

		if (position_r.x == 50 && position_r.y > 220){

			current_animation_r = &blinky_up;
			position_r.y -= speed;
			if (position_r.y == 223){
				time_pinky = SDL_GetTicks();
			}
		}
		else if (position_r.x >50){

			current_animation_r = &blinky_left;
			position_r.x -= speed;
		}
	}

	//PINKY
	if (SDL_GetTicks() - time_pinky < 10000){

		if (position_b.x == 50 && position_b.y > 260){

			current_animation_p = &pinky_up;
			position_b.y -= speed;
			if (position_b.y == 263){
				time_inky = SDL_GetTicks();
			}
		}

		else if (position_b.x > 50){

			current_animation_p = &pinky_left;
			position_b.x -= speed;
		}

	}

	//INKY
	if (SDL_GetTicks() - time_inky < 10000){
		if (position_p.x == 50 && position_p.y > 300){

			current_animation_b = &inky_up;
			position_p.y -= speed;

			if (position_p.y == 303){
				time_sue = SDL_GetTicks();
			}
		}
		else if (position_p.x > 50)
		{
			current_animation_b = &inky_left;
			position_p.x -= speed;
		}
	}

	//SUE
	if (SDL_GetTicks() - time_sue < 10000)
	{
		if (position_o.x == 50 && position_o.y > 340)
		{
			current_animation_o = &sue_up;
			position_o.y -= speed;
			if (position_o.y == 343){
				time_pacman = SDL_GetTicks();
			}
		}
		else if (position_o.x > 50)
		{
			current_animation_o = &sue_left;
			position_o.x -= speed;
		}
	}

	//Ms Pac Man
	if (SDL_GetTicks() - time_pacman < 10000)
	{
		if (position_ms.x > 224)
		{
			current_animation_ms = &backward;
			position_ms.x -= speed;
			if (position_ms.x == 224){
				gname.speed == 0.0f;
			}
		}
	}

	SDL_Rect r = current_animation_ms->GetCurrentFrame();

	SDL_Rect r_r = current_animation_r->GetCurrentFrame();
	SDL_Rect r_p = current_animation_p->GetCurrentFrame();
	SDL_Rect r_o = current_animation_o->GetCurrentFrame();
	SDL_Rect r_b = current_animation_b->GetCurrentFrame();

	//App->render->Blit(graphics, 0, -20, &ground);
	//App->render->Blit(graphics, 90, 167, &(squareinit.GetCurrentFrame()), 0.75f); //squareinit animation
	//App->render->Blit(graphics, 90, 167, &(square.GetCurrentFrame()), 0.75f); // square animation

	//MSPACMAN
	if (position_ms.x == 120)
	{
		App->render->Blit(graphics, position_ms.x, position_ms.y - r.h, &mspacman);
	}
	else if (position_ms.x > 120)
	{
		App->render->Blit(graphics, position_ms.x, position_ms.y - r.h, &r);
	}

	//GHOST BLINKY
	if (position_r.y == 100)
	{
		App->render->Blit(graphics, position_r.x, position_r.y - r_r.h, &blinky);
	}
	else if (position_r.y > 100)
	{
		App->render->Blit(graphics, position_r.x, position_r.y - r_r.h, &r_r);
	}

	//PINKY
	if (position_p.y == 116)
	{
		App->render->Blit(graphics, position_p.x, position_p.y - r_p.h, &pinky);
	}
	else if (position_p.y > 116)
	{
		App->render->Blit(graphics, position_p.x, position_p.y - r_p.h, &r_p);
	}

	//INKY
	if (position_b.y == 132)
	{
		App->render->Blit(graphics, position_b.x, position_b.y - r_b.h, &inky);
	}
	else if (position_b.y > 132)
	{
		App->render->Blit(graphics, position_b.x, position_b.y - r_b.h, &r_b);
	}


	//SUE
	if (position_o.y == 148)
	{
		App->render->Blit(graphics, position_o.x, position_o.y - r_o.h, &sue);
	}
	else if (position_o.y > 148)
	{
		App->render->Blit(graphics, position_o.x, position_o.y - r_o.h, &r_o);
	}

	//FADE TO BLACK
	if (App->input->keyboard[SDL_SCANCODE_SPACE]){

		App->fade->FadeToBlack(App->start, App->ready, 1);

	}

	App->render->Blit(graphics, 110, 190, &(gname.GetCurrentFrame()), 0.75f); // ghost name animation
	return UPDATE_CONTINUE;
}