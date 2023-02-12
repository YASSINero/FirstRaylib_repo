#include "Objects.h"

#define WINWID 1000
#define WINHEI 800

World* window = nullptr;

int main()
{
	//InitWindow(WINWID, WINHEI, "Ball");

	////==============image edit==================
	//Image ball_img = LoadImage("empty.png");
	//Image padd_img = LoadImage("empty.png");

	//ImageResize(&ball_img, 150, 150);
	//ImageResize(&padd_img, 20, 145);

	//for(int radius = 74; radius > 0; --radius)
	//{
	//	ImageDrawCircle(&ball_img, 75, 75, radius, WHITE);
	//}

	//ImageDrawRectangleV(&padd_img, { 0, 0 }, { 20, 145 }, WHITE);
	////ImageCrop(&padd_img, { 55, 0, 20, 145 });
	//	

//	Ball aBall{ LoadTextureFromImage(ball_img) };
	//Paddle lPaddle{ LoadTextureFromImage(padd_img) };
	//UnloadImage(ball_img);
	//	UnloadImage(padd_img);
	//const Texture2D ballText = aBall.getBallText();
	//	const Texture2D paddText = lPaddle.getPaddleText();
//	aBall.x = 0; lPaddle.x = 0;
//	aBall.y = WINHEI / 2.f - ballText.height / 2.f;
//	lPaddle.y = WINHEI / 2.f - paddText.height / 2.f;

	////============================================


	window = new World(WINWID, WINHEI, "ZA WARUDU");

	SetTargetFPS(60);

	auto& gameBall = window->addObject<Ball>(0.f, 0.f);

	window->initAll();
	
//	float p_speed = 150.f, b_speed = 150.f;

	while (!WindowShouldClose())
	{
		/*if (aBall.x > GetScreenWidth() - ballText.width)
		{
			aBall.x = GetScreenWidth() - ballText.width;
			b_speed *= -1;
		}
		if (aBall.x < 0)
		{
			aBall.x = 0;
			b_speed *= -1;
		}
			aBall.x += b_speed * GetFrameTime();
*/
		

		/*if (lPaddle.y > GetScreenHeight() - paddText.height)
		{
			lPaddle.y = GetScreenHeight() - paddText.height;
			p_speed *= -1;
		}
		if (lPaddle.y < 0)
		{
			lPaddle.y = 0;
			p_speed *= -1;
		}
			lPaddle.y += p_speed * GetFrameTime();*/

		
		window->updateAll();



		BeginDrawing();
			ClearBackground(BLACK);

		//DrawTexture(ballText, aBall.x, aBall.y, WHITE);
		//DrawTexture(paddText, lPaddle.x, lPaddle.y, MAROON);
			window->drawAll();

		EndDrawing();

	}

		//UnloadTexture(ballText);
		CloseWindow();

	return 0;
}