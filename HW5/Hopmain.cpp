//
//  main.cpp
//  HopScotchHashTable
//
//  Created by Tali Moreshet on 6/14/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "HopScotchHash.h"

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream inFile("/Users/talim/Courses/EC330/HW/HW5/input.txt");

    if (!inFile.is_open())
    {
        cout << "Can't open file";
        return -1;
    }

    string item;
    int key;
    HopScotchHash hopScotchHash(17);


    while (inFile >> item >> key)
    {
        cout << item << ":" << key << endl;

        HashEntry hashEntry;
        hashEntry.item = item;
        hashEntry.key = key;

        hopScotchHash.insert(hashEntry);
    }

    inFile.close();

    /*int keys[] = {7, 9, 6, 7, 8, 12, 11, 9, 6};
    string items[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    HopScotchHash hopScotchHash(17);

    for (int i=0; i<9; i++)
    {
        HashEntry newEntry;
        newEntry.key = keys[i];
        newEntry.item = items[i];
        hopScotchHash.insert(newEntry);
    }*/

    hopScotchHash.printContent();

    return 0;
}
