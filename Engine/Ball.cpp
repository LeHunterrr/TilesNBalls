#include "Ball.h"

Ball::Ball( const Vec2 & position, const Vec2 & movement, Color color ) :
	pos( position ),
	move( movement ),
	c( color ) {}

void Ball::Update( float dt ) {
	pos += move * dt;
}

void Ball::Draw( Graphics & gfx ) const {
	gfx.DrawCircle(pos.x, pos.y, radius, c);
}

bool Ball::IsCollidingWithWall( const RectF & walls ) {
	bool isColliding = false;

	if( pos.x - radius < walls.left ) {
		ChangeX();
		pos.x = walls.left + radius; 
		isColliding = true;
	}
	if( pos.x + radius >= walls.right ) {
		ChangeX();
		pos.x = walls.right - radius;
		isColliding = true;
	}
	if( pos.y - radius < walls.top ) {
		ChangeY();
		isColliding = true;
		pos.y = walls.top + radius;
	}
	if( pos.y + radius >= walls.bottom ) {
		ChangeY();
		isColliding = true;
		pos.y = walls.bottom - radius;
	}
	return isColliding;
}

RectF Ball::GetRect() {
	return RectF( { pos.x - radius, pos.y - radius }, {pos.x + radius, pos.y + radius} );
}

void Ball::ChangeX() {
	move.x *= -1;
}

void Ball::ChangeY() {
	move.y *= -1;
}
