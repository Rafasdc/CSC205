/*
Project CSC205
Rafael Solorzano
V00838235
*/
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
//surfaces
SDL_Surface* sprite = SDL_LoadBMP("sprites_small.bmp");

//C
//top to bottom
//Box brick1(100,300,100,350,145,173,78,255);
Box brick1(100,200,100,125,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick2(100,125,130,205,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick3(100,125,210,285,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick4(100,200,290,315,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);

//S
//bottom to top
Box brick5(250,375,290,315,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",sprite);
Box brick6(350,375,240,285,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",sprite);
Box brick7(250,375,210,235,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",sprite);
Box brick8(250,275,130,205,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",sprite);
Box brick9(250,375,100,125,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",sprite);

//C
//top to bottom
Box brick10(425,525,100,125,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick11(425,450,130,205,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick12(425,450,210,285,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);
Box brick13(425,525,290,315,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",sprite);

//Lower Line
Box brick14(0,50,350,375,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",sprite);
Box brick15(55,105,350,375,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",sprite);
Box brick16(110,160,350,375,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",sprite);
Box brick17(165,215,350,375,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",sprite);
Box brick18(165,215,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick19(220,270,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick20(275,325,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick21(330,380,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick22(385,435,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick23(440,490,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick24(495,545,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick25(550,600,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick26(605,655,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick27(660,710,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);
Box brick28(715,800,350,375,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",sprite);


//Play
Box play(350,450,580,590,0,0,255,255,0,120,63,8,-1, true, "sprites.bmp",sprite);


//Ball
Ball ball(400,569,135,135, 7,200, 255,67,55,255);
Ball arb(70,530,-100,-100, 7,225, 0,255,55,255);

//line right
Line line_right(400,580,420,550,255,255,255,255);

//line left
Line line_left(400,580,380,550,255,255,255,255);

//walking area 1
Box walk(0,800,800,900,0,0,255,255,212,463,270,45,-1, true, "terrain.bmp",sprite);

//player
Box player(400,435,745,800,255,0,0,0,216,244,14,26,-1,true, "characters.bmp",sprite);

//hit boxes
Box box1(55,85,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);
Box box2(185,215,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);
Box box3(315,345,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);
Box box4(445,475,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);
Box box5(575,605,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);
Box box6(705,735,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",sprite);

//hit over box when hit
Box overbox1(0,125,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);
Box overbox2(130,250,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);
Box overbox3(255,375,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);
Box overbox4(380,520,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);
Box overbox5(525,645,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);
Box overbox6(650,800,630,640,0,0,255,255,20,651,63,6,-1, true, "sprites.bmp",sprite);

//SDL_SetColorKey(surface,SDL_TRUE,0);


std::vector<Box *> BrickList;
std::vector<Ball*> BallList;
std::vector<Box *> HitBoxes;
vector<Box *> OverBoxes;

class Level1{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 900;



	Level1(){
		key_a = true;
		key_d = false;
		first = true;
		lose_disable = false;
		changer_r = true;
		ichange_r = 0;
		changer_l = true;
		ichange_l = 0;
		for (int i = 0; i < 5; i++){
			overboxes_hit[i] = 0;
		}
		overboxes_hit[5] = 0;
		lives = 3;
		cheatwin = false;
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
		HitBoxes.push_back(&box1);
		HitBoxes.push_back(&box2);
		HitBoxes.push_back(&box3);
		HitBoxes.push_back(&box4);
		HitBoxes.push_back(&box5);
		HitBoxes.push_back(&box6);
		OverBoxes.push_back(&overbox1);
		OverBoxes.push_back(&overbox2);
		OverBoxes.push_back(&overbox3);
		OverBoxes.push_back(&overbox4);
		OverBoxes.push_back(&overbox5);
		OverBoxes.push_back(&overbox6);



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
					if (lives != 0){
						lives--;
						ball.start = false;
						first = true;
						ball.hit_bottom = false;
						ball.ball_position.x = 400;
						ball.ball_position.y = 569;
					} else {
						return -1;
					}

				}
			}


			if (BrickList.size() == 0 || cheatwin){
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

		} else if (key == SDLK_d){

		} else if (key == SDLK_n){
			lose_disable = true;
		} else if (key == SDLK_UP){
			key_w = true;
		} else if (key == SDLK_k){
			cheatwin = true;
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
		//printf("x is %d, y is %d\n", x,y);
		mouse_x = x;
	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){

		ball.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y-100);
		ball.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y-100);


		for (int k = 0; k < BrickList.size(); k++){
					(ball.ball_rectangle_col(BrickList[k]));
					(arb.ball_rectangle_col(BrickList[k]));
					if(BrickList[k]->hits ==1 && BrickList[k]->hits_to_destroy ==1){
						BrickList.erase(BrickList.begin()+k);
					}else if (BrickList[k]->hits ==1 && BrickList[k]->hits_to_destroy == 3){
						BrickList[k]->clip_x = 405;
					} else if (BrickList[k]->hits ==2 && BrickList[k]->hits_to_destroy == 3){
						BrickList[k]->clip_x = 356;
					} else if (BrickList[k]->hits ==3 && BrickList[k]->hits_to_destroy == 3){
						BrickList.erase(BrickList.begin()+k);
					}
		}

		for (int j = 0; j < HitBoxes.size(); j++){
			ball.ball_rectangle_col(HitBoxes[j]);
			if (overboxes_hit[j] > 0){
				ball.ball_rectangle_col(OverBoxes[j]);
			}
		}


		float frame_delta_seconds = frame_delta_ms/1000.0;
		if (key_w){
			player.setClip(334,244,17,26);
			float gravity = 305;
			float jump_height = 210;
			//printf("player velo is %f \n", player.velocity_y);
			if (player.velocity_y != 0){
				player.y1 -= player.velocity_y * frame_delta_seconds;
				player.y2 -= player.velocity_y * frame_delta_seconds;
				player.velocity_y -= gravity * frame_delta_seconds;
			}
			if (player.y2 > 800){
				player.y1 = 745;
				player.y2 = 800;
				player.velocity_y = 0;
				player.setClip(216,244,14,26);
				key_w = false;
			}
			if (player.velocity_y == 0){
				player.velocity_y = jump_height;
			}
		}

		const Uint8 *state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT]){
			changer_l = true;
			ichange_l = 0;
			if (changer_r){
				player.setClip(255,244,16,26);
				ichange_r++;
				if (ichange_r == 2){
					changer_r = false;
					ichange_r = 0;
				}
			} else {
				player.setClip(215,244,16,26);
				changer_r = true;
			}
			if (key_w){
				player.setClip(334,244,17,26);
			}
			player.x1 += player.velocity_x*frame_delta_seconds;
			player.x2 += player.velocity_x*frame_delta_seconds;
			if (player.x2 > 800){
				player.x2 = 800;
				player.x1 = 800-35;
			}
		}


		if (state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT]){
			changer_r = true;
			ichange_r = 0;
			if (changer_l){
				player.setClip(135,244,16,26);
				ichange_l++;
				if (ichange_l == 2){
					changer_l = false;
					ichange_l = 0;
				}
			} else {
				player.setClip(175,244,16,26);
				changer_l = true;
			}
			if (key_w){
				player.setClip(54,244,17,26);
			}
			player.x1 -= player.velocity_x*frame_delta_seconds;
			player.x2 -= player.velocity_x*frame_delta_seconds;
			if (player.x1 < 0){
				player.x1 = 0;
				player.x2 = 35;
			}
		}

		player.ball_intersection(&ball.new_position, &ball.ball_position,ball.radius,&ball.ball_direction);

		for (int j = 0; j < HitBoxes.size(); j++){
			player.box_collision(HitBoxes[j], overboxes_hit, j);
		}




		SDL_SetRenderDrawColor(renderer, 0, 255, 247, 255);
		SDL_RenderClear(renderer);

		ball.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);





		//draw each box
		for (int k = 0; k < BrickList.size(); k++){
			BrickList[k]->draw(renderer);
		}
		for (int k = 0; k < HitBoxes.size(); k++){
			HitBoxes[k]->draw(renderer);
			if (overboxes_hit[k] > 0){
				//printf("%d\n", overboxes_hit[k]);
				OverBoxes[k]->draw(renderer);
				overboxes_hit[k]--;
			}
		}
		//play.draw(renderer);
		walk.draw(renderer);
		player.draw(renderer);

		stringRGBA(renderer,10,10,"BALLS",255,255,255,255);
		if (lives == 3){
			stringRGBA(renderer,10,25,"3",255,255,255,255);
		} else if (lives == 2){
			stringRGBA(renderer,10,25,"2",255,255,255,255);
		} else if (lives == 1){
			stringRGBA(renderer,10,25,"1",255,255,255,255);
		} else {
			stringRGBA(renderer,10,25,"0",255,255,255,255);
		}



		SDL_RenderPresent(renderer);
	}
	bool first, play_mouse, play_keyboard, key_a, key_d, balls_2, lose_disable, key_w, changer_r, changer_l, cheatwin;
	int mouse_x, ichange_r, ichange_l, lives;
	int overboxes_hit[6];

};


