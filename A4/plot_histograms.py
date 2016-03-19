# plot_histograms.py
# CSC 205 - Spring 2016
#
# A simple histogram plotter: Reads an image file and produces two png images
# containing graphical representations of the histogram and cumulative histogram
# of the input image.
#
# B. Bird - 03/10/2016

import sys

import png
import itertools

import numpy


def histograms(image_intensities):
	all_intensities = image_intensities.flatten() #Convert the 2d array into a single long array of pixel values
	hist = numpy.zeros(256)
	for i in all_intensities:
		hist[i] += 1
	cumulative_hist = numpy.zeros(256)
	cumulative_hist[0] = hist[0]
	for i in xrange(1,256):
		cumulative_hist[i] = cumulative_hist[i-1] + hist[i]
	#Normalize the histograms to 0-1
	hist /= hist.max()
	cumulative_hist /= cumulative_hist.max()
	return hist,cumulative_hist
	
	
def plot_histogram_array(output_filename, hist):
	hist_field = numpy.ndarray((256,100))
	hist_field[:,:] = 255
	for i in range(256):
		hist_field[i,0:hist[i]*100] = 0
	hist_field = hist_field[:,::-1]
	hist_image = numpy.ndarray((276,120))
	hist_image[:,:] = 255
	hist_image[10:266,9] = 0
	hist_image[10:266,110] = 0
	hist_image[9,10:110] = 0
	hist_image[266,10:110] = 0
	hist_image[10:266,10:110] = hist_field
	write_png_grayscale(output_filename, hist_image.T)

def write_png_grayscale(output_filename, pixels):
	with open(output_filename, 'wb') as f:
		w = png.Writer(pixels.shape[1], pixels.shape[0], greyscale=True)
		w.write(f, pixels)

def read_image_greyscale(filename):
	r = png.Reader(filename)
	image_data = r.asDirect()
	width,height = image_data[0], image_data[1]
	image_raw = numpy.vstack(itertools.imap(numpy.uint8, image_data[2]))
	if image_data[3]['greyscale']:
		image_bw = image_raw
	else:
		image_pixels = image_raw.reshape((height, width, 3))
		image_bw = numpy.array( image_pixels.mean(axis=2), dtype=numpy.uint8)
	return image_bw
	
if __name__ == '__main__':
	if len(sys.argv) < 2:
		print >>sys.stderr, "Usage: %s <input image>"
		sys.exit(0)
	input_filename = sys.argv[1]
	output_filename1 = input_filename.rsplit('.',1)[0] + '_histogram.png'
	output_filename2 = input_filename.rsplit('.',1)[0] + '_cumulative_histogram.png'
	
	image_intensities = read_image_greyscale(input_filename)
	
	histogram,cumulative_histogram = histograms(image_intensities)
	plot_histogram_array(output_filename1, histogram)
	plot_histogram_array(output_filename2, cumulative_histogram)