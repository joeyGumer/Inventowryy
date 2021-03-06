#ifndef _HUDBELT_H_
#define _HUDBELT_H_

#include "hudElement.h"

enum GUI_Event;
class j1HUD;
class GuiElement;
class GuiImage;
class GuiLabel;


#define STAT_LOCAL_Y 33
#define STAT_TEX_Y 196
#define STAT_MAX_H float(78)

//NOTE : Do HUD Elements
class hudBelt : public hudElement
{
public:
	//Constructor
	hudBelt();

	//Destructor
	~hudBelt();

	//Called before fist frame
	bool Start();

	//Called before each loop iteration
	bool PreUpdate();

	//Called each frame
	bool Update(float dt);

	//Called after each loop iteration
	bool PostUpdate();

	//Called before quitting
	bool CleanUp();

	//Called when there's a gui event
	void OnEvent(GuiElement* element, GUI_Event even);

	//Utils
	void SetLife(int max_HP, int HP);
	void SetMana(int max_MP, int MP);

public:

	//Life
	float life_current_h;

	//Mana
	float mana_current_h;

	//Some buttons bools
	bool run_pressed = false;
	bool minipanel_pressed = false;

	//Belt Gui Elements
	GuiImage* HUD = NULL;
	GuiImage* HUDback1 = NULL;
	GuiImage* HUDback2 = NULL;
	GuiImage* life = NULL;
	GuiImage* mana = NULL;
	GuiImage* life_holder = NULL;
	GuiImage* mana_holder = NULL;
	GuiImage* runbutton = NULL;
	GuiImage* minipanelbutton = NULL;
	GuiImage* stats = NULL;
	GuiImage* skilltree = NULL;
	GuiImage* inventory = NULL;
	GuiImage* map = NULL;
	GuiImage* message_log = NULL;
	GuiImage* search_log = NULL;
	GuiImage* game_menu = NULL;
	GuiImage* attack1 = NULL;
	GuiImage* attack2 = NULL;

	//NOTE : labels for debug:
	GuiLabel* life_debug;
	GuiLabel* mana_debug;
};


#endif _HUDBELT_H_