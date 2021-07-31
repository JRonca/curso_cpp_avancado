#include <iostream>
#include  <sqlite3.h>

int main( int argc, char **argv  ){
	
	sqlite3 * DB;
	bool connect = sqlite3_open("database.db", &DB);

	if(connect){
		std::cerr << "Erro ao conectar ao DB." << sqlite3_errmsg(DB) << "\n";
		return 1;
	}else{
		std::cout << "Conectado com sucesso ao DB." << "\n";
		sqlite3_close(DB);
	}

	return 0;
}
//sudo apt install sqlite3 libsqlite3-dev
//https://www.sqlite.org/cintro.html
