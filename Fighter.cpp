#include "Fighter.hpp"

Fighter::Fighter(void) {

	std::string name = "Chery";
	setName(name);

    _fireDamage = 5;
    _fireSpeed = 20;
    _hitPoints = 5;
	_type = 'F';
	
	std::cout << "Fighter " << _name << " constructed" << std::endl;;
	return ;
}

Fighter::Fighter(std::string const name) {

	setName(name);

    _fireDamage = 5;
    _fireSpeed = 20;
    _hitPoints = 5;

	std::cout << "Fighter " << _name << " contructed" << std::endl;
	return ;
}

Fighter::Fighter(Fighter const & src) {

	std::cout << "Fighter cloned" << std::endl;
	*this = src;
	return ;
}

Fighter::~Fighter(void) {

	std::cout << "Fighter " << _name << " decommissoned" << std::endl;
	return ;
}

Fighter & Fighter::operator=(Fighter const & src) {

	std::cout << "Assigning " << src.getName() << "'s values to Fighter" << std::endl;

	_name = src.getName();
	_fireSpeed = src._fireSpeed;
	_fireDamage = src._fireDamage;
	_hitPoints = src._hitPoints;

	std::cout << "Done...." << std::endl;
	
	return *this;
}