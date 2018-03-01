#include "main.h"
using namespace std;
int main(){
	int choice = 0;
	while(choice!= 9){
		cout<<" C1325 LIBRARY MANAGEMENT SYSTEM" <<endl;
		cout<<"Publications"<<endl;
		cout<<"------------"<<endl;
		cout<<"1. Add publication \n2. List all publication \n3.Check out publication \n4.Check in publication" <<endl;
		cout<<"\nUtility\n-------"<<endl;
		cout<<"9. exit \n0. Help"<<endl;
		
		cin >> choice;
		
		execute_cmd(choice);
	}
	
	return 0;
}

int execute_cmd(int cmd){
	if(cmd == 0){
		
	}
	return cmd;	
}