#include <iostream>
#include <algorithm> // fid_if_not
/* #include <iterator>// std::begin std::end (usado modos 1 e 2) */

//modo 1 (normal)
/* bool eh_letra(char c){ */
/* 	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); */
/* } */

//modo 2 com functor
/* struct EhLetra{ */
/* 	bool operator() (char c) const { */
/* 		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); */
/* 	} */
/* }; */

//modo 3 com expressao lambda

int main( int argc, char **argv  ){
	const char str[] = "dfg8lkpw04";
	
	//modo 1 (normal)
	/* const char *it = std::find_if_not(std::begin(str), std::end(str), eh_letra); */

	//modo 2 com functor
	/* const char *it = std::find_if_not(std::begin(str), std::end(str), EhLetra{}); */
	/* auto it = std::find_if_not(std::begin(str), std::end(str), EhLetra{}); */

	//modo 3 com expressao lambda
	auto it = std::find_if_not(std::begin(str), std::end(str), [] (char c){
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); 
	});

	std::cout << "O caractere que nao e letra de str e: " << *it << "\n";
	return 0;
}
