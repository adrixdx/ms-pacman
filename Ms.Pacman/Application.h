#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"


#define NUM_MODULES 26


class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleStartScreen;
class ModuleLevelOne;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleParticles;
class ModuleCollision;
class ModuleAudio;
class ModuleEnemies;
class ModuleBlinky;
class ModuleGameOver;
class ModuleReady;
class ModuleSue;
class ModulePinky;
class ModuleInky;
class Module;
class ModuleWin;
class ModuleLevelThree;
class ModuleLevelTwo;
class ModuleReadyTwo;
class ModuleLevelFour;
class ModuleReadyThree;
class ModuleReadyFour;

class ModuleGameOverTwo;


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
	ModuleGameOver* gameover;

	ModuleStartScreen* start;
	ModuleLevelOne* level_one;
	ModuleLevelThree* level_three;
	ModuleLevelTwo* level_two;
	ModuleLevelFour* level_four;
	
	ModuleReady* ready;
	ModuleReadyTwo* ready_two;
	ModuleReadyThree* ready_three;
	ModuleReadyFour* ready_four;

	ModuleGameOverTwo* gameover_two;

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