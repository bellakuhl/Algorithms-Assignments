/*  Isabella Kuhl
*   10/27/19
*   Cpp code to initialize a hopscotch hash table
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include "HopScotchHash.h"

// Hopscotch Hash constructor
HopScotchHash::HopScotchHash(int size)
{
  vector<HashEntry> hashTable; // create vector of hash entries
  for (int i = 0; i < size; i++)
  {
    HashEntry *curr = new HashEntry; // pointer for each hash entry
    curr->item = "0";
    curr->hop = 0;
    curr->key = i;
    curr->isActive = false;
    hashTable.push_back(*curr);
  }
  this->table = hashTable;
}

// Accepts a hash key, and returns its hash value, using division hash
int HopScotchHash::myHash(const int & x) const
{
  int key;
  int size = table.size();
  if (x < 0)
  {
    key = size + x;
  }

  else
  {
    key = x % size;
  }

  return key;
}

// insert hash entry
bool HopScotchHash::insert(HashEntry & x)
{
  int key = myHash(x.key);
  if (table[key].isActive == false)
  {
    table[key].item = x.item;
    table[key].hop ^= 1 << 0; // change first bit to 1 i.e 0000 -> 1000
    table[key].isActive = true;
    return true;
  }
  else
  {
    int nextOpen = key;
    while(table[nextOpen].isActive == true) // find next open spot
    {
      nextOpen++;
    }
    shiftDown(key, nextOpen, x);
    return false;
  }
}

// moves elements in hash to fit in hash entry x
bool HopScotchHash::shiftDown(int home, int open, HashEntry & x)
{
  if (table[open].isActive == false && (open - home) < MAX_DIST)  // if open spot isn't filled, place new item in
  {
    table[open].item = x.item;
    table[open].isActive = true;
    table[home].hop ^= 1 << (open-home);
    return true;
  }
  else // if open spot is too far from home and / already filled
  {
    int maxIndex = open - (MAX_DIST - 1); // start looking from MAX_DIST from open spot
    int candidateIndex = maxIndex;
    int bitNum;

    while (open > maxIndex)
    {
      for (int i = 0; i < (MAX_DIST-1); i++)  // check every bit for a 1 except the last one
      {
        if (((table[maxIndex].hop >> i) & 1) == 1)  // if you find a 1, the hash corresponding to that bit is the candidate
        {
          candidateIndex = maxIndex + i;
          bitNum = i; // get bit number corresponding to candidate
          goto exit;  // then exit from while loop
        }
      }
      maxIndex++;
    }

    exit:
    table[open].item = table[candidateIndex].item;  // place candidate item in open spot
    table[open].isActive = true;
    table[maxIndex].hop ^= 1 << (open - maxIndex); // change bit map of candidate hash since item has moved
    table[maxIndex].hop ^= 1 << bitNum;

    if ((candidateIndex - home) < MAX_DIST)
    {
      table[candidateIndex].item = x.item;  // replace candidate with new item
      table[home].hop ^= 1 << (candidateIndex - home);  // update home bitmap
      return true;
    }
    else
    {
      shiftDown(home, candidateIndex, x);
    }
  }
}

void HopScotchHash::printContent()
{
  cout << "Index  " << "Item    " << "Hop" << endl;
  vector<HashEntry>::const_iterator it;
  for (it = table.begin(); it != table.end(); it++)
  {
    cout << it->key << "       ";
    if (it->item == "0")
    {
      cout << "-     ";
    }
    else
    {
      cout << it->item << "     ";
    }
    for (int i = 0; i < 4; i++)
    {
      cout << ((it->hop >> i) & 1);
    }
    cout << endl;
  }
}
