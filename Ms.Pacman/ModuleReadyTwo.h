#ifndef __MODULEREADYTWO_H__
#define __MODULEREADYTWO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleReadyTwo : public Module
{
public:
	ModuleReadyTwo();
	~ModuleReadyTwo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground2;

	Animation square;
	Animation gname;
	Animation blinky;
	int time = 0;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEREADYTWO_H__