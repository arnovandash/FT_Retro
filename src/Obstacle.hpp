

#include <iostream>
#include "Sprite.hpp"

#ifndef Obstacle_HPP
 #define Obstacle_HPP

class Obstacle : public Sprite {

public:
	Obstacle(void);
	Obstacle(int x, int y);
	Obstacle(Obstacle const & src);

	~Obstacle();
	
	Obstacle const &	operator=(Obstacle const &);
	bool	move( int );
};

#endif
