#include <string.h>

class FinalIntro{
public:
	static const int CANVAS_SIZE_X = 800;
	static const int CANVAS_SIZE_Y = 900;



	FinalIntro(){
		kill = false;

	}
	void frame_loop_win(SDL_Renderer* r){
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
				if (kill){
					break;
				}

				draw_win(r,delta_ms);

				last_frame = current_frame;
				frame_number++;

			}


		}


	private:

		void handle_key_down2(SDL_Keycode key){
			if (key == SDLK_SPACE){
				kill = true;
			}
		}
		void handle_mouse_down2(int x, int y, int button){
		}
		void handle_mouse_up2(int x, int y, int button){
		}
		void handle_mouse_moved2(int x, int y){
		}

		void draw_win(SDL_Renderer *renderer, float frame_delta_ms){



			SDL_SetRenderDrawColor(renderer, 28, 102, 204, 255);
			SDL_RenderClear(renderer);

			stringRGBA(renderer,300,300,"YOU HAVE REACH CSC205 FINAL BOSS",255,0,0,255);
			stringRGBA(renderer,500,400,"PRESS SPACE WHEN READY",255,0,0,255);




			SDL_RenderPresent(renderer);
		}
		bool kill;
};
