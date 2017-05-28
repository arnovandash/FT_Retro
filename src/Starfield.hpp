

#include <iostream>
#include "Sprite.hpp"

#ifndef Starfield_HPP
 #define Starfield_HPP

class Starfield : public Sprite {

public:
	Starfield(void);
	Starfield(int x, int y);
	Starfield(Starfield const & src);

	~Starfield();
	
	Starfield const &	operator=(Starfield const &);
	bool	move( int );
};

#endif
