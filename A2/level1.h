
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


#include "vector2d.h"
#include "colourRGB.h"
#include "box.h"
#include "ball.h"
#include "line.h"

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

//Play
Box play(350,450,580,590,0,0,255,255);


//Ball
Ball ball(400,571,135,135, 7,150, 255,67,55,255);

//line right
Line line_right(400,580,420,550,255,255,255,255);

//line left
Line line_left(400,580,380,550,255,255,255,255);


std::vector<Box *> BrickList;


class A2Canvas2{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 600;



	A2Canvas2(){
		first = true;
		BrickList.push_back(&brick1);
		BrickList.push_back(&brick2);
		BrickList.push_back(&brick3);
		BrickList.push_back(&brick4);
		BrickList.push_back(&brick5);
		BrickList.push_back(&brick6);
		BrickList.push_back(&brick7);
		BrickList.push_back(&brick8);
		BrickList.push_back(&brick9);
		BrickList.push_back(&brick10);
		BrickList.push_back(&brick11);
		BrickList.push_back(&brick12);
		BrickList.push_back(&brick13);
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
			//if (ball.hit_bottom){
			//	break;
			//}

		}


	}


private:

	void handle_key_down2(SDL_Keycode key){
		if (key == SDLK_s){
			ball.start = true;
			first = false;
		}else if (key == SDLK_r){

			Vector2d rotation( cos(30*(M_PI/180)), sin(30*(M_PI/180)) );
			Vector2d new_direction(
			rotation.x*ball.ball_direction.x - rotation.y*ball.ball_direction.y,
			rotation.x*ball.ball_direction.y + rotation.y*ball.ball_direction.x);
			ball.ball_direction = new_direction;

		} else if (key == SDLK_a){
			if (first){
				ball.ball_position.x -=15;
			}
			play.x1 -= 15;
			play.x2 -= 15;
		} else if (key == SDLK_d){
			if (first){
				ball.ball_position.x +=15;
			}
			play.x1 += 15;
			play.x2 += 15;
		}
	}
	void handle_mouse_down2(int x, int y, int button){
		if (button == SDL_BUTTON_LEFT){
			ball.start = true;
			first = false;
		}
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
		printf("x is %d, y is %d\n", x,y);
		mouse_x = x;

		//ball.set_direction(x,x);
		//play.x1 = x;
		//play.x2 = x+100;
	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){

		ball.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y);
		ball.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y);



		for (int k = 0; k < BrickList.size(); k++){
					(ball.ball_rectangle_col(BrickList[k]));
		}


		SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
		SDL_RenderClear(renderer);


		if (first && mouse_x < CANVAS_SIZE_X/2){
			ball.set_direction(135,135);
			line_left.draw(renderer);
		} else if (first) {
			ball.set_direction(45,45);
			line_right.draw(renderer);

		}

		ball.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);

		//draw each box
		for (int k = 0; k < BrickList.size(); k++){
			BrickList[k]->draw(renderer);
		}
		play.draw(renderer);
		if (!first){
			play.ball_intersection(&ball.new_position, &ball.ball_position,ball.radius,&ball.ball_direction);
		}


		/*
		SDL_Rect r;
		r.x = 100;
		r.y = 100;
		r.w = 50;
		r.h = 25;
		SDL_Surface* canada = SDL_LoadBMP("canada.bmp");
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,canada);
		SDL_RenderCopy(renderer, texture, NULL, &r);
		*/



		SDL_RenderPresent(renderer);
	}
	bool first;
	int mouse_x;
};


