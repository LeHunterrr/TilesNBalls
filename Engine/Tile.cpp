#include "Tile.h"
#include <assert.h>

Tile::Tile( const RectF & rekt, Color _c ) :
	rect( rekt ),
	c( _c ) {}

void Tile::Draw( Graphics & gfx ) const {
	if( !isDestroyed ) {
		gfx.DrawRect( rect, c );
	}
}

void Tile::DrawWithPadding( float pixels, Graphics & gfx ) const {
	if( !isDestroyed ) {
		gfx.DrawRect( RectF(rect.left + pixels, rect.right - pixels, rect.top + pixels, rect.bottom - pixels), c );
	}
}

bool Tile::isCollidingWithBall( Ball & ball ) {
	return !isDestroyed && ball.GetRect().isCollidingWithRect( GetRect() );
}

void Tile::CollideWithBall( Ball & ball ) {
	assert( !isDestroyed && ball.GetRect().isCollidingWithRect( GetRect() ) );
	
	Vec2 center = ball.GetRect().GetCenter();
	if( center.x <= rect.left || center.x >= rect.right ) {
		ball.ChangeX();
	} else {
		ball.ChangeY();
	}
	isDestroyed = true;
}

