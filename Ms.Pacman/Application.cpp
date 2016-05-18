#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleStartScreen.h"
#include "ModuleLevelOne.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleGhost.h"
#include "ModuleEnemies.h"
#include "ModuleBlinky.h"
#include "ModuleSue.h"
#include "ModulePinky.h"
#include "ModuleInky.h"
#include "ModuleGameOver.h"
#include "ModuleLevelThree.h"
#include "ModuleLevelTwo.h"
#include "ModuleReadyTwo.h"

#include "ModuleReady.h"

#include "ModuleWin.h"




Application::Application()
{

	
	

	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = level_one = new ModuleLevelOne();
	modules[5] = start = new ModuleStartScreen();
	modules[6] = level_two = new ModuleLevelTwo();
	modules[7] = level_three = new ModuleLevelThree();


	modules[8] = fade = new ModuleFadeToBlack();
	modules[9] = particles = new ModuleParticles();
	modules[10] = collision = new ModuleCollision();

	modules[11] = player = new ModulePlayer();
	modules[12] = enemies = new ModuleEnemies();
	modules[13] = blinky = new ModuleBlinky();
	modules[14] = inky = new ModuleInky();
	modules[15] = sue = new ModuleSue();
	modules[16] = pinky = new ModulePinky();

	modules[17] = gameover = new ModuleGameOver();
	modules[18] = ready_two = new ModuleReadyTwo();
	modules[19] = ready = new ModuleReady();	
	modules[20] = win = new ModuleWin();

	modules[21] = audio = new ModuleAudio();




}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	// Disable the map that you do not start with
	level_one->Disable();
	level_two->Disable();
	level_three->Disable();
	ready->Disable();
	ready_two->Disable();
	win->Disable();
	gameover->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}