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
	
	double sigma = 2.5;
	double kernel[5][5];
	double sum = 0;
	for (int x=0; x< 5; x++){
		for (int y = 0; y < 5; y++){
			kernel[x][y] = exp((-(x*x)+(y*y))/(2*sigma*sigma));
					//exp(-0.5 * (pow((x-2.5)/sigma, 2.0) + pow((y-2.5)/sigma,2.0)))/(2 * M_PI * sigma * sigma);
			sum += kernel[x][y];
		}
	}
	//double sum = 0.0;

	for (int x = 0; x<5; x++){
		for(int y = 0; y < 5; y++){
			//kernel[x][y] /= sum;
			printf(" %f ",kernel[x][y]);
		}
		printf("\n");
	}

	printf("%f\n",sum);

	int K = 2;
	double s = 1.0/sum;


	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
	
	for (int y = K; y < height-K-1; y++){
		for (int x = K; x < width-K-1; x++){
			int sum = 0;
			for (int j = -K; j <= K; j++){
				for (int i = -K; i <= K; i++){
					int p = image.get_pixel(x+i,y+j);
					int c = kernel[j+K][i+K];
					sum += c * p;
				}
			}
			int q = round(s*sum);
			if (q < 0) q = 0;
			if (q > 255) q = 255;
			outputImage.set_pixel(x,y,q);
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
