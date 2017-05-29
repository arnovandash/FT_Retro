

#include "Window.hpp"
#include <ncurses.h>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>


Window::Window() : fighter(Ship()), starInit(false), keyPress(ERR), prevKeyPress(ERR), score(0), lives(5), timeFrameCount(0), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), WSTARTX(SHIPX), WSTARTY(SHIPY) {
	init();
}

Window::Window(Window const & src): fighter(Ship()), starInit(false), keyPress(ERR), prevKeyPress(ERR), score(0), lives(5), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), WSTARTX(SHIPX), WSTARTY(SHIPY) {

	init();
	*this = src;
}

Window::~Window() {
	destroyWin();
    endwin();
    std::cout << "You Died, Bummer Dude.. Your final score: " << score << std::endl;
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

void    Window::spawn() {
	int i;

	for (i = 0; i < 20; i++) {
		if(obstacles[i] == NULL) {
			obstacles[i] = new Obstacle(WINWIDTH + 2, rand() % (WINHEIGHT - 2) + 6);
			break;
		}
	}
	if (timeFrameCount % 15 == 0)
	{
		for (i = 0; i < 10; i++) {
			if(enemies[i] == NULL) {
				enemies[i] = new Enemy(WINWIDTH + 2, rand() % (WINHEIGHT - 2) + 6);
				break;
			}
		}
	}
	return;
}

void    Window::starSpawn() {
	int i;
	if (this->starInit == false)
	{
		for (i = 0; i < 80; i++) {
			if(starfield[i] == NULL) {
				starfield[i] = new Starfield(rand() % WINWIDTH + 2, rand() % (WINHEIGHT - 2) + 6);
			}
		}
		this->starInit = true;
	}
	else
	{
		for (i = 0; i < 80; i++) {
			if(starfield[i] == NULL) {
				starfield[i] = new Starfield(WINWIDTH + 2, rand() % (WINHEIGHT - 2) + 6);
				break;
			}
		}
	}
	return;
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
//	starSpawn();
	if (timeFrameCount % 6 == 0)
		spawn();
	fighter.move(keyPress, timeFrameCount);
	if (keyPress == 32) {
		shoot(fighter.getY());
	}
//	for (int i = 0; i < 80; ++i) {
//		if (starfield[i]) {
//			if (!starfield[i]->move(timeFrameCount)) {
//				delete starfield[i];
//				starfield[i] = NULL;
//			}
//		}
//	}
	for (int i = 0; i < 10; ++i) {
		if (projectiles[i]) {
			if (!projectiles[i]->move(timeFrameCount)) {
				delete projectiles[i];
				projectiles[i] = NULL;
			}
		}
	}

	for (int i = 0; i < 20; ++i) {
		if (obstacles[i]) {
			if (!obstacles[i]->move(timeFrameCount)) {
				delete obstacles[i];
				obstacles[i] = NULL;
			}
		}
	}


	for (int i = 0; i < 10; ++i) {
		if (enemies[i]) {
			if (!enemies[i]->move(timeFrameCount)) {
				delete enemies[i];
				enemies[i] = NULL;
			}
		}
	}
	for (int i = 0; i < 1; ++i) {
		if (sprites[i]) {
			if (!sprites[i]->move(timeFrameCount)) {
				delete sprites[i];
				sprites[i] = NULL;
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

	for (int i = 0; i < 20; ++i) {
		if (obstacles[i])
			obstacles[i]->toPrint();  
	}

	for (int i = 0; i < 10; ++i) {
		if (enemies[i])
			enemies[i]->toPrint();  
	}

//	for (int i = 0; i < 80; ++i) {
//		if (starfield[i])
//			starfield[i]->toPrint();  
//	}
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

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	
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

int     Window::impact() {
    for (int j = 0; j < 10; ++j) {
        for (int k = 0; (k < 10 && projectiles[j]) ; ++k) {
            if (enemies[k] && projectiles[j]->impact(enemies[k])) {
                delete projectiles[j];
                projectiles[j] = NULL;
				delete enemies[k];
				enemies[k] = NULL;
				score += 5;
			}
		}
	}
	for (int x = 0; x < 10; ++x) {
		if (enemies[x] && fighter.impact(enemies[x])) {
			if (lives == 0) {
				delete enemies[x];
				enemies[x] = NULL;
				keyPress = 27;
				return 0;
			}
			else {
					lives--;
					delete enemies[x];
					enemies[x] = NULL;
				}
			}
		}

   for (int j = 0; j < 10; ++j) {
        for (int k = 0; (k < 20 && projectiles[j]) ; ++k) {
            if (obstacles[k] && projectiles[j]->impact(obstacles[k])) {
                delete projectiles[j];
                projectiles[j] = NULL;
				delete obstacles[k];
				obstacles[k] = NULL;
				score += 5;
			}
		}
	}
	for (int x = 0; x < 20; ++x) {
		if (obstacles[x] && fighter.impact(obstacles[x])) {
			if (lives == 0) {
				delete obstacles[x];
				obstacles[x] = NULL;
				keyPress = 27;
				return 0;
			}
			else {
					lives--;
					delete obstacles[x];
					obstacles[x] = NULL;
				}
			}
		}
		return (1);
	}


	unsigned int    Window::timediff(timeval t1, timeval t2) {

		return ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
	}

	void	Window::pewPew() {

		int maxX = 0, maxY = 0;
		keyPress = getch();

		while (keyPress != 27) {
			keyPress = getch();
			if (keyPress != ERR) {
				prevKeyPress = keyPress;
			}
			getmaxyx(stdscr, maxY, maxX);
			gettimeofday(&now, NULL);

//			Potential bonus, Disabled due to flickering
//			if (this->starInit == false)
//				Window::starSpawn();

			if (timediff(start, now) >= (1000000 / 30)) {
				if (maxX < WINWIDTH + 10 || maxY < WINHEIGHT) {
					clear();
					mvprintw(0,0, "GAME PAUSED!\nTerminal window too small. Please resize!");
					refresh();
				}

				else {
					destroyWin();
					printw("Score: %d\nLives remaining: %d\nTime: %d", score, lives, timeFrameCount/30);
					createWin();
					movesprites(prevKeyPress);
					impact();
					printScreen();
					prevKeyPress = ERR;
					start = now;
				}
				timeFrameCount++;
				score++;
			}
		}
	}
