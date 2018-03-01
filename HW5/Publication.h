#include <iostream> 

using namespace std;

enum Age{children, teen, adult, restricted};
enum Genre{fiction, nonfiction, selfhelp, performance};
enum Media{books, magazines, newspapers, audio, video};

class Publication{
	
	private:
		string title;
		string author;
		string copyright;
		Genre genre;
		Media media;
		Age target_age;
		string isbn;
		bool checked_out;
		string patron_name;
		string patron_phone;
	
	public: 
		
		Publication(string title, string author, string copyright, Genre genre, Media media, Age target_age, string isbn){
			this->title = title;
			this->author = author;
			this->copyright = copyright;
			this->genre = genre;
			this->media = media;
			this->target_age = target_age;
			this->isbn = isbn;
		}
	
		check_out(string patron_name, string patron_phone){
			this->patron_name = patron_name;
			this->patron_phone = patron_phone;
		}
		
		void check_in();
	
		bool is_checked_out();
	
		string to_string();
		
};