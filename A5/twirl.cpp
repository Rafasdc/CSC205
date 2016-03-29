/* image_processor_bw.cpp
   CSC 205 - Spring 2016
   
   Template for a grayscale PNG image processor.
   
   B. Bird - 03/02/2016
*/

#include <string>
#include <iostream>
#include "lodepng.h"
#include "png_canvas.h"
#include <math.h>

using namespace std;



void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();

	
	//image dilatate with and then erode with H

	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW transformed(width,height);
	
	double rmax = (double) width/2;
	double xc = (double) width/2;
	double yc = (double) height/2;
	double alpha = 43;
	double dx;
	double dy;
	double r;
	double betha;
	double Tx;
	double Ty;

	for (int x = 0; x < width; x++){
			for (int y = 0; y < height; y++){

				dx = x - xc;
				dy = y - yc;
				r = sqrt(dx*dx + dy*dy);
				betha = atan2(dy,dx) + alpha * ((rmax-r)/rmax);

				if (r > rmax){
					Tx = x;
				} else {
					Tx = xc+(r*cos(betha));
				}
				if (r > rmax){
					Ty = y;
				} else {
					Ty = yc+(r*sin(betha));
				}

				//printf("%f\n",Tx);
				//printf("%f\n",Ty);

				double x0 = floor(Tx);
				double y0 = floor(Ty);
				double x1 = ceil(Tx);
				double y1 = ceil(Ty);
				double xs = Tx - x0;
				double ys = Ty - y0;
				/*
				if(x0 > 255) x0 = 128;
				if(x1 > 255) x1 = 128;
				if (y0 > 255) y0 = 128;
				if (y1 > 255) y1 = 128;
				if(x0 < 0) x0 = 0;
				if(x1 < 0) x1 = 0;
				if (y0 < 0) y0 = 0;
				if (y1 < 0) y1 = 0;
				*/
				double p0 = (image.get_pixel(x0,y0) * (1-xs))+ (image.get_pixel(x1,y0)*xs);
				double p1 = image.get_pixel(x0,y1) * (1-xs)+image.get_pixel(x1,y1)*xs;
				double result = p0 *(1-ys) + p1 *ys;
				if (result > 255) result = 128;
				if (result < 0) result = 128;
				transformed.set_pixel(x,y,result);

			}
		}



			
			
	//Copy the result back into the provided image
	image = transformed;
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
