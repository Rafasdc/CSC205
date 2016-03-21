/* image_processor_bw.cpp
   CSC 205 - Spring 2016
   
   Template for a grayscale PNG image processor.
   
   B. Bird - 03/02/2016
*/

#include <string>
#include <iostream>
#include <array>
#include <math.h>
#include "lodepng.h"
#include "png_canvas.h"

using namespace std;



void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();
	

	//non-cumualtive hist
	int h[256];
	for (int x =0; x < width -1; x++){
		for (int y = 0; y < height-1; y++){
			h[image.get_pixel(x,y)] = h[image.get_pixel(x,y)]+1;
		}
	}
	//cumulative hist
	int H[256];
	H[0] = h[0];
	for (int a = 1; a < 255; a++){
		H[a] = h[a-1] + h[a];
	}

	//gaussian distribution
	double normal[256];
	for (int x = 0; x< 256; x++){
		int sigma = 50;
		int m = 128;
		float sigmasqr2pi = sigma * sqrt(2*M_PI);
		float twosigma2 = 2 * sigma * sigma;
		normal[x] = exp((-pow((x-m),2))/twosigma2)/(sigmasqr2pi);
	}

	//inversed bell curve
	double gx[256];
	for (int b = 0; b < 256; b ++){
		int sigma = 50;
		int m = 128;
		float sigmasqr2pi = sigma * sqrt(2*M_PI);
		float twosigma2 = 2 * sigma * sigma;
		float gm = exp((-pow((m-m),2))/twosigma2)/(sigmasqr2pi);
		gx[b] = gm - normal[b];
		//printf("%f\n",normal[b]);
	}


	//histogram matching
	int Href[256];
	copy(H,H+256,Href);
	int F[256];
	int i = 0;
	int c = 0;
	int j = 0;
	while (i < 256){
		if (c <= normal[j]){
			c += h[i];
			F[i] = j;
			i = i + 1;
		} else {
			j = j + 1;
		}
	}


	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
	
	for (int y = 1; y < height-2; y++){
		for (int x = 1; x < width-2; x++){
			double s = F[image[x][y]];
			outputImage.set_pixel(x,y,s);
		}
	}


			

	image = outputImage;
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
