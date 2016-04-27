#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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

	Animation square;
	Animation gname;
	Animation blinky;
	Animation inky;
	Animation pinky;
	Animation sue;
	Animation mspacman;


	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENEKEN_H__