//
//  HopScotchHashTable.h
//  HopScotchHashTable
//
//  Created by Tali Moreshet on 6/14/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//

#ifndef HopScotchHash_h
#define HopScotchHash_h

#include <iostream>
#include <vector>

using namespace std;

const int MAX_DIST = 4; // The maximum number of probes in a probe sequence

class HashEntry     // A hash table entry
{
public:
    string item;      // item to store
    int key;          // used to determine the corresponding hash value of the item
    int hop;          // hop bitmap field
    bool isActive;    // does this entry contain an item or is it empty
};

class HopScotchHash
{
private :
    vector<HashEntry> table;
    int myHash(const int & x) const;    // division hash: (key) mod (table size))
    bool shiftDown(int home, int open, HashEntry & x);  // make room for new hash entry x, where:
                                                        //  home - desired location for x (e.g. the hash value of x)
                                                        //  open - closest open location to home

public :
    HopScotchHash(int size);           // constractor for an empty hash table of the specified size
    bool insert(HashEntry & x);        // insert item x to the table
    void printContent();               // print the content of the table
};

#endif /* HopScotchHash_h */
