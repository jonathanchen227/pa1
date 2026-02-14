// card.h
// Author: Jonathan Chen
// All class declarations related to defining a single card go here
using namespace std;
#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
class Card {

public:

string suit;
string value;

Card(string s,string val);


string readSuit();
string readValue();


int getSuit() const;
int getValue() const;


bool operator <(const Card& other) const;
bool operator==(const Card& other) const;

friend ostream& operator<<(ostream& os,const Card& c);



};
#endif
