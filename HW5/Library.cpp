#include "Library.h"

void add_publication(Publication pub){
	string title;
	string author;
	string copyright;
	Genre genre;
	Media media;
	Age target_age;
	string isbn;
	
	cout << "What is the title" <<endl;
	cin >> title;
	cout << "What is the author" <<endl;
	cin >> author;
	cout << "What is the copyright" <<endl;
	cin >> copyright;
	cout << "What is the genre (enter in a number)\n 1. Fiction\n 2. nonfiction\n 3. Self-help\n 4. Performance" <<endl;
	cin >> genre;
	cout << "What is the media (enter in a number)\n 1. Book\n 2. Magazine\n 3. Newspaper\n 4. audio\n 5. video" <<endl;
	cin >> media;
	cout << "What is the target_age(enter in a number)\n 1.children\n 2.teen\n 3.adult\n 4.restricted" <<endl;
	cin >> target_agel
	cout << "What is the isbn number" <<endl;
	cin >> isbn;
	
	Publication pub(title, author, copyright, genre, media, target_age, isbn);
}

void checkout(int publication_index, string patron_name, string patron_phone){
	
}