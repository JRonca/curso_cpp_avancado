#include <gtkmm.h>

int main( int argc, char **argv  ){
	Gtk::Main kit( argc, argv );
	Gtk::Window window;
	window.set_default_size( 600, 400 );
	window.set_title("Hello World GTK+");

	Gtk::Label label;
	label.set_text("Hello GTK+");
	window.add(label);

	window.show_all();

	Gtk::Main::run( window );
	return 0;
}
//sudo apt install libgtkmm-3.0-dev
//https://www.gtkmm.org/pt_BR/index.html
//g++ simple-gtk.cpp -o simplegtk $(pkg-config gtkmm-3.0 --cflags --libs)
