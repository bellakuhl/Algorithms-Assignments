//
//  SkipList.h
//  Skip_List
//
//  Created by Tali Moreshet on 6/5/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//
//
//  This is an implementation of a Skip List class, consisting of Linked Lists, which are made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef SkipList_h
#define SkipList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
};

template <class T>
class SkipList {
public:
    SkipList(T minVal, T maxVal);                   // constructor: accepts -infinity, +infinity values,
                                                    //  creates skip list with top-level only
    ~SkipList();                                    // destructor
    Node<T>* search(T data);                        // search for data, return node <= data (existing node, or location
                                                    //  where new node should be inserted in the bottom-most list
    bool insert(T data);                            // insert node with data, return true if inserted, false if exists
    void printData();                               // prints skip list data
    void print();                                   // prints skip list with all nodes pointers
    LinkedList<T> *topList;                         // pointer to the top-most list
    int randomLevel();
};


/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/

template <class T>
void LinkedList<T>::print() {
	(this->head)->print();
	Node<T>* Nodecheck = this->head;
	while ((Nodecheck->next) != nullptr) {
		(Nodecheck->next)->print();
		Nodecheck = Nodecheck->next;
	}
}
template <class T>
LinkedList<T>::LinkedList(T minval, T maxval) {
	const T minva = minval;
	const T maxva = maxval;
	this->head = new Node<T> (minva);
	(this->head)->next = new Node<T>(maxva);
	(this->head)->prev = nullptr;
	((this->head)->next)->prev = this->head;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* Nodecheck = this->head;
	Node<T>* tempcheck = Nodecheck;
	while ((*Nodecheck).next != nullptr) {
		tempcheck = Nodecheck;
		Nodecheck = Nodecheck->next;
		delete tempcheck;
	}
}

template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data) {
	Node<T>* Nodecheck = location;
	while ((Nodecheck->next)->data < data) {
		Nodecheck = Nodecheck->next;
	}
	return Nodecheck;
}

template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data) {
	Node<T>* New_node = new Node<T>(data);//making new node
	New_node->next = location->next; //making the next of new node what comes after
	(location->next)->prev = New_node;
	New_node->prev = location;
	location->next = New_node;
	return nullptr;
}

template <class T>
void LinkedList<T>::printData() {
	(this->head)->printData();
	Node<T>* Nodecheck = this->head;
	while ((Nodecheck->next) != nullptr) {
		(Nodecheck -> next)->printData();
		Nodecheck = Nodecheck->next;
	}
}


/****** Skip List Implementation ******/

template <class T>
SkipList<T>::SkipList(T minval, T maxval) {   // Skip list constructor
	const T min = minval;
	const T max = maxval;
	this->topList = new LinkedList<T> (min, max);
}

template <class T>
SkipList<T>::~SkipList() {                  // Skip list deconstructor
  LinkedList<T>* currentList = this->topList;
  while(currentList != nullptr) {
    ~LinkedList();
    (this->topList)->down = currentList;   // point to next list down
  }
}

template <class T>
Node<T>* SkipList<T>::search(T data) {

}

template <class T>
bool SkipList<T>::insert(T data) {
  int heads = randomLevel();
  skiplist_node<T>* update[MAXLEVEL];
  NodeType* currNode = m_pHeader;
  for(int level=max_curr_level; level >=1; level--) {
      while ( currNode->forwards[level]->key < searchKey ) {
          currNode = currNode->forwards[level];
      }
      update[level] = currNode;
  }
  currNode = currNode->forwards[1];
  if ( currNode->key == searchKey ) {
      currNode->value = newValue;
  }
  else {
      int newlevel = randomLevel();
      if ( newlevel > max_curr_level ) {
          for ( int level = max_curr_level+1; level <= newlevel; level++ ) {
              update[level] = m_pHeader;
          }
          max_curr_level = newlevel;
      }
      currNode = new NodeType(searchKey,newValue);
      for ( int lv=1; lv<=max_curr_level; lv++ ) {
          currNode->forwards[lv] = update[lv]->forwards[lv];
          update[lv]->forwards[lv] = currNode;
      }
  }
}

template <class T>
int SkipList<T>::randomLevel() {
  int level = 1;
        double p = 0.5;
        while ( uniformRandom() < p) {
            level++;
        }
        return level;
}

template <class T>
void SkipList<T>::printData() {
  (this->topList)->printData();
	LinkedList<T>* currentList = this->topList;
	while ((currentList->next) != nullptr) {
		((currentList->head)->next)->printData();
		currentList = (currentList->topList)->next;
	}
}

template <class T>
void SkipList<T>::print(); {

}

#endif /* SkipList_h */
