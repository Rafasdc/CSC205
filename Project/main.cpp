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
#include "win.h"
#include "final.h"
#include "finalintro.h"

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
	
	Level1 level1;
	Lose lose;
	Win win;
	FinalLevel final;
	FinalIntro intro;
	bool quit = false;
	int status = 0;



	status = level1.frame_loop2(renderer);
	if (status == 1){
		//Proceed to Final Level
	} else if (status == -1){
		lose.frame_loop_lose(renderer);
	} else {
		exit(0);
	}

	if (status != -1){
	intro.frame_loop_win(renderer);
	status = final.frame_loop2(renderer);
	if (status == 1){
		win.frame_loop_win(renderer);
	} else if (status == -1){
		lose.frame_loop_lose(renderer);
	} else {
		exit(0);
	}
	}



	return 0;
}
