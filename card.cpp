// card.cpp
// Author: Jonathan Chen
// Implementation of the classes defined in card.h
#include "card.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


Card::Card(string s, string val) {
     value = val;
     suit = s;
}


string Card::readSuit() {
     return suit;
}
string Card::readValue(){
    return value;
}
int Card::getSuit() const {
	if( suit == "c" ) {
		return 0;
	}
	if( suit == "d"){
		return 1;
	}
	if(suit == "s"){
		return 2;
	}
	if(suit == "h"){
		return 3;
	}
	return -1;
}
int Card::getValue() const {
	if ( value == "a") {
        	return 1;
        }
        if ( value == "j") {
		return 11;
	}
	if ( value == "q") {
		return 12;
	}
	if ( value == "k") {
		return 13;
	}
	else {
		return stoi(value);
        }
}

bool Card::operator<(const Card& other) const {
	if ( getSuit() != other.getSuit() ) {
              return getSuit() < other.getSuit();
        }
        return getValue() < other.getValue();
}

bool Card::operator==(const Card& other) {
	return suit == other.suit && value == other.value;
}

ostream& operator<<(ostream& os, const Card& c) {
	os  <<  c.suit << " " << c.value ;
return os;
} 	
