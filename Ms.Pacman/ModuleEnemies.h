#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleEnemies : public Module
{
public:
	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation right;
	Animation left;
	Animation up;
	Animation down;
	iPoint position;
	Collider* col;
	bool destroyed = false;

};

#endif