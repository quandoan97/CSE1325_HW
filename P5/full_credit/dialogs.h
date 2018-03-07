#ifndef _DIALOGS_H
#define _DIALOGS_H
#include <iostream>
#include <gtkmm.h>

class Dialogs{
	public:
		static std::string input(std::string msg, std::string title = "Input", std::string default_text = "", std::string cancel_text = "CANCEL");
};

#endif