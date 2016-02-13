/*
 * box.h
 *
 *  Created on: Feb 13, 2016
 *      Author: rafa
 */

#ifndef BOX_H_
#define BOX_H_





#endif /* BOX_H_ */

#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "vector2d.h"
#include "colourRGB.h"


class Box{
public:
	Box(SDL_Renderer* renderer_in, int x1_in, int x2_in, int y1_in, int y2_in, int r_in, int g_in, int b_in, int a_in){
		renderer = renderer_in;
		x1 = x1_in;
		x2 = x2_in;
		y1 = y1_in;
		y2 = y2_in;
		r = r_in;
		g = g_in;
		b = b_in;
		a = a_in;

	}

	void setHit(){
		hit = true;
	}

	void draw(){
		if (!hit){
			boxRGBA(renderer, x1,y1,x2,y2,r,g,b,a);
		}
	}



	SDL_Renderer* renderer;
	int x1,x2,y1,y2,r,g,b,a;
	bool hit = false;
};

