#pragma once
#include <SDL.h>

class Affichage
{
public :

	Affichage();

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	bool init();

	void drawGrid();

	void close();

};