

#include <iostream>
#include "Sprite.hpp"

#ifndef Projectile_HPP
 #define Projectile_HPP

class Projectile : public Sprite {

public:
	Projectile(void);
	Projectile(int x, int y);
	Projectile(Projectile const & src);

	~Projectile();
	
	Projectile const &	operator=(Projectile const &);

	bool 	impact(Sprite const & target);
	bool	move( int );
};

#endif
