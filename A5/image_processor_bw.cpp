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
	int H[5][5]= {
			{0,0,1,0,0},
			{0,1,1,1,0},
			{1,1,1,1,1},
			{0,1,1,1,0},
			{0,0,1,0,0}
	};
	
	//image dilatate with and then erode with H

	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW binary(width,height);
	

	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			if (image.get_pixel(x,y) <= 128) binary[x][y] = 1;
			if (image.get_pixel(x,y) > 128) binary[x][y] = 0;

		}
	}

	PNG_Canvas_BW binarycopy(width,height);



	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (H[i][j] == 1  ){
				//printf("inside H\n");
				//binarycopy[i][j] = image[i][j];
				for (int u = 0 ; u < width; u++){
					for (int v = 0; v < height; v++){
						if (binary[u][v] == 1){
							binarycopy[u+i][v+j] = 1;
						}
					}
				}

			}
		}
	}


	for (int i =0; i <= width; i++){
		for (int j = 0; j <= width; j++){
			//printf("%d\n", binarycopy[i][j]);
			if (binarycopy[i][j] == 1){
				image[i][j] = 0;
			} else {
				image[i][j] = 255;
			}
		}
	}


	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (H[i][j] == 1  ){
				//printf("inside H\n");
				//binarycopy[i][j] = image[i][j];
				for (int u = 0 ; u < width; u++){
					for (int v = 0; v < height; v++){
						if (image[u][v] == 255){
							binarycopy[u+i][v+j] = 255;
						}
					}
				}

			}
		}
	}


			
			
	//Copy the result back into the provided image
	image = binarycopy;
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
