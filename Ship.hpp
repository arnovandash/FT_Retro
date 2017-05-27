#ifndef SHIP_HPP
# define SHIP_HPP

# include <iostream>

class Ship {

	public:
		Ship(void);
		Ship(std::string const name);
		Ship(Ship const & src);
		~Ship(void);

		Ship &	operator=(Ship const &);
		
		void			setName(std:: string const name);
		std::string		getName(void) const;
		std::string		_name;

	//protected:

		int				_fireSpeed;
		int				_fireDamage;
		int				_hitPoints;
		int 			_maxX;
		int				_shipX;
		int				_maxY;
		int				_shipY;
		std::string		_type;
};

#endif
