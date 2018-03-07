#include <iostream>
using namespace std;

enum Color{red, green, blue};

int main(){
	string color_to_string[3] = {"red","green","blue"}; 
	Color color = red;
	cout<< color_to_string[color] <<endl;
	return 0; 
}