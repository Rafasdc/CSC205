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
//#include "object.h"


class Box{
public:
	Box(int x1_in, int x2_in, int y1_in, int y2_in, int r_in, int g_in, int b_in, int a_in){
		//renderer = renderer_in;
		x1 = x1_in;
		x2 = x2_in;
		y1 = y1_in;
		y2 = y2_in;
		r = r_in;
		g = g_in;
		b = b_in;
		a = a_in;
		hit = false;

	}

	void setHit(){
		hit = true;
	}

	void draw(SDL_Renderer* renderer_in){
		if (!hit){
			boxRGBA(renderer_in, x1-1, y1-1,x2+1,y2+1,0,0,0,255); //border
			boxRGBA(renderer_in, x1,y1,x2,y2,r,g,b,a);
		}
	}

	bool ball_intersection(Vector2d new_position, int BALL_RADIUS){
		if (hit){
			return false;
		}
		if ((new_position.x >= x1 - BALL_RADIUS  && new_position.x <= x2 + BALL_RADIUS)) {
			if (new_position.y >= y1- BALL_RADIUS && new_position.y <= y2 + BALL_RADIUS){
				return true;
			}
		}
		return false;
	}



	//SDL_Renderer* renderer;
	int x1,x2,y1,y2,r,g,b,a;
	bool hit;
};

