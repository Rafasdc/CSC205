/* ImageProcessor205.java
   CSC 205 - Spring 2016
   Image Processor Template
   

   B. Bird - 10/15/2015
*/

import java.awt.Color;
import java.math.*;
import javax.imageio.ImageIO;
import java.awt.Dimension;
import java.awt.image.BufferedImage;
import java.io.File;


public class Gaussian {

	static int[] compute_histogram(int[][] pixels, int width, int height){
		int h[] = new int[256];
		for (int x =0; x < width ; x++){
			for (int y = 0; y < height; y++){
				h[pixels[x][y]] = h[pixels[x][y]]+1;
			}
		}
		return h;
	}
	
	static int[] cumulative_hist(int[][] pixels, int width, int height){
		int H[] = compute_histogram(pixels,width,height);
		for (int i = 1; i < H.length; i++){
			H[i] = H[i-1] + H[i];
		}
		return H;
		
	}
	
	static double[] CDF(int[] h){
		int K = h.length;
		int n = 0;
		for (int i=0; i<K;i++){
			n += h[i];
		}
		
		double [] P = new double[K];
		int c = 0;
		for (int i = 0; i< K; i++){
			c += h[i];
			P[i] = (double) c/n;
		}
		return P;
	}
	
	 static int[] matchHistograms (int[] hA, int[] hR) {
		 int K = hA.length; 
		 double[] PA = CDF(hA);
		 double[] PR = CDF(hR);
		 int[] F = new int[K];
		 for(int a=0;a<K;a++){
			 int j = K-1;
			 do {
				 F[a] = j;
				 j--;
			 } while (j>=0 && PA[a]<=PR[j]);
		 }
		
		 return F;
		 }

	static int[] match_histrograms(int[][] pixels, int width,  int height, int Href[], int nref){
		int n = width * height;
		int h[] = compute_histogram(pixels,width,height); //non cumulative histogram of pixels array
		int r = n/nref;
		//System.out.println(r);
		int F[] = new int[256];
		int i = 0;
		int j = 0; 
		int c = 0;
		while (i < 256) {
			if (c <= r * Href[j]){
				c = c + h[i];
				F[i] = j;
				i++;
			} else {
				j++;
			}
		}
		return F; //integer array
	}

	static float[][] gaussian(){
		float sigma = 1.0f;
		float twosigma2 = 2 * sigma * sigma;
		float[][] kernel = new float[5][5];
		float sum = 0;
		for (int x = 0; x < kernel.length; x++){
			for(int y = 0; y < kernel.length; y++){
				kernel[x][y] = (float) Math.exp( -((x*x)+(y*y))/twosigma2);
				sum += kernel[x][y];
			}
		}

		return kernel;
	}
	

	
	
	
	
	public static int[][] ProcessImage( int [][] inputPixels){
		int width = inputPixels.length;
		int height = inputPixels[0].length;
		
		int[] h = compute_histogram(inputPixels,width,height);
		int[] href = cumulative_hist(inputPixels,width,height);
		double a = 0;
		
		float [][] gaussian = gaussian();
		double sum = 0;
		for (int i = 0; i < gaussian.length; i++){
			for (int j=0; j < gaussian.length; j++){
				sum += gaussian[i][j];
				System.out.print(gaussian[i][j]+ " ");
			}
			System.out.print("\n");
		}
		System.out.println("sum is" + sum);
		//int[] F = match_histrograms(inputPixels,width,height,test,256);
		//int[] F = matchHistograms(h,test);
		
		for (int x = 0; x < width; x++){
			for (int y = 0; y < height; y++){
				//inputPixels[x][y] = F[inputPixels[x][y]];
			}
		}
			
				//inputPixels[x][y] = 255-inputPixels[x][y];
				//inputPixels[x][y];
		return inputPixels;
	}
	
	
	private static Color[][] load_image(String image_filename){
		BufferedImage inputImage = null;
		try{
			System.err.printf("Reading image from %s\n",image_filename);
			inputImage = ImageIO.read(new File(image_filename));
		} catch(java.io.IOException e){
			ErrorExit("Unable to open %s: %s\n",image_filename,e.getMessage());
		}
		int width = inputImage.getWidth();
		int height = inputImage.getHeight();
		Color[][] imagePixels = new Color[width][height];
		for (int x = 0; x < width; x++)
			for (int y = 0; y < height; y++)
				imagePixels[x][y] = new Color(inputImage.getRGB(x,y));
		System.err.printf("Read a %d by %d image\n",width,height);
		return imagePixels;
	}
	
	
	
	private static void save_image(Color[][] imagePixels, String image_filename){
		int width = imagePixels.length;
		int height = imagePixels[0].length;
		BufferedImage outputImage = new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);
		for (int x = 0; x < width; x++)
			for(int y = 0; y < height; y++)
				outputImage.setRGB(x,y,imagePixels[x][y].getRGB());
		
		try{
			ImageIO.write(outputImage, "png", new File(image_filename));
		}catch(java.io.IOException e){
			ErrorExit("Unable to write %s: %s\n",image_filename,e.getMessage());
		}
		System.err.printf("Wrote a %d by %d image\n",width,height);
	}
	
	
	/* Convert a 2d array of Color objects to a 2d array of intensities, in the range [0,255]
	   by averaging */
	private static int[][] ColoursToIntensities(Color[][] inputPixels){
		int width = inputPixels.length;
		int height = inputPixels[0].length;
		int[][] intensities = new int[width][height];
		for (int x = 0; x < width; x++)
			for(int y = 0; y < height; y++)
				intensities[x][y] = (inputPixels[x][y].getRed()+inputPixels[x][y].getGreen()+inputPixels[x][y].getBlue())/3;
		return intensities;
	}
	
	
	private static Color[][] IntensitiesToColours(int[][] intensities){
		int width = intensities.length;
		int height = intensities[0].length;
		Color[][] outputPixels = new Color[width][height];
		for (int x = 0; x < width; x++)
			for(int y = 0; y < height; y++)
				outputPixels[x][y] = new Color(intensities[x][y],intensities[x][y],intensities[x][y]);
		return outputPixels;
	}
	
	
	public static void main(String[] args){
		if (args.length < 1){
			System.out.printf("Usage: ImageProcessor205BW <input image>\n");
			return;
		}
		
		String input_filename = args[0];
		
		if (!input_filename.toLowerCase().endsWith(".png"))
			ErrorExit("Input file must be a PNG image.\n");
			
		String output_filename = null;
		if (args.length > 1)
			output_filename = args[1];
		else
			output_filename = input_filename.substring(0,input_filename.length()-4)+"_output.png";
			
		

		Color[][] inputPixels = load_image(input_filename);
		
		int[][] inputIntensities = ColoursToIntensities(inputPixels);
				
		int[][] resultIntensities = ProcessImage(inputIntensities);
		
		Color[][] resultPixels = IntensitiesToColours(resultIntensities);
		
		save_image(resultPixels, output_filename);
		
	}
	/* Prints an error message and exits (intended for user errors) */
	private static void ErrorExit(String errorMessage, Object... formatArgs){
		System.err.printf("ERROR: " + errorMessage + "\n",formatArgs);
		System.exit(0);
	}
	/* Throws a runtime error (intended for logic errors) */
	private static void ErrorAbort(String errorMessage, Object... formatArgs){
		throw new Error(String.format(errorMessage,formatArgs));
	}

}

