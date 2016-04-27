#ifndef __ModuleSUE__
#define __ModuleSUE__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleEnemies.h"


struct SDL_Texture;

class ModuleSue : public Module
{
private:
	bool enabled = true;
public:
	ModuleSue();
	~ModuleSue();

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
	iPoint position;
	Collider* col;
	bool turn;
	bool destroyed = false;
	int direction;

};

#endif