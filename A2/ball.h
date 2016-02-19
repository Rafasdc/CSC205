/*
 * ball.h
 *
 *  Created on: Feb 13, 2016
 *      Author: rafa
 */

#ifndef BALL_H_
#define BALL_H_





#endif /* BALL_H_ */


class Ball{
public:
	Ball(float ball_position_x_in,float ball_position_y_in,float ball_direction_x_in, float ball_direction_y_in, int radius_in, int velocity_in,int r_in, int g_in, int b_in, int a_in){
		//renderer = renderer_in;
		ball_position.x = ball_position_x_in;
		ball_position.y = ball_position_y_in;
		//new_position = new_position_in;
		ball_direction.x = ball_direction_x_in;
		ball_direction.y = ball_direction_y_in;
		radius = radius_in;
		velocity = velocity_in;
		r = r_in;
		g = g_in;
		b = b_in;
		a = a_in;
	}



	void move(SDL_Renderer* renderer, float frame_delta_ms, int CANVAS_SIZE_X, int CANVAS_SIZE_Y){
		float frame_delta_seconds = frame_delta_ms/1000.0;
		float position_delta = frame_delta_seconds*velocity;
		new_position = ball_position + position_delta*ball_direction;


	}

	void screen_collission(int CANVAS_SIZE_X, int CANVAS_SIZE_Y){
		//The ball collides with the edge of the screen if the new position is less than radius
		//pixels away from any edge.

		if (new_position.x <= radius){
			//Collide with left edge
			//Determine how far past the collision point the new position is.
			float offset_x = radius-new_position.x;
			//Mirror the direction around the y axis (since the ball bounces)
			ball_direction.x = -ball_direction.x;
			new_position.x += 2*offset_x;
		}else if(new_position.x >= CANVAS_SIZE_X - radius){
			//Collide with right edge
			//Determine how far past the collision point the new position is.
			float offset_x = new_position.x - (CANVAS_SIZE_X-radius);
			//Mirror the direction around the y axis (since the ball bounces)
			ball_direction.x = -ball_direction.x;
			new_position.x -= 2*offset_x;
		}else if(new_position.y <= radius){
			//Collide with top
			//Determine how far past the collision point the new position is.
			float offset_y = radius-new_position.y;
			//Mirror the direction around the x axis (since the ball bounces)
			ball_direction.y = -ball_direction.y;
			new_position.y += 2*offset_y;
		}else if(new_position.y >= CANVAS_SIZE_Y - radius){
			//Collide with bottom
			//Determine how far past the collision point the new position is.
			float offset_y = new_position.y - (CANVAS_SIZE_Y-radius);
			//Mirror the direction around the x axis (since the ball bounces)
			ball_direction.y = -ball_direction.y;
			new_position.y -= 2*offset_y;
		}
			ball_position = new_position;
	}

	void draw(SDL_Renderer* renderer, float frame_delta_seconds, int CANVAS_SIZE_X, int CANVAS_SIZE_Y ){
		filledCircleRGBA(renderer,ball_position.x,ball_position.y,radius,r,g,b,a);
	}


	void ball_rectangle_col(int x1, int x2, int y1, int y2){

		if (ball_position.x <= x1+radius && new_position.x >= x1-radius ){
			if (new_position.y >= y1 - radius && new_position.y <= y2 + radius){
				ball_direction.x = -ball_direction.x;
				printf("left edge\n");
				//hit = true;
			}
		} else if (ball_position.x >= x2-radius && new_position.x <= x2+radius){

			if (new_position.y >= y1 - radius && new_position.y <= y2 + radius){
				printf("right edge\n");
				ball_direction.x = -ball_direction.x;
				//hit = true;
			}
		} else if (ball_position.y >= y2 - radius && new_position.y <= y2+radius){
			if ((new_position.x >= x1 - radius  && new_position.x <= x2 + radius)) {
				printf("bottom\n");
				ball_direction.y = -ball_direction.y;
				//hit = true;
			}
		} else if (ball_position.y <= y1 + radius && new_position.y >= y1-radius){
			if ((new_position.x >= x1 - radius  && new_position.x <= x2 + radius)) {
				printf("top\n");
				ball_direction.y = -ball_direction.y;
				//hit = true;
			}
		}
		//return hit;
	}



	Vector2d ball_position, ball_direction, new_position;
	int radius, velocity,r,g,b,a;
};
