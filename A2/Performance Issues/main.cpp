/*
Assignment 2 CSC205
Rafael Solorzano
V00838235
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "vector2d.h"
#include "colourRGB.h"
#include "level1.h"
#include "lose.h"
#include "menu.h"
#include "win.h"

using namespace std;

static const int WINDOW_SIZE_X = 800;
static const int WINDOW_SIZE_Y = 600;



int main(){

	SDL_Window* window = SDL_CreateWindow("CSC 205 A2",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_SIZE_X, WINDOW_SIZE_Y, 
							  SDL_WINDOW_SHOWN);
							  
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0/*SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED*/);

	//Initialize the canvas to solid green
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	Menu menu;
	Level1 level1;
	Lose lose;
	Win win;
	bool quit = false;



	menu.frame_loop_menu(renderer, &level1);
	int won = level1.frame_loop2(renderer);
	if (won == 1){
		win.frame_loop_win(renderer);
	} else if (won == -1){
		lose.frame_loop_lose(renderer);
	} else {
		exit(0);
	}


	



	return 0;
}
