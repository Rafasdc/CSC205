/*
 * line.h
 *
 *  Created on: Feb 20, 2016
 *      Author: rafa
 */

#ifndef LINE_H_
#define LINE_H_

#endif /* LINE_H_ */

class Line{
public:
	Line(int x1_in, int y1_in,int x2_in, int y2_in, int r_in, int g_in, int b_in, int a_in){
		x1 = x1_in;
		x2 = x2_in;
		y1 = y1_in;
		y2 = y2_in;
		r = r_in;
		g = g_in;
		b = b_in;
		a = a_in;
	}

	void draw(SDL_Renderer* renderer){
		lineRGBA(renderer, x1,y1,x2,y2,r,g,b,a);
	}

	int x1,x2,y1,y2,r,g,b,a;

};




