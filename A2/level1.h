
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "vector2d.h"
#include "colourRGB.h"
#include "box.h"

using namespace std;






class A2Canvas2{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 600;


	A2Canvas2(){



	}





	void frame_loop2(SDL_Renderer* r){
		unsigned int last_frame = SDL_GetTicks();
		unsigned int frame_number = 0;
		while(1){
			//cout << "Frame " << frame_number << endl;
			unsigned int current_frame = SDL_GetTicks();
			unsigned int delta_ms = current_frame - last_frame;

			SDL_Event e;
			//Handle all queued events
			while(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_QUIT:
						//Exit immediately
						return;
					case SDL_KEYDOWN:
						//e.key stores the key pressed
						handle_key_down2(e.key.keysym.sym);
						break;
					case SDL_MOUSEMOTION:
						//e.motion contains the relevant mouse position information
						handle_mouse_moved2(e.motion.x,e.motion.y);
						break;
					case SDL_MOUSEBUTTONDOWN:
						//e.button contains the relevant mouse position and button information
						handle_mouse_down2(e.button.x,e.button.y,e.button.button);
						break;
					case SDL_MOUSEBUTTONUP:
						handle_mouse_up2(e.button.x,e.button.y,e.button.button);
						break;
					default:
						break;
				}
			}

			draw2(r,delta_ms);

			last_frame = current_frame;
			frame_number++;


		}


	}


private:

	void handle_key_down2(SDL_Keycode key){
	}
	void handle_mouse_down2(int x, int y, int button){
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){


		float frame_delta_seconds = frame_delta_ms/1000.0;

		//background = SDL_LoadBMP("canada.bmp");
		//SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,background);
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
		SDL_RenderClear(renderer);

		//Vector2d vx = (400,500);
		//Vector2d vy = (300,400);

		//boxRGBA(renderer, box_position1.x,box_position1.y,box_position2.x,box_position2.y,255,0,0,255);

		//boxRGBA(renderer, 399,299,501,401,0,0,0,255);
		//boxRGBA(renderer, 100,100,125,175,145,173,78,255);
		//boxRGBA(renderer, 100,100,175,125,145,173,78,255);
		Box brick1(renderer,100,175,100,125,145,173,78,255);
		brick1.setHit();
		brick1.draw();







		SDL_RenderPresent(renderer);
	}


};


