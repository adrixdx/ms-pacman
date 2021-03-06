#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"


#define NUM_MODULES 28


class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleStartScreen;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleParticles;
class ModuleCollision;
class ModuleAudio;

class ModuleEnemies;
class ModuleBlinky;
class ModuleSue;
class ModulePinky;
class ModuleInky;

class Module;
class ModuleWin;

class ModuleLevelOne;
class ModuleLevelThree;
class ModuleLevelTwo;
class ModuleLevelFour;

class ModuleReady;
class ModuleReadyTwo;
class ModuleReadyThree;
class ModuleReadyFour;

class ModuleGameOver;
class ModuleGameOverTwo;
class ModuleGameOverThree;
class ModuleGameOverFour;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleEnemies* enemies;
	ModuleAudio* audio;

	ModuleStartScreen* start;
	ModuleLevelOne* level_one;
	ModuleLevelThree* level_three;
	ModuleLevelTwo* level_two;
	ModuleLevelFour* level_four;
	
	ModuleReady* ready;
	ModuleReadyTwo* ready_two;
	ModuleReadyThree* ready_three;
	ModuleReadyFour* ready_four;

	ModuleGameOver* gameover;
	ModuleGameOverTwo* gameover_two;
	ModuleGameOverThree* gameover_three;
	ModuleGameOverFour* gameover_four;

	ModuleBlinky* blinky;
	ModuleSue* sue;
	ModuleInky* inky;
	ModulePinky* pinky;

	ModuleWin* win;


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__