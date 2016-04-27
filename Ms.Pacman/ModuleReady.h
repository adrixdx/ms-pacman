#ifndef __MODULEREADY_H__
#define __MODULEREADY_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleReady : public Module
{
public:
	ModuleReady();
	~ModuleReady();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;

	Animation square;
	Animation gname;
	Animation blinky;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEREADY_H__