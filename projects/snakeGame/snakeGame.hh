#ifndef SNAKE_GAME_H
#define SNALE_GAME_H
#include <iostream>// time and rand
#include <ncurses.h>
#include <vector>// lógica das coordenadas
#include <unistd.h> // usleep()

//logica para armazenar as coordenadas
struct SnakeType{
	int s_x, s_y;
	SnakeType(int, int);
	SnakeType();
};

class SnakeGame{
	protected:
		int m_maxwidth; // tamanho largura
		int m_maxheight; //tamanho altura
		std::vector<SnakeType> snake;
		char m_snake_char; //desenha a snake
		SnakeType v_food;
		char m_food_char;
		int m_delay;
		char m_direction;
		bool m_tail_stop;
		int m_score;
	public:
		SnakeGame();
		~SnakeGame();
		void m_insert_food();
		void moveSnake();
		bool _colision();
		void start();
};
#endif
