/* LSViewer.cpp

   B. Bird - 02/08/2016
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "LSystem.h"
#include "matrix.h"
//#include "colourRGB.h"
#include "transformed_renderer.h"

using namespace std;

//static const int WINDOW_SIZE_X = 800;
//static const int WINDOW_SIZE_Y = 600;
int WINDOW_SIZE_X = 800;
int WINDOW_SIZE_Y = 600;


class A3Canvas{
public:

	A3Canvas(LSystem* L){
		LS_iterations = 0;
		this->L_system = L;

	}

	
	void frame_loop(SDL_Renderer* r){
		unsigned int last_frame = SDL_GetTicks();
		//unsigned int frame_number = 0;
		draw(r,0);
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
						handle_key_down(e.key.keysym.sym);
						draw(r,delta_ms);
						break;
					case SDL_WINDOWEVENT:
						switch(e.window.event){
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							printf("size changed\n");
							WINDOW_SIZE_X = e.window.data1;
							WINDOW_SIZE_Y = e.window.data2;
							draw(r,0);
						}
						break;
					default:
						break;
				}
			}
			
			

		}
		

	}
private:
	int LS_iterations;
	LSystem* L_system;
	void handle_key_down(SDL_Keycode key){
		if (key == SDLK_UP){
			LS_iterations++;
		}else if (key == SDLK_DOWN){	
			LS_iterations--;
			if (LS_iterations < 0)
				LS_iterations = 0;
		}
	}
	
	
	inline Matrix3 Rotation(float radians){
		Matrix3 M;
		M.identity();
		M(0,0) = M(1,1) = cos(radians);
		M(1,0) = -(M(0,1) = sin(radians));
		return M;
	}
	inline Matrix3 Translation(float tx, float ty){
		Matrix3 M;
		M.identity();
		M(0,2) = tx;
		M(1,2) = ty;
		return M;
	}
	inline Matrix3 Scale(float sx, float sy){
		Matrix3 M;
		M.identity();
		M(0,0) = sx;
		M(1,1) = sy;
		return M;
	}


	void draw_leaf(TransformedRenderer& tr){
		float vx[] = {0,1.0 ,1.25,   1,  0,  -1,-1.25,-1};
		float vy[] = {0,0.75,1.75,2.75,4.0,2.75, 1.75,0.75};
		int numVerts = 8;
		tr.fillPolygon(vx,vy,numVerts, 64,224,0, 255);
		/*
		SDL_Surface* grass = SDL_LoadBMP("leaf.bmp");
		tr.fillTexturePolygon(vx,vy,numVerts,grass);
		SDL_FreeSurface(grass);
		*/
		tr.drawPolygon(vx,vy,numVerts, 64,128,0, 255);

	}

	void draw_stem(TransformedRenderer& tr, int h){
		tr.drawRectangle(-1,0,1,h,255,255,255,255);
		//float vx[] = {-1,1,1,-1};
		//float vy[] = {0,0,7,7};
		tr.fillRectangle(-1,0,1,h,102,51,0,255);
		/*
		SDL_Surface* trunk = SDL_LoadBMP("woodtexture.bmp");
		tr.fillTexturePolygon(vx,vy,4,trunk);
		SDL_FreeSurface(trunk);
		*/
		tr.drawRectangle(-1,0,1,h,95,68,4,255);
	}

	void draw_banana(TransformedRenderer& tr){
		float vx[] = {0,1.5,1,5,0.85,0,-1,-1.15,-1.6,-1.4};
		float vy[] = {-0.45,0.05,1.2,2.5,3.35,2.9,2,1,0};
		int numVerts = 9;
		tr.fillPolygon(vx,vy,numVerts,204,255,51,255);
		/*
		SDL_Surface* banana = SDL_LoadBMP("banana.bmp");
		tr.fillTexturePolygon(vx,vy,numVerts,banana);
		SDL_FreeSurface(banana);
		*/
		tr.drawPolygon(vx,vy,numVerts,204,175,51,255);
	}

	void draw_apple(TransformedRenderer& tr){
		float vx[] = {0,1,1.95,2,0.9,0,-0.9,-2,-1.95,-1};
		float vy[] = {0,-1,0.95,2.4,3.3,3,3.3,2.4,0.95,-1};
		int numVerts = 10;
		tr.fillPolygon(vx,vy,numVerts,255,59,48,255);
		/*
		SDL_Surface* apple = SDL_LoadBMP("apple.bmp");
		tr.fillTexturePolygon(vx,vy,numVerts,apple);
		SDL_FreeSurface(apple);
		*/
		tr.drawPolygon(vx,vy,numVerts,200,59,48,255);
	}

	void handle_iteration(string system_string, SDL_Renderer *renderer,
			Matrix3& viewportTransform, TransformedRenderer& tr){
		for(int i = 0; i < system_string.size(); i++){
			switch(system_string[i]){
			case 'L' :
				draw_leaf(tr);
				//draw_leaf(tr);
				break;
			case 'T':
				//draw stem at pos (0,0) and multiply the local coordinate transform
				//on right by translation by (0,h), h is height of stem
				draw_stem(tr,7);
				//draw_stem(tr,7);
				viewportTransform *= Translation(0, 7);
				break;
			case '+':
				//local coordinate mult on right by c-clockwise 30 degrees
				viewportTransform *= Rotation(30*M_PI/180);
				break;
			case '-':
				//local coordinate mult on right by clockwise rotation of 30 degrees.
				/*
				viewportTransform.identity();
				viewportTransform *= Translation(WINDOW_SIZE_X/2, WINDOW_SIZE_Y);
				viewportTransform *= Scale(1,-1);
				viewportTransform *= Scale(WINDOW_SIZE_X/100.0,WINDOW_SIZE_Y/100.0);
				*/
				viewportTransform *= Rotation(330*M_PI/180);
				break;
			case 's':
				//multiply local coordinate transform on right by scale of (0.9,0.9)
				viewportTransform *= Scale(0.9,0.9);
				break;
			case 'S':
				//multiply local coordinate transform on right by scale of (1/0.9, 1/0.9);
				viewportTransform *= Scale(1/0.9,1/0.9);
				break;
			case 'h':
				//multiply local coordinate transform on right by scale of (0.9,1)
				viewportTransform *= Scale(0.9,1);
				break;
			case 'H':
				//multiply local coordinate transform on right by scale of (1/0.9,1)
				viewportTransform *= Scale(1/0.9,1);
				break;
			case 'v':
				//multiply local coordinate transform on right by scale of (1,0.9)
				viewportTransform *= Scale(1,0.9);
				break;
			case 'V':
				//multiply local coordinate transform on right by scale of (1,1/0.9)
				viewportTransform *= Scale(1,1/0.9);
				break;
			case '[':
				//save current local coordinate transform
				list.push_back(viewportTransform);
				break;
			case ']':
				//restore the last coordinate transform that was saved
				viewportTransform = (list.back());
				list.pop_back();
				break;
			case 'A':
				draw_stem(tr,10);
				viewportTransform *= Translation(0,10);
				tr.set_transform(viewportTransform);
				draw_leaf(tr);
				break;
			case 'B':
				draw_stem(tr,10);
				viewportTransform *= Translation(0,10);
				break;
			case '(':
				list.push_back(viewportTransform);
				viewportTransform *= Rotation(315*M_PI/180);
				break;
			case ')':
				viewportTransform = (list.back());
				list.pop_back();
				viewportTransform *= Rotation(45*M_PI/180);
				break;
			case 'K':
				//setup for Serpinski, Dragon,Koch,Cantor
				viewportTransform *= Translation(-50,0);
				viewportTransform *= Rotation(30*M_PI/180);
				break;
			case 'F':
				tr.fillRectangle(-1,0,1,1,102,51,0,255);
				tr.drawRectangle(-1,0,1,1,102,51,0,255);
				viewportTransform *= Translation(0,1);
				break;
			case '#':
				viewportTransform *= Rotation(270*M_PI/180);
				break;
			case '_':
				viewportTransform *= Rotation(90*M_PI/180);
				break;
			case 'G':
				tr.fillRectangle(-1,0,1,1,102,51,0,255);
				tr.drawRectangle(-1,0,1,1,102,51,0,255);
				viewportTransform *= Translation(0,1);
				break;
			case ',':
				viewportTransform *= Rotation(240*M_PI/180);
				break;
			case '.':
				viewportTransform *= Rotation(120*M_PI/180);
				break;
			case 'M':
				viewportTransform *=Translation(0,1.5);
				break;
			case 'm':
				viewportTransform *=Rotation(335*M_PI/180);
				break;
			case 'p':
				viewportTransform *=Rotation(25*M_PI/180);
				break;
			case 'R':
				draw_banana(tr);
				draw_banana(tr);
				break;
			case 'r':
				draw_apple(tr);
				//draw_apple(tr);
				break;
			case 't':
				list.push_back(viewportTransform);
				viewportTransform *= Translation(-35,50);
				viewportTransform *= Scale(0.5,0.5);
				tr.set_transform(viewportTransform);
				handle_iteration(&system_string[i+1], renderer, viewportTransform, tr);
				viewportTransform = list.back();
				list.pop_back();

				list.push_back(viewportTransform);
				viewportTransform *= Translation(35,50);
				viewportTransform *= Scale(0.5,0.5);
				tr.set_transform(viewportTransform);
				handle_iteration(&system_string[i+1], renderer, viewportTransform, tr);
				viewportTransform = list.back();
				list.pop_back();

				list.push_back(viewportTransform);
				viewportTransform *= Translation(0,75);
				viewportTransform *= Scale(0.25,0.25);
				tr.set_transform(viewportTransform);
				handle_iteration(&system_string[i+1], renderer, viewportTransform, tr);
				viewportTransform = list.back();
				list.pop_back();
				break;
			case 'n':
				viewportTransform.identity();
				viewportTransform *= Translation(WINDOW_SIZE_X/2, WINDOW_SIZE_Y);
				viewportTransform *= Scale(1,-1);
				viewportTransform *= Scale(WINDOW_SIZE_X/100.0,WINDOW_SIZE_Y/100.0);
				break;
			case 'O':
				viewportTransform *= Translation(-50,0);
				viewportTransform *= Rotation(90*M_PI/180);
				break;
			case 'D':
				viewportTransform *= Translation(0, 50);
			}



			tr.set_transform(viewportTransform);
		}
	}



	void draw(SDL_Renderer *renderer, float frame_delta_ms){
	

		//float frame_delta_seconds = frame_delta_ms/1000.0;

		string ls_string = L_system->GenerateSystemString(LS_iterations);
		cerr << "Drawing with " << LS_iterations << " iterations." << endl;
		cerr << "System string: " << ls_string << endl;



		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		TransformedRenderer tr(renderer);
		Matrix3 viewportTransform;
		viewportTransform.identity();
		viewportTransform *= Translation(WINDOW_SIZE_X/2, WINDOW_SIZE_Y);
		viewportTransform *= Scale(1,-1);
		viewportTransform *= Scale(WINDOW_SIZE_X/100.0,WINDOW_SIZE_Y/100.0);
		
		tr.set_transform(viewportTransform);
		
		//Replace this with actual drawing code..
		//draw_leaf(tr);
		handle_iteration(ls_string, renderer, viewportTransform, tr);
		
	
		SDL_RenderPresent(renderer);
	}
	std::vector<Matrix3>list;
};


int main(int argc, char** argv){

	if (argc < 2){
		cerr << "Usage: " << argv[0] << " <input file>" << endl;
		return 0;
	}
	char* input_filename = argv[1];
	
	LSystem* L = LSystem::ParseFile(input_filename);
	if (!L){
		cerr << "Parsing failed." << endl;
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("CSC 205 A3",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_SIZE_X, WINDOW_SIZE_Y, 
							  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
							  
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	//Initialize the canvas to solid green
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	A3Canvas canvas(L);

	canvas.frame_loop(renderer);
	
	delete L;
	
	return 0;
}
