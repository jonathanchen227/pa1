// card_list.cpp
// Author: Jonathan Chen
// Implementation of the classes defined in card_list.h
#include "card_list.h"

cardList::cardList(): root(nullptr) {} 

cardList::~cardList() { destroy(root); }


void cardList::destroy(Node* node) {
	if ( node == nullptr ) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
}
cardList::Node* cardList::minimum(cardList::Node* n) const {
	if ( !n ) return nullptr;
	while (n->left) n = n -> left;
	return n;
}
cardList::Node* cardList::maximum(cardList::Node* n) const{
	if(!n) return nullptr;
	while(n->right) n = n->right;
	return n;
}
void cardList::insert(Card& card) {
	Node* node = new Node(card);
	if (root==nullptr) {
           root = node;
	   return;
        }
        Node* current = root;
        Node* parent = nullptr;
	while ( current ) {
		parent = current;
		if ( card < current->data ) {
			current = current -> left;
		}
		else {
			current = current -> right;
		}
	}
	node->parent = parent;
	if(card < parent->data ) {
		parent->left = node;
	}
	else {
		parent->right = node;
	}
}
cardList::Node* cardList::findNode(Card& card) { 
	Node* current = root;
	while ( current ) {
		if ( card == current->data ) { return current; }
		else if ( card < current->data ) {current=current->left;}
		else {current=current->right;}
	}
	return nullptr;
}
bool cardList::contains(Card& card) { return findNode(card) != nullptr; } 

void cardList::print() {
	for ( auto it = begin(); it != end() ; ++it ) 
		{std::cout<<*it<<std::endl;}
}

cardList::iterator::iterator(Node* node, const cardList* l ) : current(node),tree(l) {}

bool cardList::iterator::operator==(const cardList::iterator& other) const {return current==other.current;}
bool cardList::iterator::operator!=(const cardList::iterator& other) const {return current!=other.current;}

Card& cardList::iterator::operator*() {
return current->data;
}


Card* cardList::iterator::operator->() const {
return &(current->data);
}

cardList::iterator& cardList::iterator::operator++() {
	if ( !current) return *this;
	if(current->right) {
		current = current->right;
		while ( current->left) {
			current = current -> left;
		}
	}
	else {
		Node* parent = current ->parent;
		while ( parent && current == parent -> right ) {
			current = parent;
			parent = parent->parent;
		}
		current = parent;
	}
	return * this;
}

cardList::iterator& cardList::iterator::operator--() {
	if (!current) {
		current = tree -> maximum(tree->root);
		return *this;
	}
	if ( current->left)  { 
		current = current -> left ; 
		while ( current -> right ) {
			current = current -> right;
		}
	}
	else {
		Node* parent = current -> parent;
		while ( parent && current == parent -> left ) {
			current = parent;
			parent = parent -> parent ;
		}
		current = parent;
	}
	return *this;
}
cardList:: iterator cardList::begin() {
	return iterator(minimum(root),this);
}

cardList::iterator cardList::end() {
	return iterator(nullptr,this);
}
cardList::iterator cardList::rbegin() {
	return iterator(maximum(root),this);
}
cardList::iterator cardList::rend() {
	return iterator(nullptr,this);
}
	

