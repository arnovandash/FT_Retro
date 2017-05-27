#ifndef FIGHTER_HPP
# define FIGHTER_HPP

#include "Ship.hpp"
#include <iostream>

class Fighter : public Ship {
    public:

        Fighter(void);
        Fighter(std::string const name);
        Fighter(Fighter const & src);
        ~Fighter(void);

        Fighter &	operator=(Fighter const &);
};

#endif
