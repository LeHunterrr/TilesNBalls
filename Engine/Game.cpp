/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "FrameTimer.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	b( { 100.0f, 400.0f }, { 200.0f, 200.0f }, Colors::Green ),
	border( 0, Graphics::ScreenWidth, 0, Graphics::ScreenHeight ),
	soundPad( L"Sounds\\arkpad.wav", false ),
	soundTile( L"Sounds\\arkbrick.wav", false ),
	p( { 100.0f, 550.0f }, 100.0f, 25.0f ) {

	Vec2 start = { 40.0f, 50.0f };
	Color c[ numTilesHeight ] = { Colors::Cyan, Colors::Gray, Colors::LightGray, Colors::Yellow, Colors::Red };
	for( int y = 0; y < numTilesHeight; y++ ) {
		Color tileColor = c[ y ];
		for( int x = 0; x < numTilesWidth; x++ ) {
			tiles[ y * numTilesWidth + x ] = Tile( RectF( {start.x + tilesWidth * x, start.y + tilesHeight * y}, tilesWidth, tilesHeight ), tileColor );
		}
	}
}

void Game::Go() {
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	float dt = timer.Mark();
	b.Update( dt );
	p.Update( wnd.kbd, dt );

	p.IsCollidingWithWall( border );
	if( p.IsCOllidingWithBall( b ) ) {
		soundPad.Play();
	}

	float closestDistance = 100.0f;
	int index = -1;

	for( int i = 0; i < numTiles; i++ ) {
		Tile& t = tiles[ i ];
		if( t.isCollidingWithBall( b ) ) {
			const float distance = (t.GetRect().GetCenter() - b.GetRect().GetCenter()).GetLengthSq();
			if( distance < closestDistance || index == -1) {
				closestDistance = distance;
				index = i;
			}
		}
	}
	if( index != -1 ) {
		soundTile.Play();
		tiles[ index ].CollideWithBall( b );
	}

	if( b.IsCollidingWithWall( border ) ) {
		
	}
}

void Game::ComposeFrame() {
	
	b.Draw( gfx );
	p.Draw( gfx );
	for( const Tile& t : tiles ) {
		t.DrawWithPadding(2, gfx);
	}
}
