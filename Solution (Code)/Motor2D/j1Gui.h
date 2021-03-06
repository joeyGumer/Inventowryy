#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
//I'm doing trap here...
//So i can take this out i have to change the constructors..., i'll do it later
#include "GuiElements.h"
#include <list>
;
class GuiInventory;
class GuiItem;

#define CURSOR_WIDTH 2

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Gui creation functions
	GuiImage* AddGuiImage(iPoint p, SDL_Rect r, GuiElement* par, j1Module* list);
	GuiLabel* AddGuiLabel(p2SString t, _TTF_Font* f, iPoint p, GuiElement* par, j1Module* list);
	GuiInputBox* AddGuiInputBox(p2SString t, _TTF_Font* f, iPoint p, int width, SDL_Rect r, iPoint offset, GuiElement* par, j1Module* list);
	GuiButton* AddGuiButton(iPoint p, SDL_Rect idle_r1, SDL_Rect hover_r1, SDL_Rect click_r1, p2SString t = "", _TTF_Font* f = NULL, j1Module* list = NULL, GuiElement* parent = NULL);

	//Function that creates an inventory
	GuiInventory* AddGuiInventory(iPoint p, SDL_Rect r, int columns, int rows, int slot_w, int slot_h, GuiElement* par = NULL, j1Module* list = NULL);

	GuiSlider* AddGuiSlider(iPoint p, SDL_Rect tex_1, SDL_Rect tex_2, int width, int thumb_h, iPoint offset, float value, GuiElement* par, j1Module* list);

	GuiMouseImage* AddGuiMouseImage(iPoint p, SDL_Rect r, GuiElement* par, j1Module* list);

	//Get selected element
	GuiElement* FindSelectedElement();

	SDL_Texture* GetAtlas() const;

public:

	list<GuiElement*> gui_elements;
	
	//The dragged item (goes directly at the GUI so it draws over everything and can go to other inventories
	GuiItem*		dragged_item = NULL;

	bool			interaction;

private:
	bool			debug;
	SDL_Texture*	atlas;
	p2SString		atlas_file_name;
	int             mouse_x, mouse_y;

	GuiElement*		focus;
	GuiMouseImage*	mouse = NULL;
};

#endif // __j1GUI_H__