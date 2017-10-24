#include "Tile.h"


Tile::Tile( const RectF & rekt, Color _c ) :
rect(rekt),
c(_c){}

void Tile::Draw( Graphics & gfx ) const {
	if( !isDestroyed ) {
		gfx.DrawRect( rect, c );
	}
}

bool Tile::isCollidingWithBall( Ball & ball ) {
	if( !isDestroyed && ball.GetRect().isCollidingWithRect( GetRect() ) ) {
		ball.ChangeY();
		isDestroyed = true;
		return true;
	} 
	return false;
}
