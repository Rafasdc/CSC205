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

	bool ball_intersection(Vector2d  * new_position, Vector2d * current_position, int radius, Vector2d * ball_direction, int CANVAS_SIZE_Y, int CANVAS_SIZE_X){
		if (hit){
			return false;
		}

		/*
		if ((new_position.x >= x1 - BALL_RADIUS  && new_position.x <= x2 + BALL_RADIUS)) {
			if (new_position.y >= y1 - BALL_RADIUS && new_position.y <= y2 + BALL_RADIUS){
				ball_direction->y = -ball_direction->y;
				//ball_direction->x = ball_direction->x;
				return true;
			}
		}
		*/

		/*
		 * use or in both new_position to change x direciton and on both
		 * y to change y direction, insted of having one big if in each statement have a big one before.
		 *
		 */

		if (current_position->x <= x1+radius && new_position->x >= x1-radius ){
			if (new_position->y >= y1 - radius && new_position->y <= y2 + radius){
				ball_direction->x = -ball_direction->x;
				printf("left edge\n");
			}
		} else if (current_position->x >= x2-radius && new_position->x <= x2+radius){

			if (new_position->y >= y1 - radius && new_position->y <= y2 + radius){
				printf("right edge\n");
				ball_direction->x = -ball_direction->x;
			}
		} else if (current_position->y >= y2 - radius && new_position->y <= y2+radius){
			if ((new_position->x >= x1 - radius  && new_position->x <= x2 + radius)) {
				printf("bottom\n");
				ball_direction->y = -ball_direction->y;
			}
		} else if (current_position->y <= y1 + radius && new_position->y >= y1-radius){
			if ((new_position->x >= x1 - radius  && new_position->x <= x2 + radius)) {
				printf("top\n");
				ball_direction->y = -ball_direction->y;
			}
		}
		return false;
	}



	//SDL_Renderer* renderer;
	int x1,x2,y1,y2,r,g,b,a;
	bool hit;
};

