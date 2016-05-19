#ifndef __MODULEREADYFOUR_H__
#define __MODULEREADYFOUR_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleReadyFour : public Module
{
public:
	ModuleReadyFour();
	~ModuleReadyFour();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground4;

	Animation square;
	Animation gname;
	Animation blinky;
	int time = 0;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEREADYFOUR_H__