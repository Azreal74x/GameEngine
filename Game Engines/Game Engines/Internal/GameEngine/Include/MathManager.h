#pragma once
#include <SDL.h>
#include <Singleton.h>

class MathManager : public Singleton<MathManager> {
	friend class Singleton<MathManager>;

public:
	MathManager();

	static int GenerateRandomRange(int min, int range);
	static int GenerateRandomRangeWithSeed(int min, int range, int seed);

	//everything below is still in progress
	struct Vec2 {
		float x, y;
		Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
	};

	//const?
	static Vec2 Plus(Vec2& left, Vec2& right);
	static Vec2 Minus(Vec2& left, Vec2& right);
	static Vec2 Multiply(Vec2& left, Vec2& right);

	float GetLength(const Vec2& vector2);

private:

};