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
	

	//Placeholder: invert the image
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			if (image.get_pixel(x,y) < 128) binary[x][y] = 1;
			if (image.get_pixel(x,y) >= 128) binary[x][y] = 0;
		}
	}

	PNG_Canvas_BW binarycopy(width,height);

	for (int j = 0; j < 2; j++){
		for (int i = 0; i < 2; i++){
			if (H[j][i] == 1){
				//target.copybits(source,target of source inserted in target, same as previous,Max of (target,source)
			}
		}
	}
			
			
	//Copy the result back into the provided image
	//image = outputImage;
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
