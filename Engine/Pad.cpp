#include "Pad.h"

Pad::Pad( const Vec2 & vec1, float _width, float _height ) :
	pos( vec1 ),
	height( _height ),
	width( _width ) {}

void Pad::Draw( Graphics & gfx ) const {
	gfx.DrawRect( RectF( pos, width, height ), secondary );
	gfx.DrawRect( RectF( {pos.x + secondaryPixels, pos.y}, width - secondaryPixels * 2, height ), c );
}

void Pad::Update( const Keyboard & kbd, float dt ) {
	if( kbd.KeyIsPressed( VK_LEFT ) ) {
		pos.x -= speed * dt;
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) ) {
		pos.x += speed * dt;
	}
}

void Pad::ResetCooldown() {
	Cooldown = false;
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

bool Pad::IsCOllidingWithBall( Ball & ball ) {
	RectF rect(pos, width, height);
	if(!Cooldown && rect.isCollidingWithRect( ball.GetRect() ) ) {
		const Vec2 center = ball.GetRect().GetCenter();
		Vec2 distanceCenterToBall = center - rect.GetCenter();
		if( std::signbit( ball.GetVelocity().x ) == signbit( distanceCenterToBall.x ) ||
			center.x >= rect.left && center.x <= rect.right ) {
			ball.SetVelocity( { distanceCenterToBall.x, -40 } );
		} else {
			ball.ChangeX();
		}
		Cooldown = true;
		return true;
	}
	return false;
}
