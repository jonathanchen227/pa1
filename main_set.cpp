// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  
  set<Card> alice;
  set<Card> bob;

  //Read each file
  while (getline (cardFile1, line)){
        if ( line.empty() ) {continue;}
	stringstream ss(line);
        string suit;
        string value;
        ss >> suit >> value;
        alice.insert(Card(suit,value));
  }
  cardFile1.close();


  while (getline (cardFile2, line) ){
	if ( line.empty() ) {continue;}
        stringstream ss(line);
        string suit;
	string value;
	ss >> suit  >> value;
	bob.insert(Card(suit,value));
  }
  cardFile2.close();
  
  bool match = true;
  while (match){
	match = false;
	for ( auto a = alice.begin(); a != alice.end(); ++a) {
		if ( bob.find(*a) != bob.end() ) {
                    cout << "Alice picked matching card " << *a << endl;
                    bob.erase(*a);
                    alice.erase(a);
                    match = true;
                    break;
		
		}
	}
        match = false;
	for ( auto b = bob.rbegin(); b != bob.rend(); ++b) {
               if ( alice.find(*b) != alice.end() ) {
                      cout << "Bob picked matching card " << *b << endl;
                      alice.erase(*b);
                      bob.erase(*b);
                      match = true;
 		      break;
               }
	}
}
 cout << "Alice's cards:" << endl;
 for ( const Card& card : alice ) {
      cout << card << endl;
 }
 cout << "Bob's cards:" << endl;
 for ( const Card& card : bob ) {
     cout << card << endl;
 }
  return 0;
}

