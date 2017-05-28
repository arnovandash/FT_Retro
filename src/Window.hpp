

#ifndef WINDOW_HPP
# define WINDOW_HPP

#define WINHEIGHT 30
#define WINWIDTH 100
#define SHIPX 5
#define SHIPY 5

#include "Sprite.hpp"
#include "Ship.hpp"
#include "Projectile.hpp"
#include "Obstacle.hpp"
#include "Starfield.hpp"
#include <ncurses.h>
#include <sys/time.h>

class Window {

public:

	Window(void);
	Window(Window const &);
	~Window();

	Window const &	operator=(Window const &);
	
	void	createWin();
	void	destroyWin();
	void	pewPew();

private:

	Sprite* 		sprites[100];
	Sprite* 		projectiles[1000];
	Sprite* 		starfield[10000];
	Sprite* 		obstacles[10000];
	Ship			fighter;
	bool			starInit;
	int				keyPress;
	int				prevKeyPress;
	unsigned long	timeFrameCount;
	struct timeval	start;
	struct timeval	now;
	WINDOW			*newScr;
	const int		HEIGHT;
	const int		WIDTH;
	const int		WSTARTX;
	const int		WSTARTY;

	void	init();
	void	printScreen();
	void	createArray();
	void	createArray2();
	void	createProjectiles();
	void	shoot(int y);
	void	spawn(void);
	void	starSpawn(void);
	void	movesprites(int const keyPress);
	unsigned int 	timediff(timeval t1, timeval t2);
};

#endif

