#include <iostream> 

using namespace std;

enum Age{children, teen, adult, restricted};
enum Genre{fiction, non-fiction, self-help, performance};
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
			
		}
};