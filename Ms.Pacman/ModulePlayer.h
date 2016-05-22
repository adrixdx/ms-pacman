#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

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
	Animation g_right;
	Animation g_left;
	Animation g_up;
	Animation g_down;

	//Numbers;
	Animation n_0;
	Animation n_1;
	Animation n_2;
	Animation n_3;
	Animation n_4;
	Animation n_5;
	Animation n_6;
	Animation n_7;
	Animation n_8;
	Animation n_9;
	
	iPoint position;
	Collider* col;
	Collider* col2;
	bool destroyed = false;
	bool power = false;
	bool god = false;
	unsigned int time = 0;
	int dir = 0;
	int n_map = 0;
	int s_map[36][28];
	uint points = 0;

};

#endif