/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 12:38:09 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>

#include "Ship.hpp"
#include "Fighter.hpp"
#include "Destroyer.hpp"

int main(void)
{

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
//From tutorial////////
	int ch = 0; 
	int x = 10, y = 10;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;
//////////////////////


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


	std::cin.get();
	while (1) // Main Gameloop
	{
		ch = getch();
		switch (ch)
		{
			case KEY_UP:
				std::cout << ch << std::endl;
				endwin();
				return (0);
				break;
			case KEY_DOWN:
				std::cout << "Happy " << std::endl;
		}

		//Start of render code
		clear();
		mvprintw(y, x, "o");
		x++;

		refresh();
		usleep(20000);
		//end of renderer code

	}

	endwin();
	return (0);
}
