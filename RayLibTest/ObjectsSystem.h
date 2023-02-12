#pragma once

#include <memory>
#include <vector>
#include<raylib.h>

class Ball;
class Paddle;
class World;

class GameObjects
{
public:
	virtual void objInit() {}
	virtual void objUpdate() {}
	virtual void objDraw() {}

	virtual ~GameObjects() = default;
};

class World
{
	std::vector<std::unique_ptr<GameObjects>> objs;


public:

	World(int w, int h, const char* title)
	{
		InitWindow(w, h, title);
		initAll();
		//call functions requiring glcontext
	}

	void initAll() const
	{
		for (const auto& intiti : objs)
		{
			intiti->objInit();
		}
	}
	void updateAll() const
	{
		for (const auto& intiti : objs)
		{
			intiti->objUpdate();
		}
	}
	void drawAll() const
	{
		for (const auto& intiti : objs)
		{
			intiti->objDraw();
		}
	}

	template <typename T, typename... TArgs>
	T& addObject(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		std::unique_ptr<GameObjects> uPtr{ c };
		objs.emplace_back(std::move(uPtr));

		//c->objInit();

		return *c;
	}


};

