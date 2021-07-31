#include <iostream>
#include <mysql.h>
#include <cstring>
#include <string>

int main( int argc, char **argv  ){
	MYSQL * connect;
	connect = mysql_init(NULL);
	std::string create, nome, mail;
	connect = mysql_real_connect( connect, "172.17.0.2", "root", "root", "cpp", 0, NULL, 0 );
	if(argc < 2){
		std::cout << "uso: " << argv[0] << " '[nome]' [email]" << "\n";
		return 0;
	}else{
		nome = argv[1];
		mail = argv[2];
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

		create = "INSERT INTO crudcpp VALUES( NULL, '" + nome + "', '"+ mail +"')";

		bool query_state = mysql_query(connect, create.c_str());

		if(!query_state){
			std::cout << "Dados Inseridos com sucesso!" << "\n";
		}else{
			std::cout << "Erro ao inserir os dados: " << mysql_error( connect ) << "\n";
		}

		mysql_close(connect);

		return 0;
	}catch(...){
		std::cout << "Falha ao conectar." << "\n";
	}
}
// sudo apt install libmysqlclient-dev libmysqlcppconn-dev
// g++ create.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o create
