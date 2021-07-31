#include <iostream>
#include <vector>
#include <cstring>

int main( int argc, char **argv  ){
	std::vector<std::string> v = {"DOCUMENT_ROOT", "GATEWAY_INTERFACE","HTTP_A    CCEPT", "HTTP_ACCEPT_ENCODING","HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION","HTTP_HOST", "HTTP_USER_AGENT", "PATH","QUERY_STRING","REMOTE_ADDR", "REMOTE_PORT","REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME","SCRIPT_NAME","SERVER_ADDR", "SERVER_ADMIN","SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL","SERVER_SIGNATURE", "SERVER_SOFTWARE"};
	std::cout << "content-type: text/html\n\n"
		"<!DOCTYPE html>\n"
		"<html>\n"
		"<head>\n"
		"<title>Index CPP</title>\n"
		"</head>\n"
		"<body>\n"
		"<h1>Variaveis ambiente:</h1>\n";
	std::cout << "<table border='1'>\n";
	for(auto it = v.begin(); it != v.end(); it++){
		char * value = getenv((*it).c_str());
		if(value != 0){
			std::cout << "<tr><td><b>" << *it << "</b></td><td>"<< value << "</td></tr>\n";
		}
	}
	std::cout << "</table>\n";
	
	std::cout << "</body>\n"
		"</html>\n";
	return 0;
}
