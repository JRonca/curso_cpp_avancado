#include <iostream>
#include <mysql.h>

int main( int argc, char **argv  ){
	MYSQL * connect;
	connect = mysql_init(NULL);
	connect = mysql_real_connect( connect, "172.17.0.2", "root", "root", "cpp", 0, NULL, 0 );
	try{
		if(!connect){
			throw connect;
			return 1;
		}

		MYSQL_RES * res_set;
		MYSQL_ROW row;

		mysql_query(connect, "SELECT * FROM crudcpp");

		res_set = mysql_store_result(connect);
		unsigned int numrows = mysql_num_rows(res_set);
		std::cout << numrows << "\n";
		while((row = mysql_fetch_row(res_set)) != NULL){
			std::cout << row[0] << " | " << row[1] << " | " << row[2] << "\n";
		}

		mysql_close(connect);

		return 0;
	}catch(...){
		std::cout << "Falha ao conectar." << "\n";
	}
}
// sudo apt install libmysqlclient-dev libmysqlcppconn-dev
// g++ read.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o read
