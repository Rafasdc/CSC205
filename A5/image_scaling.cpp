/*
 * Rafael Solorzano
 * V00838235
 * CSC205 Assignment 5
 *
 *
*/

#include <string>
#include <iostream>
#include <math.h>
#include "lodepng.h"
#include "png_canvas.h"

using namespace std;

int width_in = 600;
int height_in = 600;

void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();


	
	//image dilatate with and then erode with H

	//Make a new image canvas for the output to avoid conflicts
	int new_w = width_in;
	int new_h = height_in;
	PNG_Canvas_BW imagenew(new_w,new_h);
	
	float wnw = ((double) width)/((double)new_w);
	float hnh = ((double) height)/((double)new_h);
	//printf("%f",wnw);
	for (int x = 0; x < new_w; x++){
		for (int y = 0; y < new_h; y++){
			int x0 = floor(x * wnw);
			int y0 = floor(y*hnh);
			int x1 = ceil(x*wnw);
			int y1 = ceil(y*hnh);
			int xs = x - x0;
			int ys = y - y0;
			int dx = 1 - xs;
			int dy = 1 - ys;
			int p0 = (image.get_pixel(x0,y0)*dx)+(image.get_pixel(x1,y0)*xs);
			int p1 = (image.get_pixel(x0,y1)*dx)+(image.get_pixel(x1,y1)*xs);
			int result = (p0 * dy) + (p1 *ys);
			if (result > 255) result = 128;
			if (result < 0) result = 128;
			imagenew.set_pixel(x,y,result);

		}
	}


			
			
	//Copy the result back into the provided image
	image = imagenew;
}



int main(int argc, char** argv){
	if (argc < 3){
		cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
		return 0;
	}
	string input_filename = argv[1];
	string output_filename = argv[2];
	if (argc > 3){
			sscanf(argv[3],"%d",&width_in);
			sscanf(argv[4],"%d",&height_in);
		}
	
	PNG_Canvas_BW canvas;
	if (!canvas.load_image(input_filename)){
		cerr << "Unable to load " << input_filename << ". Exiting..." << endl;
		return 0;
	}
	
	process_image(canvas);
	canvas.save_image(output_filename);
	
	
}
