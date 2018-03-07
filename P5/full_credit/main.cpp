
#include "dialog.h"
#include "enums.h"
#include "library.h"
#include "publication.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Gtk::Main kit(argc, argv);
  Library library;
  
  
  
  int cmd = -1;
  while (cmd != 0) {
    string menu = R"(
    
================================= 
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Utility
-------
(9) Help
(0) Exit
Command?
)"; 
    
    Dialog *library_dialog = new Dialog(menu, "Library", "0");
    cmd = std::stoi(library_dialog->get_user_input());
    
    if (cmd == 1) { // Add publication
      string title, author, copyright, isbn;
      int temp;
      Genre genre;
      Media media;
      Age age;
      
      library_dialog = new Dialog("Title", "Library", "0");
      title = library_dialog->get_user_input();
      
      library_dialog = new Dialog("Author", "Library", "0");
      author = library_dialog->get_user_input();
  
      library_dialog = new Dialog("Copyright", "Library", "0");
      copyright = library_dialog->get_user_input();
  
      string genres = R"(
      (0) Fiction
      (1) Nonfiction
      (2) Self Help
      (3) Performance
      )";
      
      library_dialog = new Dialog(genres, "Genre", "0");
      temp = std::stoi(library_dialog->get_user_input());
      genre = (Genre) temp;
      
      string medias = R"(
      (0) book
      (1) periodical
      (2) news paper
      (3) audio
      (4) video
      )";
      
      library_dialog = new Dialog(medias, "Media", "0");
      temp = std::stoi(library_dialog->get_user_input());
      media = (Media) temp;
      
      string ages = R"(
      (0) children
      (1) teen
      (2) adult
      (3) restricted
      )";
      library_dialog = new Dialog(ages, "Age", "0");
      temp = std::stoi(library_dialog->get_user_input());
      age = (Age) temp;
      
      library_dialog = new Dialog("ISBN", "Library", "0");
      isbn = library_dialog->get_user_input();

      try {
        library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));
      } catch (Publication::Invalid_transaction e) {
        cerr << "Unable to add" << endl;
      }

   } 
   if (cmd >= 2 && cmd <= 4) {                                                              // List all publications
      string all_pub ="";
      for (int i=0; i<library.number_of_publications(); ++i){
        all_pub += std::to_string(i) + ") " + library.publication_to_string(i) + "\n";
        
      }
     Gtk::Dialog *dialog = new Gtk::Dialog();
     dialog->set_title("List of Publications");
     
     Gtk::Label *label = new Gtk::Label(all_pub);
     dialog->get_content_area()->pack_start(*label);
     label->show();
     dialog->add_button("OK", 1);
     
     dialog->run();
     dialog->close();
     
     while(Gtk::Main::events_pending()){
		    Gtk::Main::iteration();
	   }

	   delete label;
	   delete dialog;
   }
   if (cmd == 3) {                                                                           // Check out publication
      int pub;
      string pat;
      string pat_phone;
  
      library_dialog = new Dialog("Publication Number", "Library", "0");
      pub = std::stoi(library_dialog->get_user_input());

      library_dialog = new Dialog("Patron Name", "Library", "0");
      pat = library_dialog->get_user_input();
     
      library_dialog = new Dialog("Patron Phone Number", "Library", "0");
      pat_phone = library_dialog->get_user_input();
  
      try {
        library.check_out(pub, pat, pat_phone);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked out!" << endl;
      }
      
   } 
   if (cmd == 4) {                                                                           // Check in publication
      int pub;
     
      library_dialog = new Dialog("Publication Number", "Library", "0");
      pub = std::stoi(library_dialog->get_user_input());
  
      try {
        library.check_in(pub);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked in!" << endl;
      }
  
   } 
   if (cmd == 9) { // Help
      
     Gtk::Dialog *dialog = new Gtk::Dialog();
     dialog->set_title("Help");
     
     Gtk::Label *label = new Gtk::Label("1. To add a publication \n2. To List out all of the publications\n3. To check out a publication \n4. To check in a publication" );
     dialog->get_content_area()->pack_start(*label);
     label->show();
     dialog->add_button("OK", 1);
     
     dialog->run();
     dialog->close();

   } 
   if (cmd == 99) { // Easter Egg
     library.easter_egg();
   } 
   if (cmd < 0 || (4 < cmd && cmd < 9) || (9 < cmd && cmd < 99) || (99 < cmd)) { // Invalid command
     cerr << "**** Invalid command - type 9 for help" << endl << endl;
   }
  }
}  
