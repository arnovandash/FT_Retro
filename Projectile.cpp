#include "Projectile.hpp"
#include "Ship.hpp"

Projectile::Projectile(void) {

	return ;
}

Projectile::~Projectile(void) {

	return ;
}

Projectile::Projectile(Ship const & src) {

	*this = src;
	return ;
}

