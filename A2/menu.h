
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


#include "vector2d.h"
#include "colourRGB.h"



using namespace std;


static const ColourRGB BALL_COLOURS[] = {
	ColourRGB(0,0,0),
	ColourRGB(255,0,0),
	ColourRGB(0,255,0),
	ColourRGB(0,0,255),
	ColourRGB(0,255,255),
	ColourRGB(255,0,255),
	ColourRGB(255,255,0)
};

//C
//top to bottom
//Box brick1(100,300,100,350,145,173,78,255);
Box choice1(290,490,365,420,255,128,0,255);
Box choice2(290,490,490,545,51,153,255,255);



//std::vector<Box *> BrickList;


class Menu{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 600;



	Menu(){
		option1 = false;

	}

	void frame_loop_menu(SDL_Renderer* r){
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

			draw_menu(r,delta_ms);

			last_frame = current_frame;
			frame_number++;
			if (option1){
				break;
			}

		}


	}


private:

	void handle_key_down2(SDL_Keycode key){

	}
	void handle_mouse_down2(int x, int y, int button){
		if (x >= 290 && x <= 490){
			if (y <= 420 && y >= 365){
				if(button == SDL_BUTTON_LEFT){
					option1 = true;
				}
			}
		}
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
		printf("x is %d, y is %d\n", x,y);
	}

	void draw_menu(SDL_Renderer *renderer, float frame_delta_ms){



		SDL_SetRenderDrawColor(renderer, 229, 255, 204, 255);
		SDL_RenderClear(renderer);

		//stringRGBA(renderer,315,310,"BALLS",0,0,204,255);

		choice1.draw(renderer);
		stringRGBA(renderer,315,385,"CLICK HERE TO PLAY",0,0,204,255);
		stringRGBA(renderer,350,400,"WITH MOUSE",0,0,204,255);
		choice2.draw(renderer);
		stringRGBA(renderer,315,510,"CLICK HERE TO PLAY",102,0,0,255);
		stringRGBA(renderer,350,525,"WITH KEYBOARD",102,0,0,255);

		SDL_RenderPresent(renderer);
	}
	bool option1;
};



