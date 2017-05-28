

#include <iostream>
#include "Sprite.hpp"

#ifndef Enemy_HPP
 #define Enemy_HPP

class Enemy : public Sprite {

public:
	Enemy(void);
	Enemy(int x, int y);
	Enemy(Enemy const & src);

	~Enemy();
	
	Enemy const &	operator=(Enemy const &);

	bool 	impact(Sprite const & target);
	bool	move( int );
};

#endif
