
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


#include "vector2d.h"
#include "colourRGB.h"


using namespace std;
//surfaces
SDL_Surface* fsprite = SDL_LoadBMP("sprites_small_with_pear.bmp");

//C
//top to bottom
//Box fbrick1(100,300,100,350,145,173,78,255);

Box fbrick1(100,200,100,125,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick2(100,125,130,205,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick3(100,125,210,285,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick4(100,200,290,315,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);

//S
//bottom to top
Box fbrick5(250,375,290,315,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick6(350,375,240,285,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick7(250,375,210,235,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick8(250,275,130,205,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick9(250,375,100,125,203,38,38,255,52,530,16,8,1,true, "sprite.bmp",fsprite);

//C
//top to bottom
Box fbrick10(425,525,100,125,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick11(650,675,130,205,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick12(650,675,210,285,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);
Box fbrick13(425,525,290,315,145,173,78,255,116,530,16,8,1,true, "sprite.bmp",fsprite);


//Lower Line
Box fbrick14(0,50,400,425,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",fsprite);
Box fbrick15(55,105,400,425,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",fsprite);
Box fbrick16(110,160,400,425,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",fsprite);
Box fbrick17(165,215,400,425,370,173,78,255,452,554,16,6,3, true, "sprites.bmp",fsprite);
Box fbrick18(165,215,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick19(220,270,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick20(275,325,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick21(330,380,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick22(385,435,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick23(440,490,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick24(495,545,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick25(550,600,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick26(605,655,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick27(660,710,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);
Box fbrick28(715,800,400,425,370,173,78,255,452,554,16,6,3, true, "sprite.bmp",fsprite);

//pear
Box pear0(325,465,285,316,370,173,78,255,603,353,115,22,5, true, "sprite.bmp",fsprite);
Box pear1(305,485,255,285,370,173,78,255,583,316,151,25,5, true, "sprite.bmp",fsprite);
Box pear2(290,490,225,255,370,173,78,255,573,263,168,34,5, true, "sprite.bmp",fsprite);
Box pear3(290,490,195,225,370,173,78,255,573,213,171,29,5, true, "sprite.bmp",fsprite);
Box pear4(300,485,165,195,370,173,78,255,576,182,162,27,5, true, "sprite.bmp",fsprite);
Box pear5(315,470,135,165,370,173,78,255,584,151,142,23,5, true, "sprite.bmp",fsprite);
Box pear6(330,450,104,134,370,173,78,255,599,124,112,22,5, true, "sprite.bmp",fsprite);
Box pear7(343,434,87,104,370,173,78,255,607,107,86,15,5, true, "sprite.bmp",fsprite);
Box pear8(350,420,69,86,370,173,78,255,613,88,68,15,5, true, "sprite.bmp",fsprite);
Box pear9(360,405,55,69,370,173,78,255,617,62,46,14,5, true, "sprite.bmp",fsprite);


//Play
Box fplay(350,450,580,590,0,0,255,255,0,120,63,8,-1, true, "sprites.bmp",fsprite);


//fball
Ball fball(400,569,135,135, 7,200, 255,67,55,255);
Ball farb(70,530,-100,-100, 7,225, 0,255,55,255);

//line right
Line fline_right(400,580,420,550,255,255,255,255);

//line left
Line fline_left(400,580,380,550,255,255,255,255);

//walking area 1
Box fwalk(0,800,800,900,0,0,255,255,212,463,270,45,-1, true, "terrain.bmp",fsprite);

//player
Box fplayer(400,435,745,800,255,0,0,0,216,244,14,26,-1,true, "characters.bmp",fsprite);

//hit boxes
Box fbox1(55,85,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);
Box fbox2(185,215,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);
Box fbox3(315,345,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);
Box fbox4(445,475,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);
Box fbox5(575,605,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);
Box fbox6(705,735,640,670,255,0,0,255,783,532,30,30,-1,true,"bleh",fsprite);

//hit over box when hit
Box foverbox1(0,125,630,640,0,0,255,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);
Box foverbox2(130,250,630,640,0,0,0,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);
Box foverbox3(255,375,630,640,0,0,0,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);
Box foverbox4(380,520,630,640,0,0,0,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);
Box foverbox5(525,645,630,640,0,0,0,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);
Box foverbox6(650,800,630,640,0,0,0,0,20,651,63,6,-1, true, "sprites.bmp",fsprite);

//SDL_SetColorKey(surface,SDL_TRUE,0);


std::vector<Box *> fBrickList;
std::vector<Ball*> fBallList;
std::vector<Box *> fHitBoxes;
vector<Box *> fOverBoxes;

class FinalLevel{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 900;



	FinalLevel(){
		key_a = true;
		key_d = false;
		first = true;
		lose_disable = false;
		changer_r = true;
		ichange_r = 0;
		changer_l = true;
		ichange_l = 0;
		for (int i = 0; i < 5; i++){
			fOverBoxes_hit[i] = 0;
		}
		fOverBoxes_hit[5] = 0;
		lives = 3;
		finalwin = false;
		//fBrickList.push_back(&fbrick1);
		fBrickList.push_back(&fbrick2);
		fBrickList.push_back(&fbrick3);
		//fBrickList.push_back(&fbrick4);
		//fBrickList.push_back(&fbrick10);
		fBrickList.push_back(&fbrick11);
		fBrickList.push_back(&fbrick12);
		//BrickList.push_back(&fbrick13);

		fBrickList.push_back(&fbrick14);
		fBrickList.push_back(&fbrick15);
		fBrickList.push_back(&fbrick16);
		fBrickList.push_back(&fbrick17);
		fBrickList.push_back(&fbrick18);
		fBrickList.push_back(&fbrick19);
		fBrickList.push_back(&fbrick20);
		fBrickList.push_back(&fbrick21);
		fBrickList.push_back(&fbrick22);
		fBrickList.push_back(&fbrick23);
		fBrickList.push_back(&fbrick24);
		fBrickList.push_back(&fbrick25);
		fBrickList.push_back(&fbrick26);
		fBrickList.push_back(&fbrick27);
		fBrickList.push_back(&fbrick28);
		fBrickList.push_back(&pear0);
		fBrickList.push_back(&pear1);
		fBrickList.push_back(&pear2);
		fBrickList.push_back(&pear3);
		fBrickList.push_back(&pear4);
		fBrickList.push_back(&pear5);
		fBrickList.push_back(&pear6);
		fBrickList.push_back(&pear7);
		fBrickList.push_back(&pear8);
		fBrickList.push_back(&pear9);
		fHitBoxes.push_back(&fbox1);
		fHitBoxes.push_back(&fbox2);
		fHitBoxes.push_back(&fbox3);
		fHitBoxes.push_back(&fbox4);
		fHitBoxes.push_back(&fbox5);
		fHitBoxes.push_back(&fbox6);
		fOverBoxes.push_back(&foverbox1);
		fOverBoxes.push_back(&foverbox2);
		fOverBoxes.push_back(&foverbox3);
		fOverBoxes.push_back(&foverbox4);
		fOverBoxes.push_back(&foverbox5);
		fOverBoxes.push_back(&foverbox6);



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

			if (fball.hit_bottom){
				if(!lose_disable){
					if (lives != 0){
						lives--;
						fball.start = false;
						first = true;
						fball.hit_bottom = false;
						fball.ball_position.x = 400;
						fball.ball_position.y = 569;
					} else {
						return -1;
					}

				}
			}

			if (fBrickList.size() == 0 || finalwin){
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
			fball.start = true;
			arb.start = true;
			first = false;
		}else if (key == SDLK_r){

			Vector2d rotation( cos(30*(M_PI/180)), sin(30*(M_PI/180)) );
			Vector2d new_direction(
			rotation.x*fball.ball_direction.x - rotation.y*fball.ball_direction.y,
			rotation.x*fball.ball_direction.y + rotation.y*fball.ball_direction.x);
			fball.ball_direction = new_direction;

		} else if (key == SDLK_a){

		} else if (key == SDLK_d){

		} else if (key == SDLK_n){
			lose_disable = true;
		} else if (key == SDLK_UP){
			key_w = true;
		} else if (key == SDLK_k){
			finalwin = true;
		}
	}
	void handle_mouse_down2(int x, int y, int button){
		if (button == SDL_BUTTON_LEFT){
			fball.start = true;
			first = false;
			arb.start = true;
		}
	}
	void handle_mouse_up2(int x, int y, int button){
	}
	void handle_mouse_moved2(int x, int y){
		//printf("x is %d, y is %d\n", x,y);
	}

	void draw2(SDL_Renderer *renderer, float frame_delta_ms){

		fball.move(renderer,frame_delta_ms,CANVAS_SIZE_X, CANVAS_SIZE_Y-100);
		fball.screen_collission(CANVAS_SIZE_X, CANVAS_SIZE_Y-100);


		for (int k = 0; k < fBrickList.size(); k++){
					(fball.ball_rectangle_col(fBrickList[k]));
					(arb.ball_rectangle_col(fBrickList[k]));
					if(fBrickList[k]->hits ==1 && fBrickList[k]->hits_to_destroy ==1){
						fBrickList.erase(fBrickList.begin()+k);
					}else if (fBrickList[k]->hits ==1 && fBrickList[k]->hits_to_destroy == 3){
						fBrickList[k]->clip_x = 405;
					} else if (fBrickList[k]->hits ==2 && fBrickList[k]->hits_to_destroy == 3){
						fBrickList[k]->clip_x = 356;
					} else if (fBrickList[k]->hits ==3 && fBrickList[k]->hits_to_destroy == 3){
						fBrickList.erase(fBrickList.begin()+k);
					}
		}

		for (int j = 0; j < fHitBoxes.size(); j++){
			fball.ball_rectangle_col(fHitBoxes[j]);
			if (fOverBoxes_hit[j] > 0){
				fball.ball_rectangle_col(fOverBoxes[j]);
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

		player.ball_intersection(&fball.new_position, &fball.ball_position,fball.radius,&fball.ball_direction);

		for (int j = 0; j < fHitBoxes.size(); j++){
			player.box_collision(fHitBoxes[j], fOverBoxes_hit, j);
		}




		SDL_SetRenderDrawColor(renderer, 0, 255, 247, 255);
		SDL_RenderClear(renderer);

		fball.draw(renderer,frame_delta_ms,CANVAS_SIZE_X,CANVAS_SIZE_Y);





		//draw each box
		for (int k = 0; k < fBrickList.size(); k++){
			fBrickList[k]->draw(renderer);
		}
		for (int k = 0; k < fHitBoxes.size(); k++){
			fHitBoxes[k]->draw(renderer);
			if (fOverBoxes_hit[k] > 0){
				//printf("%d\n", fOverBoxes_hit[k]);
				fOverBoxes[k]->draw(renderer);
				fOverBoxes_hit[k]--;
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
	bool first, play_mouse, play_keyboard, key_a, key_d, balls_2, lose_disable, key_w, changer_r, changer_l,finalwin;
	int mouse_x, ichange_r, ichange_l, lives;
	int fOverBoxes_hit[6];


};


