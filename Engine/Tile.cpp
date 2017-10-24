#include "Tile.h"


Tile::Tile( const RectF & rekt, Color _c ) :
rect(rekt),
c(_c){}

void Tile::Draw( Graphics & gfx ) const {
	gfx.DrawRect( rect, c );
}
