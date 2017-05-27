#include "Ship.hpp"

Ship::Ship(void) : _fireSpeed(0), _fireDamage(0), _hitPoints(0) {

	std::string name = "KIA";
	setName(name);
	
	return ;
}

Ship::Ship(std::string const name) : _fireSpeed(0), _fireDamage(0), _hitPoints(0) {

	setName(name);

	return ;
}

Ship::Ship(Ship const & src) {

	*this = src;
	return ;
}

Ship::~Ship(void) {

	return ;
}

void		Ship::setName(std::string const name) {

	this->_name = name;
	return ;
}

std::string		Ship::getName(void) const {

	return(this->_name);
}

Ship & Ship::operator=(Ship const & src) {

	std::cout << "Assigning " << src.getName() << "'s values to ship" << std::endl;

	_name = src.getName();
	_fireSpeed = src._fireSpeed;
	_fireDamage = src._fireDamage;
	_hitPoints = src._hitPoints;

	std::cout << "Done...." << std::endl;
	
	return *this;
}
