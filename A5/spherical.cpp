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
	
	double rmax = width/2;
	double xc = (double) width/2;
	double yc = (double) height/2;
	double dx;
	double dy;
	double r;
	double z;
	double bethax;
	double bethay;
	double Tx;
	double Ty;
	double refract = 1.5;
	double refractoverone = 1/refract;
	double dxz;
	double dyz;

	for (int x = 0; x < width; x++){
			for (int y = 0; y < height; y++){

				dx = x - xc;
				dy = y - yc;
				r = sqrt(dx*dx + dy*dy);
				z = sqrt(rmax*rmax - r*r);
				dxz = sqrt(dx*dx+z*z);
				dyz = sqrt(dy*dy+z*z);
				bethax = (1-refractoverone) * asin(dx/dxz);
				bethay = (1-refractoverone) * asin(dy/dyz);


				if (r > rmax){
					Tx = x;
				} else {
					Tx = x - ( z*tan(bethax));
				}
				if (r > rmax){
					Ty = y;
				} else {
					Ty = y - (z*tan(bethay));
				}

				//printf("%f\n",Tx);
				//printf("%f\n",Ty);

				int x0 = floor(Tx);
				int y0 = floor(Ty);
				int x1 = ceil(Tx);
				int y1 = ceil(Ty);
				int xs = Tx - x0;
				int ys = Ty - y0;
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
				int dx = 1 - xs;
				int dy = 1 - ys;
				int p0 = (image.get_pixel(x0,y0)*dx)+(image.get_pixel(x1,y0)*xs);
				int p1 = (image.get_pixel(x0,y1)*dx)+(image.get_pixel(x1,y1)*xs);
				int result = (p0 * dy) + (p1 *ys);
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
