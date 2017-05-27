/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 14:20:55 by bsaunder         ###   ########.fr       */
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
#include "Projectile.hpp"



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

	Fighter	fighter;
	Projectile pew;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);

//	shipInit();
	int ch = 0; 
	int max_x = 0, max_y = 0;

	getmaxyx(stdscr, max_y, max_x);
	fighter._posX = max_x / 2;
	fighter._posY = max_y - 1;

	while (1) // Main Gameloop
	{
		ch = getch();
		switch (ch)
		{
			case 'q':
				endwin();
				return (0);
				break;
			case KEY_UP:
			   if (fighter._posY > 0)
				   fighter._posY--; break;
			case KEY_DOWN: 
			   if (fighter._posY < max_y - 1)
				   fighter._posY++; break;
			case KEY_LEFT:
			   if (fighter._posX > 0)
				   fighter._posX--; break;
			case KEY_RIGHT:
			   if (fighter._posX < max_x - 3)
				   fighter._posX++; break;
			case 'y':
				Projectile pew;
				pew._posX = fighter._posX;
				pew._posY = fighter._posY;
				
				/*
				while (pew._posY >= 0) 
				{
					clear();
					mvprintw(pew._posY-2, pew._posX, "H");
					usleep(10000);
					pew._posY--;
					refresh();
				}
				*/
		}

		//Start of render code
		clear();
		
		std::string	type = fighter._type;
		
		mvprintw(fighter._posY, fighter._posX, "^T^");
		

		mvprintw(10, 10, "I");
		refresh();
		
		
		
		usleep(2000);
		//end of renderer code

	}

	endwin();
	return (0);
}
