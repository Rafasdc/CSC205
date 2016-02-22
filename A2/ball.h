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

		ball_direction.x = cos(ball_direction_x_in*(M_PI/180.0)); //in is in degrees
		ball_direction.y = sin(ball_direction_y_in*(M_PI/180.0));//in is in degrees
		radius = radius_in;
		velocity = velocity_in;
		r = r_in;
		g = g_in;
		b = b_in;
		a = a_in;
		start = false;
		hit_bottom = false;
		hit = false;
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
			hit_bottom = true;
		}
			if (start){
				ball_position = new_position;
			}
	}

	void draw(SDL_Renderer* renderer, float frame_delta_seconds, int CANVAS_SIZE_X, int CANVAS_SIZE_Y ){
		filledCircleRGBA(renderer,ball_position.x,ball_position.y,radius,r,g,b,a);
	}


	void ball_rectangle_col(Box* box){
		if (box->hit == false){
		if (ball_position.x <= box->x1+radius && new_position.x >= box->x1-radius ){
			if (new_position.y >= box->y1 - radius && new_position.y <= box->y2 + radius){
				ball_direction.x = -ball_direction.x;
				new_position.x = box->x1-radius-1;
				printf("left edge\n");
				box->setHit();
			}
		} else if (ball_position.x >= box->x2-radius && new_position.x <= box->x2+radius){

			if (new_position.y >= box->y1 - radius && new_position.y <= box->y2 + radius){
				printf("right edge\n");
				ball_direction.x = -ball_direction.x;
				new_position.x = box->x2+radius+1;
				box->setHit();

			}
		} else if (ball_position.y >= box->y2 - radius && new_position.y <= box->y2+radius){

			if ((new_position.x >= box->x1 - radius  && new_position.x <= box->x2 + radius)) {
				printf("bottom\n");
				ball_direction.y = -ball_direction.y;
				new_position.y = box->y2+radius+1;
				box->setHit();
			}
		} else if (ball_position.y <= box->y1 + radius && new_position.y >= box->y1-radius){

			if ((new_position.x >= box->x1 - radius  && new_position.x <= box->x2 + radius)) {
				printf("top\n");
				ball_direction.y = -ball_direction.y;
				new_position.y = box->y1-radius-1;
				box->setHit();
			}
		}
		if(start){
			ball_position = new_position;
		}
		}
	}

	void ball_ball_col(Ball ball){
		Vector2d R = ball_position - ball.ball_position;
		int R_distance = sqrt(R.x*R.x + R.y*R.y);
		Vector2d n = R/R_distance;
		if(R_distance < radius + ball.radius){
			ball_direction = ball.ball_direction;
			ball.ball_direction = ball_direction;
			ball_position = ball_position + ball_direction;
			ball.ball_position = ball.ball_position + ball.ball_direction;
			//printf("ball velocity is %d\n", ball->velocity);

			/*
			ball_direction.x = (2*ball->r*ball->velocity)/(radius+ball->radius);
			ball_direction.y = (2*ball->r*ball->velocity)/(radius+ball->radius);
			*/

		}
	}

	void set_direction(int x, int y){
		ball_direction.x = cos(x*(M_PI/180.0)); //in is in degrees
		ball_direction.y = sin(y*(M_PI/180.0));//in is in degrees
	}

	Vector2d get_position(){
		return ball_position;
	}

	Vector2d get_direction(){
		return ball_direction;
	}



	Vector2d ball_position, ball_direction, new_position;
	int radius, velocity,r,g,b,a;
	bool start, hit_bottom, hit;
};
