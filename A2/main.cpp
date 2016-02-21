/* sample_ball.cpp
Assignment 2 CSC205
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
	menu.frame_loop_menu(renderer);

	A2Canvas2 canvas;

	canvas.frame_loop2(renderer);
	printf("first level ended/n");
	//canvas.frame_loop2(renderer)
	Lose lose;
	lose.frame_loop_lose(renderer);

	

	return 0;
}
