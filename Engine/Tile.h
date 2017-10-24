#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Tile {
public:
	Tile() = default;
	Tile( const RectF& rekt, Color _c );
	void Draw( Graphics& gfx ) const;
private:
	RectF rect;
	Color c;
};