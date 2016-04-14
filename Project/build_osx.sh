LIB_DIR=./lib_osx
g++ -o bricks main.cpp -framework SDL2 -I. -L${LIB_DIR} -lSDL2_gfx 
