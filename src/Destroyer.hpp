#ifndef DESTROYER_HPP
# define DESTROYER_HPP

#include "Ship.hpp"
#include <iostream>

class Destroyer : public Ship {
	public:

		Destroyer(void);
		Destroyer(std::string const name);
		Destroyer(Destroyer const & src);
		~Destroyer(void);

		Destroyer &	operator=(Destroyer const &);
};

#endif