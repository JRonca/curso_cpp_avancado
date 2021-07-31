#include "snakeGame.hh"

SnakeType::SnakeType(int s_col, int s_row){
	s_x = s_col;
	s_y = s_row;
}
SnakeType::SnakeType(){
	s_x = 0;
	s_y = 0;
}

SnakeGame::SnakeGame(){
	initscr();
	nodelay( stdscr, true ); //para a snake nao parar (ncurses)
	keypad( stdscr, true ); //KEY_.... ex: KEY_DOWN
	noecho();// para nao exibir teclas na tela
	curs_set(0);// desativar cursor de escrita

	m_maxwidth = getmaxx(stdscr) / 2;
	m_maxheight = getmaxy(stdscr) /2;

	m_snake_char = 'O';//desenhando a snake

	m_food_char = 'X';
	srand(time(NULL)); // para toda vez que iniciar o game a posição da comida ser randomica
	m_insert_food();

	m_delay = 100000;
	m_direction = 'L';
	m_tail_stop =false;

	m_score = 0;

	//desenhando a margem superior	
	for(int i=0; i < m_maxwidth -1; i++ ){
		move(0,i);
		if(i==0 || i==(m_maxwidth -2)){
			addch('+');
		}else{
			addch('-');
		}
	}

	//desenhando a margem esquerda	
	for(int i=1; i < m_maxheight -1; i++ ){
		move(i,0);
		if( i==(m_maxheight -2)){
			addch('+');
		}else{
			addch('|');
		}
	}

	//desenhando a margem inferior	
	for(int i=1; i < m_maxwidth -1; i++ ){
		move(m_maxheight-2,i);
		if( i==(m_maxwidth -2)){
			addch('+');
		}else{
			addch('-');
		}
	}

	//desenhando a margem direita	
	for(int i=1; i < m_maxheight -2; i++ ){
		move(i,m_maxwidth-2);
		addch('|');
	}

	// desenha o tamanho inicial da snake
	for(int i = 0; i<5; i++){
		snake.push_back( SnakeType(20+i,7) );
	}

	for(size_t i=0; i<snake.size(); i++){
		move(snake[i].s_y, snake[i].s_x);
		addch(m_snake_char);
	}

	move(m_maxheight +1, 0);
	printw("%d", m_score);

	move(v_food.s_y, v_food.s_x);
	addch(m_food_char);
}

SnakeGame::~SnakeGame(){
	nodelay(stdscr,false);
	getch();
	endwin();
}

void SnakeGame::m_insert_food(){
	while(1){
		int tmpx = rand() % m_maxwidth + 1;
		int tmpy = rand() % m_maxheight + 1;

		for(size_t i=0; i<snake.size(); i++){
			if(snake[i].s_x == tmpx && snake[i].s_y == tmpy){
				continue;
			}
		}
		if( tmpx >= m_maxwidth - 2 || tmpy >= m_maxheight - 3 ){
			continue;
		}
		v_food.s_x = tmpx;
		v_food.s_y = tmpy;


		move(v_food.s_y, v_food.s_x);
		addch(m_food_char);
		refresh();
		break;
	}
}

void SnakeGame::moveSnake(){
	int tmp = getch();
	switch( tmp ){
		case KEY_LEFT:
			if(m_direction != 'R'){
				m_direction = 'L';
			}
			break;
		case KEY_UP:
			if(m_direction != 'D'){
				m_direction = 'U';
			}
			break;
		case KEY_DOWN:
			if(m_direction != 'U'){
				m_direction = 'D';
			}
			break;
		case KEY_RIGHT:
			if(m_direction != 'L'){
				m_direction = 'R';
			}
			break;
		case 'q':
			m_direction = 'Q';
			break;
	}
	if(!m_tail_stop){
		move( snake[snake.size() -1].s_y, snake[snake.size()-1].s_x );
		printw(" ");
		refresh();
		snake.pop_back();
	}

	if(m_direction == 'L'){
		snake.insert(snake.begin(),SnakeType(snake[0].s_x-1, snake[0].s_y));
	}

	if(m_direction == 'R'){
		snake.insert(snake.begin(),SnakeType(snake[0].s_x+1, snake[0].s_y));
	}

	if(m_direction == 'U'){
		snake.insert(snake.begin(),SnakeType(snake[0].s_x, snake[0].s_y -1));
	}

	if(m_direction == 'D'){
		snake.insert(snake.begin(),SnakeType(snake[0].s_x, snake[0].s_y +1));
	}
	move( snake[0].s_y, snake[0].s_x );
	addch(m_snake_char);
	refresh();
}

bool SnakeGame::_colision(){
	//colisao com as bordas
	if( snake[0].s_x == 0 || snake[0].s_x == m_maxwidth -2 || snake[0].s_y == 0 || snake[0].s_y == m_maxheight -2){
		return true;
	}
	//colisao com a snake
	for(size_t i = 2; i< snake.size(); i++){
		if(snake[0].s_x == snake[i].s_x && snake[0].s_y == snake[i].s_y){
			return true;
		}
	}
	//colisao de ponto
	if(snake[0].s_x == v_food.s_x && snake[0].s_y == v_food.s_y){
		m_tail_stop=true;
		m_insert_food();
		m_score += 10;
		move(m_maxheight + 1, 0);
		printw("%d", m_score);
		if((m_score%50)==0){
			m_delay -= 10000;
		}
	}else{
		m_tail_stop = false;
	}
	return false;
}

void SnakeGame::start(){
	while(1){
		if(_colision()){
			move(m_maxheight/2,(m_maxwidth/2)-4);
			printw("GAME OVER");
			usleep(5000);
			break;
		}
		moveSnake();
		if(m_direction == 'Q'){
			break;
		}
		usleep(m_delay);

	}
}
