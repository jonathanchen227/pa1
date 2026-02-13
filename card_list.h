// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

class cardList {

private:
struct Node {

Card data;
Node* left;
Node* right;
Node* parent;

Node(const Card& c): data(c), left(nullptr), right(nullptr), parent(nullptr) {} 

};

Node* root;
void destroy(Node* node);

public: 

cardList();
~cardList();

void insert(Card& card);
void remove(const Card& card);
bool contains(Card& card);
void print();
Node* minimum(Node* n) const;
Node* maximum(Node* n) const;
Node* findNode(Card& card);

class iterator {
	Node* current;
	const cardList* tree;
	
	public:
	iterator(Node* n,const cardList* t );
        Card& operator*();
        Card* operator->() const;
	iterator& operator++();
	iterator& operator--();
	bool operator==(const iterator& other) const;
	bool operator!=(const iterator& other) const;
	friend class CardList;
};
iterator begin();
iterator end();
iterator rbegin();
iterator rend();

};

#endif
