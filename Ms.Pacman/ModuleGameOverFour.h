#ifndef __MODULEGAMEOVERFOUR_H__
#define __MODULEGAMEOVERFOUR_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleGameOverFour : public Module
{
public:
	ModuleGameOverFour();
	~ModuleGameOverFour();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground04;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEGAMEOVERFOUR_H__