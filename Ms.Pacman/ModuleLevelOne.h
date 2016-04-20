#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevelOne : public Module
{
public:
	ModuleLevelOne();
	~ModuleLevelOne();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics1 = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect pellet;
	SDL_Rect powerpellet;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;
};

#endif // __MODULESCENEHONDA_H__