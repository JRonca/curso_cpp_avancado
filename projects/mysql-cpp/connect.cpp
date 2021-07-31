#include <iostream>
#include <mysql.h>

int main( int argc, char **argv  ){
	MYSQL * connect;
	connect = mysql_init(NULL);
	if(!connect){
		std::cout << "Mysql nao foi inicializado" << "\n";
		return 1;
	}

	connect = mysql_real_connect( connect, "172.17.0.2", "root", "root", "cpp", 0, NULL, 0 );
	if(connect){
		std::cout << "Conectado com sucesso ao Mysql" << "\n";
	}else{
		std::cout << "fala ao conectar ao banco de dados" << "\n";
	}

	mysql_close(connect);
	return 0;
}
// sudo apt install libmysqlclient-dev libmysqlcppconn-dev
// g++ connect.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o connect
