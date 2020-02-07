//
//  main.cpp
//  Linked_List
//
//  Created by Tali Moreshet on 6/5/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include "LinkedList_finished.h"

int main(int argc, const char * argv[]) {

  /* Uncomment */
  LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
  Node<int> *newNodeLoc;

  newNodeLoc = myLL->search(myLL->head, 3);
  myLL->insert(newNodeLoc, 3);
  newNodeLoc = myLL->search(myLL->head, 1);
  myLL->insert(newNodeLoc, 1);
  newNodeLoc = myLL->search(myLL->head, 2);
  myLL->insert(newNodeLoc, 2);

  cout << "Linked list data: \n";
  myLL->printData();

  cout << "\n Linked List entire content: \n";
  myLL->print();


    return 0;
}
