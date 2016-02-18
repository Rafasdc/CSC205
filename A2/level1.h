
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "vector2d.h"
#include "colourRGB.h"
#include "box.h"

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
Box brick1(100,200,100,125,145,173,78,255);
Box brick2(100,125,130,205,145,173,78,255);
Box brick3(100,125,210,285,145,173,78,255);
Box brick4(100,200,290,315,145,173,78,255);

//S
//bottom to top
Box brick5(250,375,290,315,203,38,38,255);
Box brick6(350,375,240,285,203,38,38,255);
Box brick7(250,375,210,235,203,38,38,255);
Box brick8(250,275,130,205,203,38,38,255);
Box brick9(250,375,100,125,203,38,38,255);

//C
//top to bottom
Box brick10(425,525,100,125,145,173,78,255);
Box brick11(425,450,130,205,145,173,78,255);
Box brick12(425,450,210,285,145,173,78,255);
Box brick13(425,525,290,315,145,173,78,255);

//Vector2d ball_position;
//Vector2d ball_direction;
Ball ball(400,300,cos(30*(M_PI/180.0)),sin(30*(M_PI/180.0)), 7,150, 255,67,55,255);


std::vector<Box *> ObjectList;


class A2Canvas2{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 600;
	//static const int BALL_RADIUS = 15;
	//static const float BALL_VELOCITY = 150; //Pixels/second
	static const int NUM_COLOURS = 7;


	A2Canvas2(){

		//ball_position.x = CANVAS_SIZE_X/2;
		//ball_position.y = CANVAS_SIZE_Y/2;
		////ball_direction.x = cos(30*(M_PI/180.0));
		//ball_direction.y = sin(30*(M_PI/180.0));
		//ball_colour_idx = 0;


		//start = false;
		ObjectList.push_back(&brick1);
		/*
		ObjectList.push_back(&brick2);
		ObjectList.push_back(&brick3);
		ObjectList.push_back(&brick4);
		ObjectList.push_back(&brick5);
		ObjectList.push_back(&brick6);
		ObjectList.push_back(&brick7);
		ObjectList.push_back(&brick8);
		ObjectList.push_back(&brick9);
		ObjectList.push_back(&brick10);
		ObjectList.push_back(&brick11);
		ObjectList.push_back(&brick12);
		ObjectList.push_back(&brick13);
		*/



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
		if (key == SDLK_s){
			//start = true;
		}else if (key == SDLK_r){
			/*
			Vector2d rotation( cos(30*(M_PI/180)), sin(30*(M_PI/180)) );
			Vector2d new_direction(
			rotation.x*ball_direction.x - rotation.y*ball_direction.y,
			rotation.x*ball_direction.y + rotation.y*ball_direction.x);
			ball_direction = new_direction;
			*/
		}
	}
	void handle_mouse_down2(int x, int y, int button){
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){


		ball.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y);
		ball.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y);
		SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
		SDL_RenderClear(renderer);

		ball.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);

		//const ColourRGB& ball_colour = BALL_COLOURS[ball_colour_idx];
		//filledCircleRGBA(renderer,ball_position.x,ball_position.y,BALL_RADIUS,ball_colour.r,ball_colour.g,ball_colour.b,255);

		//draw each box
		for (int k = 0; k < ObjectList.size(); k++){
			ObjectList[k]->draw(renderer);
		}
		SDL_RenderPresent(renderer);
	}

	//Vector2d ball_position,ball_direction;
	//int ball_colour_idx;
	//Vector2d box_position1;
	//Vector2d box_position2;
	//bool start;


};


