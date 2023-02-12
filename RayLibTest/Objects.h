#pragma once


#include "ObjectsSystem.h"



class Ball : public GameObjects 
{
	Texture2D circle_{};
	float x_speed = 150.f, y_speed = 150.f;
	float x{}, y{};

public:
	void objInit() override;

	void objUpdate() override;

	void objDraw() override;


public:
	Ball() = default;

	Ball(float ball_x, float ball_y) : x(ball_x), y(ball_y) {}

	explicit Ball(const Texture2D& srcTex) : circle_(srcTex), x(0.f), y(0.f) {}

	const Texture2D& getBallText() const { return circle_; }

};

class Paddle : GameObjects //todo override inherited funcs
{
	Texture2D rectangle_;

public:
	Paddle(float paddle_x=0, float paddle_y=0, const char* paddle_imgPath = "empty.png")
	: rectangle_(LoadTextureFromImage(LoadImage(paddle_imgPath))), x(paddle_x), y(paddle_y)
	{}

	explicit Paddle(const Texture2D& srcTex) : rectangle_(srcTex), x(0.f), y(0.f) {}

public:
	const Texture2D& getPaddleText() const
	{
		return rectangle_;
	}


public:
	float x, y;
};

