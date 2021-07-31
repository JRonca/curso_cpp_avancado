#include <iostream>
#include <gtkmm.h>
#include <string>
#include <regex>

using namespace Gtk;

Window * pWindow;
Entry * num1, * num2, * result;
Button * btn_soma;
Label * title_label;

bool is_number(std::string str){
	std::regex re("^[0-9]+$");
	std::smatch match;
	return std::regex_search(str, match, re);
}

void on_btn_soma_clicked(){
	std::string a = num1->get_text();
	std::string b = num2->get_text();

	if(is_number(a) && is_number(b)){
		int x = std::stoi( a );
		int y = std::stoi( b );
		result->set_text(std::to_string(x+y));
		num1->set_text("");
		num2->set_text("");
		title_label->set_text("Soma efetuada");
	}else{
		title_label->set_text("Insira Apenas Numeros");
	}
}

int main( int argc, char **argv  ){

	auto app = Application::create(argc,argv,"org.gtkmm.calculadora");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("soma.glade");
	refBuilder->get_widget("window", pWindow);

	if(pWindow){
		refBuilder->get_widget("num1", num1);
		refBuilder->get_widget("num2", num2);
		refBuilder->get_widget("result", result);
		refBuilder->get_widget("btn_soma", btn_soma);
		refBuilder->get_widget("title_label", title_label);
	}
	if( btn_soma ){
		btn_soma->signal_clicked().connect(sigc::ptr_fun(on_btn_soma_clicked));
	}
	app->run(*pWindow);
	delete pWindow;
	return 0;
}
