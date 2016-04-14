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

using namespace std;

class Box{
public:
	Box(int x1_in, int x2_in, int y1_in, int y2_in, int r_in, int g_in, int b_in, int a_in
			,int clip_x_in, int clip_y_in, int clip_w_in, int clip_h_in, int hits_in,
			bool textured_in, string texture_in,SDL_Surface* surface_in){
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
		clip_x = clip_x_in;
		clip_y = clip_y_in;
		clip_w = clip_w_in;
		clip_h = clip_h_in;
		hits_to_destroy = hits_in;
		hits = 0;
		textured = textured_in;
		texture = texture_in;
		surface = surface_in;
		velocity_y = 0;

	}

	void setHit(){
		hit = true;
	}

	void draw(SDL_Renderer* renderer){
		if (hits != hits_to_destroy){
			//boxRGBA(renderer_in, x1-1, y1-1,x2+1,y2+1,0,0,0,255); //border
			boxRGBA(renderer, x1,y1,x2,y2,r,g,b,a);
			if (textured){
				SDL_Rect clip;
				clip.x = clip_x;
				clip.y = clip_y;
				clip.w = clip_w;
				clip.h = clip_h;
				SDL_Rect r;
				r.x = x1;
				r.y = y1;
				r.w = x2-x1;
				r.h = y2-y1;
				SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
				SDL_RenderCopy(renderer, texture, &clip, &r);
				//SDL_FreeSurface(surface);
				SDL_DestroyTexture(texture);
			}
		}
	}

	void ball_intersection(Vector2d  * new_position, Vector2d * current_position, int radius, Vector2d * ball_direction){
		if (hits == hits_to_destroy){
			return;
		}

		if (current_position->x <= x1+radius && new_position->x >= x1-radius ){
			if (new_position->y >= y1 - radius && new_position->y <= y2 + radius){
				ball_direction->x = -ball_direction->x;
				//printf("left edge\n");
				new_position->x = x1-radius-1;
				hits++;
			}
		} else if (current_position->x >= x2-radius && new_position->x <= x2+radius){

			if (new_position->y >= y1 - radius && new_position->y <= y2 + radius){
				//printf("right edge\n");
				ball_direction->x = -ball_direction->x;
				new_position->x = x2+radius+1;
				hits++;
			}
		} else if (current_position->y >= y2 - radius && new_position->y <= y2+radius){
			if ((new_position->x >= x1 - radius  && new_position->x <= x2 + radius)) {
				//printf("bottom\n");
				ball_direction->y = -ball_direction->y;
				new_position->y = y2+radius+1;
				hits++;
			}
		} else if (current_position->y <= y1 + radius && new_position->y >= y1-radius){
			if ((new_position->x >= x1 - radius  && new_position->x <= x2 + radius)) {
				//printf("top\n");
				ball_direction->y = -ball_direction->y;
				new_position->y = y1-radius-5;
				hits++;
			}
		}
	}



	//SDL_Renderer* renderer;
	SDL_Surface* surface;
	int x1,x2,y1,y2,r,g,b,a, clip_x, clip_y, clip_w, clip_h, hits_to_destroy, hits;
	bool hit, textured;
	string texture;
	float velocity_y;
};

