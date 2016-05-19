#ifndef __ModuleINKY__
#define __ModuleINKY__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleEnemies.h"


struct SDL_Texture;

class ModuleInky : public Module
{
private:
	bool enabled = true;
public:
	ModuleInky();
	~ModuleInky();

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
	Animation scared;
	Animation scared2;
	Animation a_hor;
	Animation a_vert;
	iPoint position;
	Collider* col;
	bool turn;
	bool destroyed = false;
	int direction;
	unsigned int time = 0;
	bool debug = false;

};

#endif