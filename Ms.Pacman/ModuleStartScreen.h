#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleBlinky.h"
#include "ModulePinky.h"
#include "ModuleInky.h"
#include "ModuleSue.h"

struct SDL_Texture;

class ModuleStartScreen : public Module
{
public:
	ModuleStartScreen();
	~ModuleStartScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;

	////NEW
	SDL_Rect blinky;
	SDL_Rect inky;
	SDL_Rect pinky;
	SDL_Rect sue;
	SDL_Rect mspacman;

	//new
	Animation* current_animation_ms = &backward;
	Animation backward;
	fPoint position_ms;

	//new
	Animation* current_animation_b = &blinky_left;
	Animation* current_animation_p = &pinky_left;
	Animation* current_animation_i = &inky_left;
	Animation* current_animation_s = &sue_left;

	Animation square;
	Animation gname;

	Animation blinky_up;
	Animation blinky_left;
	Animation pinky_up;
	Animation pinky_left;
	Animation inky_up;
	Animation inky_left;
	Animation sue_up;
	Animation sue_left;
	/*
	Animation blinky;
	Animation inky;
	Animation pinky;
	Animation sue;
	Animation mspacman;*/

	fPoint position_b;
	fPoint position_p;
	fPoint position_i;
	fPoint position_s;

	uint time_blinky = 0;
	uint time_inky = 0;
	uint time_pinky = 0;
	uint time_sue = 0;
	uint time_pacman;


	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENEKEN_H__