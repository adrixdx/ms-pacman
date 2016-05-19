#ifndef __MODULEREADYTHREE_H__
#define __MODULEREADYTHREE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleReadyThree : public Module
{
public:
	ModuleReadyThree();
	~ModuleReadyThree();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground3;

	Animation square;
	Animation gname;
	Animation blinky;
	int time = 0;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEREADYTHREE_H__