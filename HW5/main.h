#include <iostream>
#include "Library.h"
#include "Publication.h"

using namespace std;

class Main{
	private:
		Library library;
	
	public:
		int main(){
			return 0;
		}
	
		void list_publications();
	
		int execute_cmd(int cmd);
};