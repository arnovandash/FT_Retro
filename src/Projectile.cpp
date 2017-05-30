

#include "Projectile.hpp"
#include "Window.hpp"

Projectile::Projectile( void ) : Sprite() {
	_character = '~';
}

Projectile::Projectile(int x, int y) : Sprite(x, y) {
	_character = '~';
}

Projectile::Projectile(Projectile const & src) : Sprite(src.getX(), src.getY()) {
}

Projectile::~Projectile( void ) {
}

bool 	Projectile::move( int timeFrameCount) {
	if (_x > WINWIDTH + SHIPX - 3)
			return FALSE;
	if (timeFrameCount % 1 ==0){
	_x++;
	}
	return TRUE;
}
