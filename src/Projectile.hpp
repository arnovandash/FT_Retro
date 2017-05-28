#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "Ship.hpp"
#include "Fighter.hpp"

class Projectile : public Fighter {

	public:

		Projectile(void);
		~Projectile(void);
		Projectile(Ship const & src);

		int 	_posX;
		int		_posY;
		bool	_fired;
};
	
#endif
