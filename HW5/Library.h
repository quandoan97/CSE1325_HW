#include <iostream>
#include <vector>
#include "Publication.h"
using namespace std;

class Library{
	
	private: 
		vector<Publication> publications;
	
	public: 
		void add_publication(Publication pub);
	
		void checkout(int publication_index, string patron_name, string patron_phone);
	
		void check_in(int publication_index);
	
		string publication_to_string(int publication_index);
	
		int number_of_publications();
	};