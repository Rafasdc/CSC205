/* image_processor_bw.cpp
   CSC 205 - Spring 2016
   
   Template for a grayscale PNG image processor.
   
   B. Bird - 03/02/2016
*/

#include <string>
#include <iostream>
#include <math.h>
#include "lodepng.h"
#include "png_canvas.h"

using namespace std;



void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();

	
	//image dilatate with and then erode with H

	//Make a new image canvas for the output to avoid conflicts
	int new_w = width+500;
	int new_h = height+500;
	PNG_Canvas_BW imagenew(new_w,new_h);
	
	float wnw = ((double) width)/((double)new_w);
	float hnh = ((double) height)/((double)new_h);
	//printf("%f",wnw);
	for (int x = 0; x < new_w; x++){
		for (int y = 0; y < new_h; y++){
			float x0 = (double) x * wnw;
			//printf("%f\n",x0);
			float y0 = (double) y * hnh;
			//printf("%f\n",y0);
			if (x0 > 256) x0 = 128;
			if (y0 > 256) y0 = 128;
			int ix = round(x0);
			int iy = round(y0);
			imagenew.set_pixel(x,y,image.get_pixel(ix,iy));

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
	
	PNG_Canvas_BW canvas;
	if (!canvas.load_image(input_filename)){
		cerr << "Unable to load " << input_filename << ". Exiting..." << endl;
		return 0;
	}
	
	process_image(canvas);
	canvas.save_image(output_filename);
	
	
}
