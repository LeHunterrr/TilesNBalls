#include "Paddle.h"

Paddle::Paddle( const Vec2 & pos_in,float halfWidth_in,float halfHeight_in )
	:
	pos( pos_in ),
	halfWidth( halfWidth_in ),
	halfHeight( halfHeight_in )
{
}

void Paddle::Draw( Graphics & gfx ) const
{
	RectF rect = GetRect();
	gfx.DrawRect( rect,wingColor );
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect( rect,color );
}

bool Paddle::DoBallCollision( Ball & ball )
{
	RectF rect = GetRect();
	if( !isCooldown && rect.IsOverlappingWith( ball.GetRect() ) ) {
		const Vec2 center = ball.GetRect().GetCenter();
		Vec2 distanceCenterToBall = center - rect.GetCenter();
		if( std::signbit( ball.GetVelocity().x ) == signbit( distanceCenterToBall.x ) ||
			center.x >= rect.left && center.x <= rect.right ) {
			ball.SetDirection( { distanceCenterToBall.x, -30 } );
		} else {
			ball.ReboundX();
		}
		isCooldown = true;
		return true;
	}
	return false;
}

void Paddle::DoWallCollision( const RectF & walls )
{
	const RectF rect = GetRect();
	if( rect.left < walls.left )
	{
		pos.x += walls.left - rect.left;
	}
	else if( rect.right > walls.right )
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Update( const Keyboard & kbd,float dt )
{
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		pos.x -= speed * dt;
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter( pos,halfWidth,halfHeight );
}

void Paddle::ResetCooldown()
{
	isCooldown = false;
}
