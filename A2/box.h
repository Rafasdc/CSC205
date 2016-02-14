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

	bool ball_intersection(Vector2d  * new_position, int BALL_RADIUS, Vector2d * ball_direction, int CANVAS_SIZE_Y, int CANVAS_SIZE_X){
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

		if (new_position->x >= x1 - BALL_RADIUS){
			//Collide with left edge
			//Determine how far past the collision point the new position is.
			//float offset_x = x1-BALL_RADIUS-new_position->x;
			//Mirror the direction around the y axis (since the ball bounces)
			if ((new_position->x >= x1 - BALL_RADIUS  && new_position->x <= x2 + BALL_RADIUS)) {
				if (new_position->y >= y1 - BALL_RADIUS && new_position->y <= y2 + BALL_RADIUS){
					ball_direction->x = -ball_direction->x;
				}
			}
			//new_position->x += 2*offset_x;
		}else if(new_position->x <= x2 + BALL_RADIUS){
			//Collide with right edge
			//Determine how far past the collision point the new position is.
			//float offset_x = new_position->x - ((CANVAS_SIZE_X-(CANVAS_SIZE_X-x2))-BALL_RADIUS);
			//Mirror the direction around the y axis (since the ball bounces)
			if ((new_position->x >= x1 - BALL_RADIUS  && new_position->x <= x2 + BALL_RADIUS)) {
				if (new_position->y >= y1 - BALL_RADIUS && new_position->y <= y2 + BALL_RADIUS){
					ball_direction->x = -ball_direction->x;
				}
			}
			//new_position->x -= 2*offset_x;
		}else if(new_position->y >= y1 - BALL_RADIUS && new_position->y <= y2+BALL_RADIUS){
			//Collide with top
			//Determine how far past the collision point the new position is.
			//float offset_y = (y1-BALL_RADIUS)-new_position->y;
			//Mirror the direction around the x axis (since the ball bounces)
			if ((new_position->x >= x1 - BALL_RADIUS  && new_position->x <= x2 + BALL_RADIUS)) {
				if (new_position->y >= y1 - BALL_RADIUS && new_position->y <= y2 + BALL_RADIUS){
					ball_direction->y = -ball_direction->y;
				}
			}
			//new_position->y += 2*offset_y;
		}/*
		else if(new_position->y <= y2+BALL_RADIUS){
			//Collide with bottom
			//Determine how far past the collision point the new position is.
			//float offset_y = new_position->y - (y2+BALL_RADIUS);
			//Mirror the direction around the x axis (since the ball bounces)
			if ((new_position->x >= x1 - BALL_RADIUS  && new_position->x <= x2 + BALL_RADIUS)) {
				if (new_position->y >= y1 - BALL_RADIUS && new_position->y <= y2 + BALL_RADIUS){
					ball_direction->y = -ball_direction->y;
				}
			}
			//new_position->y -= 2*offset_y;
		}
		*/

		return false;
	}



	//SDL_Renderer* renderer;
	int x1,x2,y1,y2,r,g,b,a;
	bool hit;
};

