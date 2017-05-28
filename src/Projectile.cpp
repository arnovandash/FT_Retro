#include "Projectile.hpp"
#include "Ship.hpp"

Projectile::Projectile(void) : _fired(false){

	return ;
}

Projectile::~Projectile(void) {

	return ;
}

Projectile::Projectile(Ship const & src) {
	
	*this = src;
	this->_fired = true;
	return ;
}

