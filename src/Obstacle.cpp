

#include "Obstacle.hpp"
#include "Window.hpp"

Obstacle::Obstacle( void ) : Sprite() {
	_character = '0';
}

Obstacle::Obstacle(int x, int y) : Sprite(x, y) {
	_character = '0';
}

Obstacle::Obstacle(Obstacle const & src) : Sprite(src.getX(), src.getY()) {
}

Obstacle::~Obstacle( void ) {
}

bool 	Obstacle::move( int timeFrameCount) {
	if (_x < 7)
			return FALSE;
	if (timeFrameCount % 1 == 0){
		_x--;
	} 
	return TRUE;
}
