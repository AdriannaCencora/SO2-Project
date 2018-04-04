#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <ncurses.h>
#include "snake.h"


void initWindows(std::vector<WINDOW*>& vecOfWindows, int x, int y);
WINDOW* createNewWindow(int y, int x, int begY, int begX);

int main(int argc, char* argv[]){

	std::vector<WINDOW*> vecOfWindows;

	int x{0}; 
	int y{0}; 

	std::mutex mx;

	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr,y, x);
	refresh();
	initWindows(vecOfWindows, y, x);
	refresh();
	getch();
	endwin();
	
	return 0;
}

void initWindows(std::vector<WINDOW*>& vecOfWindows, int y, int x){

	vecOfWindows.push_back(createNewWindow(y/2, x/2, 0, 0));
	vecOfWindows.push_back(createNewWindow(y/2, x/2, 0, x/2));
	vecOfWindows.push_back(createNewWindow(y/2, x/2, y/2, 0));
	vecOfWindows.push_back(createNewWindow(y/2, x/2, y/2, x/2));

}


WINDOW *createNewWindow(int y, int x, int begY, int begX){
	WINDOW *window;
	window = newwin(y, x, begY, begX);
	wborder(window, '|', '|', '-', '-', '#', '#', '#', '#');
	wrefresh(window);
 	refresh();
	return window;
}
