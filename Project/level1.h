
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


//C
//top to bottom
//Box brick1(100,300,100,350,145,173,78,255);
Box brick1(100,200,100,125,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick2(100,125,130,205,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick3(100,125,210,285,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick4(100,200,290,315,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");

//S
//bottom to top
Box brick5(250,375,290,315,203,38,38,255,33,0,16,8,1,true, "sprites.bmp");
Box brick6(350,375,240,285,203,38,38,255,33,0,16,8,1,true, "sprites.bmp");
Box brick7(250,375,210,235,203,38,38,255,33,0,16,8,1,true, "sprites.bmp");
Box brick8(250,275,130,205,203,38,38,255,33,0,16,8,1,true, "sprites.bmp");
Box brick9(250,375,100,125,203,38,38,255,33,0,16,8,1,true, "sprites.bmp");

//C
//top to bottom
Box brick10(425,525,100,125,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick11(425,450,130,205,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick12(425,450,210,285,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");
Box brick13(425,525,290,315,145,173,78,255,96,0,16,8,1,true, "sprites.bmp");

//Lower Line
Box brick14(0,50,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick15(55,105,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick16(110,160,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick17(165,215,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick18(165,215,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick19(220,270,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick20(275,325,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick21(330,380,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick22(385,435,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick23(440,490,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick24(495,545,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick25(550,600,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick26(605,655,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick27(660,710,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");
Box brick28(715,800,350,375,370,173,78,255,433,24,15,7,3, true, "sprites.bmp");


//Play
Box play(350,450,580,590,0,0,255,255,0,120,63,8,-1, true, "sprites.bmp");


//Ball
Ball ball(400,569,135,135, 7,225, 255,67,55,255);
Ball arb(70,530,-100,-100, 7,225, 0,255,55,255);

//line right
Line line_right(400,580,420,550,255,255,255,255);

//line left
Line line_left(400,580,380,550,255,255,255,255);

//walkin area 1
Box walk(0,800,800,900,0,0,255,255,294,190,280,48,-1, true, "terrain.bmp");

//player
Box player(400,415,772,800,255,0,0,0,196,48,15,28,-1,true, "characters.bmp");


std::vector<Box *> BrickList;
std::vector<Ball *> BallList;


class Level1{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 600;



	Level1(){
		key_a = true;
		key_d = false;
		first = true;
		lose_disable = true;
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
		BrickList.push_back(&brick14);
		BrickList.push_back(&brick15);
		BrickList.push_back(&brick16);
		BrickList.push_back(&brick17);
		BrickList.push_back(&brick18);
		BrickList.push_back(&brick19);
		BrickList.push_back(&brick20);
		BrickList.push_back(&brick21);
		BrickList.push_back(&brick22);
		BrickList.push_back(&brick23);
		BrickList.push_back(&brick24);
		BrickList.push_back(&brick25);
		BrickList.push_back(&brick26);
		BrickList.push_back(&brick27);
		BrickList.push_back(&brick28);



	}

	int frame_loop2(SDL_Renderer* r){
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
						return 2;
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

			if (ball.hit_bottom){
				if(!lose_disable){
					return -1;
				}
			}

			if (BrickList.size() == 0){
				return 1;
			}


		}


	}

	void set_mouse(){
		play_mouse = true;
	}
	void set_keyboard(){
		play_keyboard = true;
	}
	void set_2_balls(){
		balls_2 = true;
	}


private:

	void handle_key_down2(SDL_Keycode key){
		if (key == SDLK_SPACE){
			ball.start = true;
			arb.start = true;
			first = false;
		}else if (key == SDLK_r){

			Vector2d rotation( cos(30*(M_PI/180)), sin(30*(M_PI/180)) );
			Vector2d new_direction(
			rotation.x*ball.ball_direction.x - rotation.y*ball.ball_direction.y,
			rotation.x*ball.ball_direction.y + rotation.y*ball.ball_direction.x);
			ball.ball_direction = new_direction;

		} else if (key == SDLK_a){
			key_d = false;
			key_a = true;

			if(true){
				if (play.x1-25 >= 0){
				if (first){
					ball.ball_position.x -=25;
					line_right.x1 -= 25;
					line_right.x2 -= 25;
					line_left.x1 -= 25;
					line_left.x2 -= 25;
				}

					player.x1 -= 25;
					player.x2 -= 25;
				}
			}



		} else if (key == SDLK_d){
			key_a = false;
			key_d = true;
			if (true){
				if (play.x2+25 <= CANVAS_SIZE_X){
				if (first){
					ball.ball_position.x +=25;
					line_right.x1 += 25;
					line_right.x2 += 25;
					line_left.x2 += 25;
					line_left.x1 += 25;
				}

					player.x1 += 25;
					player.x2 += 25;
				}
			}


		} else if (key == SDLK_n){
			/*
			if (!first){
				arb.start = true;
				BallList.push_back(arb);
			}
			*/
			lose_disable = true;
		}
	}
	void handle_mouse_down2(int x, int y, int button){
		if (button == SDL_BUTTON_LEFT){
			ball.start = true;
			first = false;
			arb.start = true;
		}
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
		printf("x is %d, y is %d\n", x,y);
		mouse_x = x;

		if (play_mouse){
			play.x1 = x;
			play.x2 = x+100;

			if (first){
				ball.ball_position.x =x+50;
				int move_line = (play.x1 + play.x2)*1/2;
				line_right.x1 = move_line;
				line_right.x2 = move_line+20;
				line_left.x2 = move_line-20;
				line_left.x1 = move_line;
			}
		}


	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){

		ball.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y);
		ball.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y);

		/*
		if (balls_2){
			arb.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y);
			arb.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y);
		}
		*/

		//arb.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y);
		//arb.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y);

		for (int k = 0; k < BrickList.size(); k++){
					(ball.ball_rectangle_col(BrickList[k]));
					(arb.ball_rectangle_col(BrickList[k]));
					if(BrickList[k]->hits ==1 && BrickList[k]->hits_to_destroy ==1){
						BrickList.erase(BrickList.begin()+k);
					}else if (BrickList[k]->hits ==1 && BrickList[k]->hits_to_destroy == 3){
						BrickList[k]->clip_x = 385;
					} else if (BrickList[k]->hits ==2 && BrickList[k]->hits_to_destroy == 3){
						BrickList[k]->clip_x = 337;
					} else if (BrickList[k]->hits ==3 && BrickList[k]->hits_to_destroy == 3){
						BrickList.erase(BrickList.begin()+k);
					}
		}

		/*
		if (!first){
			play.ball_intersection(&ball.new_position, &ball.ball_position,ball.radius,&ball.ball_direction);
			play.ball_intersection(&arb.new_position, &arb.ball_position,arb.radius,&arb.ball_direction);
		}
		if (balls_2){
			ball.ball_ball_col(&arb);
		}
		*/


		SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
		SDL_RenderClear(renderer);


		walk.draw(renderer);

		ball.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);
		/*
		if (balls_2){
			arb.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);
		}
		*/


		//draw each box
		for (int k = 0; k < BrickList.size(); k++){
			BrickList[k]->draw(renderer);
		}
		//play.draw(renderer);
		//walk.draw(renderer);
		//player.draw(renderer);




		SDL_RenderPresent(renderer);
	}
	bool first, play_mouse, play_keyboard, key_a, key_d, balls_2, lose_disable;
	int mouse_x;
};


