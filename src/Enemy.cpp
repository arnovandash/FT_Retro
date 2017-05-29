

#include "Enemy.hpp"
#include "Window.hpp"

Enemy::Enemy( void ) : Sprite() {
	_character = 'E';
}

Enemy::Enemy(int x, int y) : Sprite(x, y) {
	_character = 'E';
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
	int x = rand();

	if (timeFrameCount % 13 == 0){
		if (_y <= 32 && _y > 6){
			if (x % 3 == 0)
				_y++;
			else if (x % 2 == 0)
				_y--;
		}
	}
	return TRUE;
}
