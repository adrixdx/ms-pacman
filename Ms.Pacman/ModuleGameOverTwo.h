#ifndef __MODULEGAMEOVERTWO_H__
#define __MODULESGAMEOVERTWO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleGameOverTwo : public Module
{
public:
	ModuleGameOverTwo();
	~ModuleGameOverTwo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground02;

	float foreground_pos;
	bool forward;
};

#endif // __MODULEGAMEOVERTWO_H__