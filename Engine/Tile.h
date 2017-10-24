#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Tile {
public:
	Tile() = default;
	Tile( const RectF& rekt, Color _c );
	void Draw( Graphics& gfx ) const;
	void DrawWithPadding( float pixels, Graphics& gfx ) const;
	bool isCollidingWithBall( Ball& ball );
	void CollideWithBall( Ball& ball );
	RectF& GetRect() { return rect; };
private:
	RectF rect;
	Color c;
	bool isDestroyed = false;
};