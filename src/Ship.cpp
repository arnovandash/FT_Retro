

#include "Ship.hpp"
#include "Window.hpp"
#include <ncurses.h>

Ship::Ship( void ) : Sprite(){
	_character = '>';
}

Ship::Ship(int x, int y) : Sprite(x, y){
	_character = '>';
}

Ship::Ship(Ship const & src) : Sprite(src.getX(), src.getY()){
}


Ship::~Ship( void ) {
}

bool 	Ship::move( int timeFrameCount) {
	if (timeFrameCount == 0)
		return 1;
	return 0;
}

void 	Ship::move( int const keyPress, int timeFrameCount) {
	if (timeFrameCount){
		if (keyPress == KEY_UP && _y > (SHIPY + 1))
			_y--;
		else if (keyPress == KEY_DOWN && _y < (SHIPY + WINHEIGHT - 2))
			_y++;
	}
}