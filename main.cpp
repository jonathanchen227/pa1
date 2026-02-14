// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  cardList alice;
  cardList bob;  
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line)){
        if ( line.empty() ) { continue; }
	stringstream ss(line);
        string suit;
        string value;
        ss >> suit >> value;
	Card c = Card(suit,value);
        alice.insert(c);
  }
  cardFile1.close();


  while (getline (cardFile2, line)){
	if ( line.empty() ) { continue;}
        stringstream ss(line);
        string suit;
        string value;
        ss >> suit  >> value;
	Card d = Card(suit,value);
        bob.insert(d);
  }
  cardFile2.close();
  
bool match = true;
  while (match){
        match = false;
        for ( auto a = alice.begin(); a != alice.end(); ++a) {
                if ( bob.contains(*a) ) {
                    Card c = *a;
		    cout << "Alice picked matching card " << c << endl;
                    bob.remove(c);
                    alice.remove(c);
                    match = true;
                    break;

                }
        }
        for (auto b = bob.rbegin(); b != bob.rend(); ++b) {
               if ( alice.contains(*b) ) {
		      Card c = *b;
                      cout << "Bob picked matching card " << c << endl;
                      alice.remove(c);
                      bob.remove(c);
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
