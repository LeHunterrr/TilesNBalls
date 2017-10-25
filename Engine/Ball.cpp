#include "Ball.h"

Ball::Ball( const Vec2 & position, const Vec2 & movement, Color color ) :
	pos( position ),
	c( color ) {
	SetVelocity( movement );
}

void Ball::Update( float dt ) {
	pos += move * dt;
}

void Ball::Draw( Graphics & gfx ) const {
	gfx.DrawCircle(pos.x, pos.y, radius, c);
}

int Ball::IsCollidingWithWall( const RectF & walls ) {
	int result = 0;

	if( pos.x - radius < walls.left ) {
		ChangeX();
		pos.x = walls.left + radius; 
		result = 1;
	}
	if( pos.x + radius >= walls.right ) {
		ChangeX();
		pos.x = walls.right - radius;
		result = 1;
	}
	if( pos.y - radius < walls.top ) {
		ChangeY();
		result = 1;
		pos.y = walls.top + radius;
	}
	if( pos.y + radius >= walls.bottom ) {
		ChangeY();
		result = 2;
		pos.y = walls.bottom - radius;
	}
	return result;
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

void Ball::SetVelocity( Vec2 velocity ) {
	move = velocity.Normalize() * speed;
}

Vec2 Ball::GetVelocity() const {
	return move;
}
