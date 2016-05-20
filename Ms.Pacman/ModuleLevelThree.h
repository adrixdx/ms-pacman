#ifndef __MODULELEVELTHREE_H__
#define __MODULELEVELTHREE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevelThree : public Module
{
public:
	ModuleLevelThree();
	~ModuleLevelThree();

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
	uint fx = 0;
	static int map[36][28];
	int pellets = 234;
};

#endif // __MODULELEVELTHREE_H__