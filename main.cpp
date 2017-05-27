/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 12:33:19 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>
#include <ncurses.h>

#include "Ship.hpp"
#include "Fighter.hpp"
#include "Destroyer.hpp"

int main(void)
{
	std:: string	choice;
	std::string		name;
	

	std::cout << "Hey Bro, Welcome to our totally rad Game\n" << std::endl;
	std::cout << "Choose your Ship Type: Fighter or Destroyer" <<std::endl;
	std::cin >> choice;

	if (choice == "Fighter") {
		std::cout << "Enter a name for your radical fighter: " << std::endl;
		std::cin >> name;
		Fighter ship(name);
	}
	else if (choice == "Destroyer") {
		std::cout << "Enter a name for your awesome destroyer: " << std::endl;
		std::cin >> name;
		Destroyer ship(name);
	}


	return (0);
}
