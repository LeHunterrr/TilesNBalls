#pragma once
#include "Vec2.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Colors.h"
#include "Ball.h"

class Pad {
public:
	Pad( const Vec2& vec1, float width, float height);
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd, float dt );
	bool IsCollidingWithWall( const RectF& walls );
	bool IsCOllidingWithBall( Ball& ball ) const;
private:
	static constexpr float speed = 200.0f;
	Color c = Colors::Blue;
	Vec2 pos;
	float height;
	float width;
};