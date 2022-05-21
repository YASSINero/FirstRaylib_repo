#include <iostream>
#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

using std::cout;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;

const int paddles_WIDTH = 10, paddles_HEIGHT = 100;

int getVerticleRectCenter(const int *rectH, const int *screenH)
{
	return (*screenH) / 2 - (*rectH) / 2;
}

int getHorizontalRectCenter(const int* rectW, const int* screenW)
{
	return (*screenW) / 2 - (*rectW) / 2;
}



int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, WHITE);
		DrawRectangle(10, getVerticleRectCenter(&paddles_HEIGHT, &SCREEN_HEIGHT), paddles_WIDTH, paddles_HEIGHT, BROWN);
		DrawRectangle(SCREEN_WIDTH - 20, getVerticleRectCenter(&paddles_HEIGHT, &SCREEN_HEIGHT), paddles_WIDTH, paddles_HEIGHT, BROWN);
		

		DrawFPS(5, 5);
		
		EndDrawing();
	}



	CloseWindow();
	return 0;
}