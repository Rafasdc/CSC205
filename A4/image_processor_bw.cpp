/* image_processor_bw.cpp
   CSC 205 - Spring 2016
   
   Template for a grayscale PNG image processor.
   
   B. Bird - 03/02/2016
*/

#include <string>
#include <iostream>
#include "lodepng.h"
#include "png_canvas.h"

using namespace std;



void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();
	


	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
	
	//Placeholder: invert the image
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			outputImage[x][y] = 255 - image[x][y];
			
			
	//Copy the result back into the provided image
	image = outputImage;
}


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



/*
double CDF[] (int h[]){
	int K = h.length;
	int n = 0;
	for (int i = 0; i < K; i++){
		n += h[i];
	}

	double P[] = new double [k];
	int c = 0;
	for (int i = 0; i < K; i++){
		c += h[i];
		P[i] = (double) c/n;
	}
	return P;
}
*/




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
