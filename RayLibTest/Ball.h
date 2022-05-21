#ifndef BALL_H
#define BALL_H

#include<raylib.h>

class Ball
{
	float x, y, speedX, speedY, ray;


public:

	Ball(float ball_x, float ball_y, float speed_x, float speed_y, int ball_r) : 
		x(ball_x), y(ball_y), speedX(speed_x), speedY(speed_y), ray(ball_r)
	{
		
	}

};


#endif /*HEADER_H*/
