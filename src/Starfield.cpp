#include "Starfield.hpp"
#include "Window.hpp"

Starfield::Starfield( void ) : Sprite() {
	_character = '.';
}

Starfield::Starfield(int x, int y) : Sprite(x, y) {
	_character = '.';
}

Starfield::Starfield(Starfield const & src) : Sprite(src.getX(), src.getY()) {
}

Starfield::~Starfield( void ) {
}

bool 	Starfield::move( int timeFrameCount) {
	if (_x < 7)
			return false;
	if (timeFrameCount % 10 == 0){
		_x--;
	} 
	return true;
}
