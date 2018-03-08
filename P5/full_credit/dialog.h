#ifndef _DIALOG_H
#define _DIALOG_H
#include <iostream>
#include <gtkmm.h>

class Dialog{
	private:
		std::string user_input;
	public:
		Dialog(std::string msg, std::string title, std::string cancel_text){
			user_input = input(msg, title, cancel_text);
		}	
	
		std::string input(std::string msg, std::string title, std::string cancel_text);
	
		std::string get_user_input();
};

#endif