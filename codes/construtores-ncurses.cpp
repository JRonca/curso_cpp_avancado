#include <iostream>
#include <ncurses.h>

class Qualquer{
	public:
		Qualquer(){
			initscr();
		}

		void uma_funcao(){
			printw("Uma funcao qualquer");
			refresh();
		}
		
		void outra_funcao(){
			move(3,20);
			printw("Outra funcao Qualquer");
		}

		~Qualquer(){
			getch();
			endwin();
		}
};

int main( int argc, char **argv  ){
	Qualquer q;
	q.uma_funcao();
	q.outra_funcao();
	return 0;
}
