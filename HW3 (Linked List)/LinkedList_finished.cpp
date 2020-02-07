//  Completed by Wooyoung Cho & Isabella Kuhl 10/02/19
//  LinkedList.h
//  Linked_List
//
//  Created by Tali Moreshet on 6/5/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef LinkedList_h
#define LinkedList_h

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

// Linked List constructor
template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal)
{
    Node<T>* min = new Node<T>(minVal);
    Node<T>* max = new Node<T>(maxVal);
    this->head = min;
    min->next = max;
    min->prev = nullptr;
    max->prev = min;
    max->next = nullptr;
}

// Searches for location of data
template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data)
{
    Node<T> *curr = location;
    Node<T> *right;
    while (curr != nullptr) {
        right = curr->next;
        if (curr->data == data) {  // checks to see if data is in list
          return curr;
        }
        else if (curr->data > data) {  // checks for location of ordered data
          return curr->prev; // why previous pointer?
        }
        curr = right; // move current position forward
    }
    return curr;
}

// Inserts data at specified location
template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data)
{
    Node<T> *curr = location;
    Node<T> *right;
    right = curr->next;

    Node<T>* newNode = new Node<T>(data);  // insert node
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = right;
    right->prev = newNode;
    return newNode;
}

template <class T>
void LinkedList<T>::printData()
{
  Node<T> *curr = this->head;
  //curr->printData();
  while (curr->next != nullptr) {
    curr->printData();
    curr = curr->next;
  }
}

template <class T>
void LinkedList<T>::print()
{
  Node<T> *curr = this->head;
  //curr->print();
  while (curr->next != nullptr) {
    curr->print();
    curr = curr->next;
  }
}

#endif /* LinkedList_h */
