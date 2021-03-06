#include "j1HUD.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Player.h"
#include "j1Game.h"
#include "j1SceneManager.h"
#include "snIntro.h"
#include "hudElement.h"
#include "hudBelt.h"
#include "hudPause.h"
#include "hudInventory.h"


//NOTE : provisional
#include "j1Input.h"

//Constructor
j1HUD::j1HUD() : j1Module()
{
	belt = new hudBelt();
	pause_menu = new hudPause();
	inventory = new hudInventory();
	
	HUD_elements.push_back(inventory);
	HUD_elements.push_back(belt);
	HUD_elements.push_back(pause_menu);
}

j1HUD::~j1HUD()
{
	for (int i = 0; i < HUD_elements.size(); i++)
	{
		RELEASE(HUD_elements[i]);
	}

	HUD_elements.clear();
}

bool j1HUD::Start()
{
	for (int i = 0; i < HUD_elements.size(); i++)
	{
		HUD_elements[i]->Start();
	}

	return true;
}

//Called before each loop iteration
bool j1HUD::PreUpdate()
{

	for (int i = 0; i < HUD_elements.size(); i++)
	{
		HUD_elements[i]->PreUpdate();
	}

	return true;
}

//Called each frame
bool j1HUD::Update(float dt)
{	
	for (int i = 0; i < HUD_elements.size(); i++)
	{
		HUD_elements[i]->Update(dt);
	}


	return true;
}

//Called after each loop iteration
bool j1HUD::PostUpdate()
{
	for (int i = 0; i < HUD_elements.size(); i++)
	{
		HUD_elements[i]->PostUpdate();
	}

	return true;
}

bool j1HUD::CleanUp()
{
	for (int i = 0; i < HUD_elements.size(); i++)
	{
		HUD_elements[i]->CleanUp();
	}

	return true;
}

void j1HUD::OnEvent(GuiElement* element, GUI_Event even)
{

}




