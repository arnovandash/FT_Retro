#include "Destroyer.hpp"

Destroyer::Destroyer(void) {

	std::string name = "Geely";
	setName(name);

    _fireDamage = 25;
    _fireSpeed = 5;
    _hitPoints = 20;
	
	std::cout << "Destroyer " << _name << " constructed" << std::endl;;
	return ;
}

Destroyer::Destroyer(std::string const name) {

	setName(name);

    _fireDamage = 25;
    _fireSpeed = 5;
    _hitPoints = 20;

	std::cout << "Destroyer " << _name << " contructed" << std::endl;
	return ;
}

Destroyer::Destroyer(Destroyer const & src) {

	std::cout << "Destroyer cloned" << std::endl;
	*this = src;
	return ;
}

Destroyer::~Destroyer(void) {

	std::cout << "Destroyer " << _name << " decommissoned" << std::endl;
	return ;
}

Destroyer & Destroyer::operator=(Destroyer const & src) {

	std::cout << "Assigning " << src.getName() << "'s values to Destroyer" << std::endl;

	_name = src.getName();
	_fireSpeed = src._fireSpeed;
	_fireDamage = src._fireDamage;
	_hitPoints = src._hitPoints;

	std::cout << "Done...." << std::endl;
	
	return *this;
}