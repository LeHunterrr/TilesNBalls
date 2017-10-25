#pragma once
#include "Vec2.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Colors.h"
#include "Ball.h"
#include "RectF.h"

class Pad {
public:
	Pad( const Vec2& vec1, float width, float height);
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd, float dt );
	void ResetCooldown();
	bool IsCollidingWithWall( const RectF& walls );
	bool IsCOllidingWithBall( Ball& ball );
private:
	static constexpr float speed = 300.0f;
	static constexpr int secondaryPixels = 20;
	Color c = Colors::Blue;
	Color secondary = Colors::Red;
	Vec2 pos;
	float height;
	float width;
	RectF rect;
	bool Cooldown = false;
};