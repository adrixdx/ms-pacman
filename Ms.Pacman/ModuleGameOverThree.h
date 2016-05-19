#ifndef __MODULEGAMEOVERTHREE_H__
#define __MODULESGAMEOVERTHREE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleGameOverThree : public Module
{
public:
	ModuleGameOverThree();
	~ModuleGameOverThree();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground03;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEGAMEOVERTHREE_H__