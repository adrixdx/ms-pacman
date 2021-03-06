#ifndef __ModuleBlinky__
#define __ModuleBlinky__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleEnemies.h"


struct SDL_Texture;

class ModuleBlinky : public Module
{
private:
	bool enabled = true;
public:
ModuleBlinky();
	~ModuleBlinky();

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

	Animation a_hor;
	Animation a_vert;
	

	Animation scared;
	Animation scared2;
	iPoint position;
	Collider* col;
	bool turn;
	bool destroyed = false;
	int direction;
	unsigned int time = 0;
	bool debug = false;

};

#endif