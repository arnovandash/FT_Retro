

#include <ncurses.h>

#ifndef SPRITE_HPP
# define SPRITE_HPP


class Sprite {
public:
	Sprite(void);
	Sprite(int x, int y);
	Sprite(Sprite const & src);
	virtual ~Sprite();
	
	Sprite const &	operator=(Sprite const & rdh);
	virtual bool	move( int ) = 0;
	bool 	impact(Sprite*&);

	virtual void toPrint();
	int		getX( void ) const ;
	int		getY( void ) const ;


	int _x;
	int _y;
	char _character;
};

#endif
