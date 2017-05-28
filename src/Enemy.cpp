

#include "Enemy.hpp"
#include "Window.hpp"

Enemy::Enemy( void ) : Sprite() {
	_character = '<';
}

Enemy::Enemy(int x, int y) : Sprite(x, y) {
	_character = '<';
}

Enemy::Enemy(Enemy const & src) : Sprite(src.getX(), src.getY()) {
}

Enemy::~Enemy( void ) {
}

bool 	Enemy::move( int timeFrameCount) {
	if (_x < 8)
			return FALSE;
	if (timeFrameCount % 4 == 0){
		_x--;
	} 
	return TRUE;
}
