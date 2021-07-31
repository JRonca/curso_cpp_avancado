#include <iostream>

using std::cout;
using std::string;

void qtd_char(string &);

int main( int argc, char **argv  ){
	string str1 = "string 1";
	string str2 = "string 2";
	//int resultstr = str1.compare( 0, 6, str2, 0, 6);//retorna 0 se for igual e 1 se for diferente ( compara do 0 ao 6 )

	//cout << (str1==str2 ? "metodo conhecido: sim, sao iguais" : "metodo conhecido: nao, e diferente") <<"\n";
	//cout << (!resultstr ? "compare(): sim, sao iguais" : "compare(): nao, e diferente") <<"\n";
	
	//str1.swap(str2);
	//cout << "str1: " << str1 << "\n";
	//cout << "str2: " << str2 << "\n";

	qtd_char(str1);

	return 0;
}

void qtd_char( string &str ){
	cout << "capacity: " << str.capacity() << "\n";
	cout << "size: " << str.size() << "\n";
	cout << "length: " << str.length() << "\n";
	cout << "empty: " << str.empty() << "\n";
	str.resize( str.length() + 10);
	cout << "r capacity: " << str.capacity() << "\n";
	cout << "r size: " << str.size() << "\n";
	cout << "r length: " << str.length() << "\n";
	cout << "r empty: " << str.empty() << "\n";
	str += "abcde";
	cout << "str+= size: " << str.size() << "\n";
}
