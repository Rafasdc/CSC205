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

int* compute_histogram(PNG_Canvas_BW pixels, int width, int height){
	int *h = 0;
	for (int x =0; x < width -1; x++){
		for (int y = 0; y < height-1; y++){
			h[pixels.get_pixel(x,y)] = h[pixels.get_pixel(x,y)]+1;
		}
	}
	return h;
}
/*
int match_histrograms(PNG_Canvas_BW pixels, int width,  int height, int Href[][], int nref){
	int n = width * height;
	int r = n/nref;
	int h[][] = 0; //non cumulative histogram of pixels array
	int F[256] = 0;
	int i, j , c = 0;
	while (i < 256) {
		if (c<= r * Href[j]){
			c = c + h[i];
			F[i] = j;
			i = i + 1;
		} else {
			j++;
		}
	}
	return F; //integer array
}
*/

void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();
	
	int laplace[3][3] = {
					{0, 1, 0},
					{1,-4, 1},
					{0, 1, 0}
	};


	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
	
	for (int y = 1; y < height-2; y++){
		for (int x = 1; x < width-2; x++){
			int sum = 0;
			for (int j = -1; j <= 1; j++){
				for (int i = -1; i <= 1; i++){
					int p = image.get_pixel(x+i,y+j);
					int c = laplace[j+1][i+1];
					sum += c * p;
				}
			}
			//inputPixels[x][y] = F[inputPixels[x][y]];
			int q = sum;
			if (q < 0) q = 0;
			if (q > 255) q = 255;
			outputImage.set_pixel(x,y,q);
		}
	}



	for (int x = 0; x < width; x++){
		for (int y = 0; y< height; y++){
			int s = image.get_pixel(x,y) - 0.5*outputImage.get_pixel(x,y);
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
