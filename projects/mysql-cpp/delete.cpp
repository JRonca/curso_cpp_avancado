#include <iostream>
#include <mysql.h>
#include <cstring>
#include <string>

int main( int argc, char **argv  ){
	MYSQL * connect;
	connect = mysql_init(NULL);
	std::string del, id;
	connect = mysql_real_connect( connect, "172.17.0.2", "root", "root", "cpp", 0, NULL, 0 );
	if(argc < 1){
		std::cout << "uso: " << argv[0] << " [id da linha a ser deletada]" << "\n";
		return 0;
	}else{
		id = argv[1];
	}

	try{
		if(!connect){
			throw connect;
			return 1;
		}

		MYSQL_RES * res_set;
		MYSQL_ROW row;

		//std::cout << "Informe o nome: ";
		//std::getline(std::cin, nome);

		//std::cout << "Informe o e-mail: ";
		//std::getline(std::cin, mail);

		del = "DELETE FROM crudcpp WHERE id="+ id;

		bool query_state = mysql_query(connect, del.c_str());

		if(!query_state){
			std::cout << "Dados deletados com sucesso!" << "\n";
		}else{
			std::cout << "Erro ao deletar os dados: " << mysql_error( connect ) << "\n";
		}

		mysql_close(connect);

		return 0;
	}catch(...){
		std::cout << "Falha ao conectar." << "\n";
	}
}
// sudo apt install libmysqlclient-dev libmysqlcppconn-dev
// g++ delete.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o delete
