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
#include "final.h"

using namespace std;

static const int WINDOW_SIZE_X = 800;
static const int WINDOW_SIZE_Y = 900;



int main(){

	SDL_Window* window = SDL_CreateWindow("CSC 205 Project",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_SIZE_X, WINDOW_SIZE_Y, 
							  SDL_WINDOW_SHOWN);
							  
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	//Initialize the canvas to solid green
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	Menu menu;
	Level1 level1;
	Lose lose;
	Win win;
	FinalLevel final;
	bool quit = false;


	int status;
	//menu.frame_loop_menu(renderer, &level1);
	/*
	for (int i = 0; i < 3; i++){
		status = level1.frame_loop2(renderer , 3-i);
		if (status == 1){
			break;
			//won level 1 proceding to level 2
		}
		if (status == 2){
			exit(0);
		}
	}
	*/
	for (int i = 0; i < 3; i++){
		status = final.frame_loop2(renderer,3-i);
		if (status == 1){
			break;
		}
		if (status == 2){
			exit(0);
		}
	}
	/*
	if (won == 1){
		win.frame_loop_win(renderer);
	} else if (won == -1){
		lose.frame_loop_lose(renderer);
	} else {
		exit(0);
	}
	*/

	return 0;
}
