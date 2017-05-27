/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 13:04:15 by arnovan-         ###   ########.fr       */
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

void shipInit() {

	std:: string	choice;
	std::string		name;
	

	std::cout << "Hey Bro, Welcome to our totally rad Game\n" << std::endl;
	std::cout << "Choose your Ship Type: (1)Fighter or (2)Destroyer" <<std::endl;
	std::cin >> choice;

	if (choice == "Fighter" || choice == "1") {
		std::cout << "Enter a name for your radical fighter: " << std::endl;
		std::cin >> name;
		if (name == " ")
			name = "Deathbringer";
		Fighter ship(name);
	}
	else if (choice == "Destroyer" || choice == "2") {
		std::cout << "Enter a name for your awesome destroyer: " << std::endl;
		std::cin >> name;
		Destroyer ship(name);
	}
}

int main(void)
{
	shipInit();
	
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

	

	std::cin.get();
	while (1) // Main Gameloop
	{
		ch = getch();
		switch (ch)
		{
			case 'q':
				endwin();
				return (0);
				break;
			case KEY_UP: y--; break;
			case KEY_DOWN: y++; break;
			case KEY_LEFT: x--; break;
			case KEY_RIGHT: x++; break;
		}

		//Start of render code
		clear();
		mvprintw(y, x, "o");

		refresh();
		usleep(20000);
		//end of renderer code

	}

	endwin();
	return (0);
}
