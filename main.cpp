/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 13:28:56 by arnovan-         ###   ########.fr       */
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
/*
void shipInit() {

	std::string		choice;
	std::string		name;
	int ch = ;

	clear();
	mvprintw(0, 0, "Choose your Ship Type: (1)Fighter or (2)Destroyer");

	refresh();
	if (ch != 1)
	{
		ch = getch();
		switch (ch)
		{
			case '1':
				clear();
				mvprintw(0, 0, "selected 1");
				break;
			case '2':
				clear();
				mvprintw(0, 0, "selected 2");
				break;
		}
	}
	*/
	/*	

		std::cout << "Hey Bro, Welcome to our totally rad Game\n" << std::endl;
		std::cout << "Choose your Ship Type: (1)Fighter or (2)Destroyer" <<std::endl;
		std::cin >> choice;

		if (choice == "Fighter" || choice == "1") {
		std::cout << "Enter a name for your radical fighter: " << std::endl;
		std::cin >> name;
		Fighter ship(name);
		}
		else if (choice == "Destroyer" || choice == "2") {
		std::cout << "Enter a name for your awesome destroyer: " << std::endl;
		std::cin >> name;
		Destroyer ship(name);
		}
		*/
//}

int main(void)
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);


//	shipInit();
	//From tutorial////////
	int ch = 0; 
	int x = 0, y = 0;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;
	//////////////////////


	getmaxyx(stdscr, max_y, max_x);
	x = max_x / 2;
	y = max_y - 1;
//	std::cin.get();
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
