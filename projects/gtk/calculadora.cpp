#include <iostream>
#include <gtkmm.h>
#include <string>

using namespace Gtk;

Window * pWindow;
Entry * display, * result;
Button * btn_add, * btn_sub, * btn_mult, * btn_div, * btn_equal, * btn_ce;
Button * btn0, * btn1, * btn2, * btn3, * btn4, * btn5, * btn6, * btn7, * btn8, * btn9;

void on_btn_soma_clicked(){
	std::string a = num1->get_text();
	std::string b = num2->get_text();

	int x = std::stoi( a );
	int y = std::stoi( b );
	result->set_text(std::to_string(x+y));
	num1->set_text("");
	num2->set_text("");
}

int main( int argc, char **argv  ){

	auto app = Application::create(argc,argv,"org.gtkmm.calculadora");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("calculadora.glade");
	refBuilder->get_widget("window", pWindow);

	if(pWindow){
		refBuilder->get_widget("display", display);
		refBuilder->get_widget("result", result);
		refBuilder->get_widget("btn_add", btn_add);
		refBuilder->get_widget("btn_sub", btn_sub);
		refBuilder->get_widget("btn_mult", btn_mult);
		refBuilder->get_widget("btn_add", btn_add);
		refBuilder->get_widget("btn_add", btn_add);
		refBuilder->get_widget("btn_add", btn_add);
	}
	if( btn_soma ){
		btn_soma->signal_clicked().connect(sigc::ptr_fun(on_btn_soma_clicked));
	}
	app->run(*pWindow);
	delete pWindow;
	return 0;
}
