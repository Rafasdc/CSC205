/*
Project CSC205
Rafael Solorzano
V00838235
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
		velocity_x = 225;

	}

	void setHit(){
		hit = true;
	}

	void draw(SDL_Renderer* renderer){
		if (hits != hits_to_destroy){
			//boxRGBA(renderer_in, x1-1, y1-1,x2+1,y2+1,0,0,0,255); //border
			//boxRGBA(renderer, x1,y1,x2,y2,r,g,b,a);
			if (textured){
				//surface->format->Amask = 0xFF000000;
				//surface->format->Ashift = 32;
				//SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,0,255,247));
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

	void box_collision(Box* box, int overbox_hit[6], int k){
		/*
		 * Using Minkowski Sum we calculate a new rectangle and we check
		 * where current rectangle lies relative to the new rectangle we computed
		 * also we check its diagonals to check where they are happening,
		 * only interested in bottom, left and right as top should never occur.
		 * Based on question answer in http://gamedev.stackexchange.com/questions/29786/a-simple-2d-rectangle-collision-algorithm-that-also-determines-which-sides-that
		 * And in Wikipedia
		 */
		float w = 0.5 * ((x2-x1)+(box->x2-box->x1));
		//float a = box->y2 - box->y1;
		//printf("%f\n",a);
		float h = 0.5 * ((y2-y1)+(box->y2-box->y1));
		float dx = ((x2+x1)/2) - ((box->x2+box->x1)/2);
		float dy = ((y2+y1)/2) - ((box->y2+box->y1)/2);
		//printf("%f %f\n", w, h);
		//printf("%f %f\n", dy, dx);

		if (abs(dx) <= w && abs(dy) <= h){
			//printf("collision\n");
			float y = w * dy;
			float x = h * dx;
			if (y > x){
				if (y > -x){
					//printf ("bottom \n");
					int h = y2 - y1;
					y1 = box->y2 + 1;
					y2 = y1 + h;
					overbox_hit[k] = 100;
				} else {
					//printf("left \n");
					int w = x2 - x1;
					x2 = box->x1 -1;
					x1 = x2 - w;
				}
			} else {
				if (y > -x){
					//printf("right\n");
					int w = x2 - x1;
					x1 = box->x2 + 1;
					x2 = x1 + w;
				} else {
					//printf("top\n");
					//should never occur
				}
			}
		}


	}

	void setClip(int x, int y, int w, int h){
		clip_x = x;
		clip_y = y;
		clip_w = w;
		clip_h = h;
	}



	//SDL_Renderer* renderer;
	SDL_Surface* surface;
	int x1,x2,y1,y2,r,g,b,a, clip_x, clip_y, clip_w, clip_h, hits_to_destroy, hits;
	bool hit, textured;
	string texture;
	float velocity_y,velocity_x;
};

