#include "RectF.h"

RectF::RectF( float _left, float _right, float _top, float _bottom ) :
	left( _left ),
	right( _right ),
	top( _top ),
	bottom( _bottom ) {}

RectF::RectF( const Vec2& topLeft, const Vec2& bottomRight ) :
	RectF( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y ) {}

RectF::RectF( const Vec2& topLeft, float width, float height ) :
	RectF( topLeft, { topLeft.x + width, topLeft.y + height } ) {}

bool RectF::isCollidingWithRect( const RectF & other ) const {
	return right > other.left && left < other.right
		&& top < bottom && bottom > other.top;
}
