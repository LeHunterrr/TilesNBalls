#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class Ball {
public:
	Ball( const Vec2& position, const Vec2& movement, Color color );
	void Update( float dt );
	void Draw( Graphics& gfx ) const;
	void ChangeX();
	void ChangeY();
	void SetVelocity( Vec2 velocity );
	int IsCollidingWithWall(const RectF& walls);
	RectF GetRect();
	Vec2 GetVelocity() const;
private:
	Vec2 pos;
	Vec2 move;
	float speed = 400;
	Color c;
	static constexpr float radius = 7.0f;

};