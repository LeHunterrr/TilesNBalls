#include "Pad.h"

Pad::Pad( const Vec2 & vec1, float _width, float _height ) :
	pos( vec1 ),
	height( _height ),
	width( _width ) {}

void Pad::Draw( Graphics & gfx ) const {
	gfx.DrawRect( int(pos.x), int(pos.y), int(width), int(height), c );
}

void Pad::Update( const Keyboard & kbd, float dt ) {
	if( kbd.KeyIsPressed( VK_LEFT ) ) {
		pos.x -= speed * dt;
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) ) {
		pos.x += speed * dt;
	}
}

bool Pad::IsCollidingWithWall( const RectF & walls ) {
	bool isColliding = false;

	if( pos.x < walls.left ) {
		pos.x = walls.left;
		isColliding = true;
	}
	if( pos.x + width >= walls.right ) {
		pos.x = walls.right - width;
		isColliding = true;
	}
	return isColliding;
}

bool Pad::IsCOllidingWithBall( Ball & ball ) const {
	bool isColliding = false;
	RectF rect( pos, width, height );
	if( rect.isCollidingWithRect( ball.GetRect() ) ) {
		isColliding = true;
		ball.ChangeY();
	}
	return isColliding;
}
