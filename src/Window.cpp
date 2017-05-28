

#include "Window.hpp"
#include <ncurses.h>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>

Window::Window(): fighter(Ship()), keyPress(ERR), prevKeyPress(ERR), timeFrameCount(0), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), WSTARTX(SHIPX), WSTARTY(SHIPY) {
	init();
}

Window::Window(Window const & src): fighter(Ship()), keyPress(ERR), prevKeyPress(ERR), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), WSTARTX(SHIPX), WSTARTY(SHIPY) {
	init();
	*this = src;
}

Window::~Window() {
	destroyWin();
    endwin();
    std::cout << "You Died, Bummer Dude" << std::endl;
}

Window const &	Window::operator=(Window const & rhs) {
	if (this != &rhs) {
		this->keyPress = rhs.keyPress;
		this->prevKeyPress = rhs.prevKeyPress;
		this->start = rhs.start;
		this->now = rhs.now;
	}
	return *this;
}

void	Window::createWin() {

    newScr = newwin(HEIGHT, WIDTH, WSTARTY, WSTARTX);
    box(newScr, 0 , 0);
    wrefresh(newScr);
}

void	Window::destroyWin() {
    wrefresh(newScr);
    clear();
    refresh();
    delwin(newScr);
}

void    Window::shoot(int y) {
    int i;
    
    for (i = 0; i < 10; i++) {
        if(projectiles[i] == NULL) {
            projectiles[i] = new Projectile(WSTARTX + 6, y);
            return;
        }
    }
}

void    Window::movesprites(int const keyPress)
{

    fighter.move(keyPress, timeFrameCount);
    if (keyPress == 32) {
        shoot(fighter.getY());
    }
    for (int i = 0; i < 1; ++i) {
        if (sprites[i]) {
            if (!sprites[i]->move(timeFrameCount)) {
                delete sprites[i];
                sprites[i] = NULL;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (projectiles[i]) {
            if (!projectiles[i]->move(timeFrameCount)) {
                delete projectiles[i];
                projectiles[i] = NULL;
            }
        }
    }
}

void    Window::printScreen() {

    fighter.toPrint();
    for (int i = 0; i < 1; ++i) {
        if (sprites[i])
            sprites[i]->toPrint();
    }
    for (int i = 0; i < 10; ++i) {
      if (projectiles[i])
            projectiles[i]->toPrint();  
    }
}

void    Window::createArray() {

    for (int i = 0; i < 1; ++i) {
        if (sprites[i])
            sprites[i] = NULL;
    }
}

void    Window::createProjectiles() {

    for (int i = 0; i < 10; ++i)
        sprites[i] = new Projectile();
}

void    Window::createArray2() {
    for (int i = 0; i < 10; ++i) {
        if (projectiles[i])
            projectiles[i] = NULL;
    }
}

void	Window::init() {

    createArray();
	initscr();
    createArray2();

    noecho();
    curs_set(false);
    timeout(0);
    cbreak();
    keypad(stdscr, true);

    gettimeofday(&start, NULL);
    refresh();
    createWin();
    printScreen();
}

unsigned int    Window::timediff(timeval t1, timeval t2) {

    return ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void	Window::pewPew() {

    //score = 0;
    keyPress = getch();

    while (keyPress != 27) { //Not ESCKEY
        keyPress = getch();
        if (keyPress != ERR) {
            prevKeyPress = keyPress;
        }

        gettimeofday(&now, NULL);      
        if (timediff(start, now) >= (1000000 / 24)) {
            // ncurses functions
            destroyWin();
            createWin();
            movesprites(prevKeyPress);
            printScreen();

            prevKeyPress = ERR;
            start = now;
            timeFrameCount++;
        }
    }
}
