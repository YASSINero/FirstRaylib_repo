#include "Objects.h"

void Ball::objInit()
{
	x = 0.f;
	y = 400 - circle_.height;

	Image ball_img = LoadImage("empty.png");
	ImageResize(&ball_img, 150, 150);
	for (int radius = 74; radius > 0; --radius)
	{
		ImageDrawCircle(&ball_img, 75, 75, radius, WHITE);
	}

	circle_ = LoadTextureFromImage(ball_img);
	UnloadImage(ball_img);
}

void Ball::objUpdate() 
{
	if (x > GetScreenWidth() - circle_.width)
	{
		x = GetScreenWidth() - circle_.width;
		x_speed *= -1;
	}
	if (x < 0)
	{
		x = 0;
		x_speed *= -1;
	}

	if (y > GetScreenHeight() - circle_.height)
	{
		y = GetScreenHeight() - circle_.height;
		y_speed *= -1;
	}
	if (y < 0)
	{
		y = 0;
		y_speed *= -1;
	}

	x += x_speed * GetFrameTime();
	y += y_speed * GetFrameTime();

}

void Ball::objDraw()
{
	DrawTexture(circle_, x, y, WHITE);
}

