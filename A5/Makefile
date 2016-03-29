all: morphological scaling non_linear_transform

morphological: morphological.cpp
	g++ -Wall morphological.cpp lodepng.cpp -o morphological

scaling: image_scaling.cpp
	g++ -Wall image_scaling.cpp lodepng.cpp -o scaling

non_linear_transform: non_linear_transform.cpp
	g++ -Wall non_linear_transform.cpp lodepng.cpp -o non_linear_transform

