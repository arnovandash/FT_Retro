

#include "Sprite.hpp"
#include <ncurses.h>
#include <iostream>

Sprite::Sprite( void ) : _x(10), _y(15), _character(' ') {
}

Sprite::Sprite(int x, int y) : _x(x), _y(y),  _character(' ') {
}

Sprite::Sprite(Sprite const & src) : _x(src._x), _y(src._y), _character(src._character) {
}

Sprite::~Sprite( void ) {
}

Sprite const &	Sprite::operator=(Sprite const & rhs) {
	if (this != &rhs) {
		_character = rhs._character;
		_x = rhs._x;
		_y = rhs._y;
	}
	return *this;
}

int		Sprite::getX( void ) const {
	return this->_x;
}

int		Sprite::getY( void ) const {
	return this->_y;
}

void	Sprite::toPrint() {
	char	character[2] = {_character, 0};
	mvprintw(this->_y, this->_x, character);
}
