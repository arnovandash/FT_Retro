/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:38:42 by arnovan-          #+#    #+#             */
/*   Updated: 2017/05/27 12:29:34 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	std::cin.get();

	int ch = 0; 
	int x = 10, y = 10;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;

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
