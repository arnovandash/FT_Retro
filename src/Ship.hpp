

#include <iostream>
#include "Sprite.hpp"

#ifndef SHIP_HPP
# define SHIP_HPP


class Ship : public Sprite
{
public:
	Ship(void);
	Ship(int x, int y);
	Ship(Ship const & src);

	~Ship();

	Ship const &	operator=(Ship const &);;
	bool	move( int );
	void	move( int const, int const);
	//char 	getCharacter();

};

#endif
