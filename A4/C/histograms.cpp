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

void histogram(PNG_Canvas_BW image, int width, int height, int h[]){
	for (int x =0; x < width -1; x++){
		for (int y = 0; y < height-1; y++){
			h[image[x][y]] = h[image[x][y]]+1;
		}
	}
}

void cumu_histogram(PNG_Canvas_BW image, int width, int height, int H[]){
	int h[256];
	histogram(image, width, height, h);
	H[0] = h[0];
	for (int a = 1; a < 256; a++){
		H[a] = h[a-1] + h[a];
	}
}



void match_histograms(int F[], int h[],  int width, int height, int Href[], int nref ){
	int n = width * height;
	int r = n/nref;
	//int h[256];
	//histogram(image,width,height,h); //non cumulative histogram
	printf("%d\n",r);
	int i = 0;
	int c = 0;
	int j = 0;
	while (i < 256){
		if (c <= r*Href[j]){
			c += h[i];
			F[i] = j;
			i = i + 1;
		} else {
			j = j + 1;
		}
	}
}

void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();






	/*
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
	*/

	int h[256] = {0};
	for (int x =0; x < width; x++){
		for (int y = 0; y < height; y++){
			h[image.get_pixel(x,y)] = h[image.get_pixel(x,y)]+1;
		}
	}

	int H[256] = {0};
	for (int x =0; x < width; x++){
		for (int y = 0; y < height; y++){
			H[image[x][y]] = H[image[x][y]]+1;
		}
	}
	H[0] = h[0];
	for (int a = 1; a < 256; a++){
		H[a] = H[a-1] + H[a];
	}

	//gaussian distribution
	double normal[256] = {0};
	int sigma = 50;
	int m = 128;
	float sigmasqr2pi = sigma * sqrt(2*M_PI);
	float twosigma2 = 2 * sigma * sigma;
	for (int x = 0; x< 256; x++){
		normal[x] = exp((-pow((x-m),2))/twosigma2)/(sigmasqr2pi);
		for(int y = 0; y < 256; y++){

		}
	}

	for (int b = 1; b < 256; b++){
		normal[b] = normal[b-1]+normal[b];
	}

	/*
	for (int i = 0; i < 256; i++){
		printf("%f\n",normal[i]);
	}
	*/

	int F[256] = {0};

	int n = width * height;
	int r = n/1;
	int i = 0;
	int c = 0;
	int j = 0;
	while (i < 256){
		if (c <= r*normal[j]){
			printf("%f\n", r*normal[i]);
			c += h[i];
			F[i] = j;
			i = i + 1;
		} else {
			j = j + 1;
		}
	}






	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
	
	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			outputImage[x][y] = F[image[x][y]];
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
