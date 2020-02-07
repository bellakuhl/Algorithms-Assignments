#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int matchCount = 0;
int wordCount = 0;
int panCount = 0;

void fourA()
{
  ifstream inFile("BigData.txt");
  int hash = 0;
  string ID = "";
  vector<int> IDhashes;
  string text;
  bool unique = true;

  if (!inFile.is_open())
  {
      cout << "Can't open file";
      return;
  }
  while (getline(inFile, text))
  {
    if (text.length() < 9)  /* check if text is a viable length for ID*/
    {
      continue;
    }
    else
    {
      for (int i = 0; i <= text.length()-9; i++)
      {
	ID = "";
	hash = 0;
	unique = true;
	bool IDbool = false;
        if (text.at(i) == 'U')
        {
	  ID += 'U';
          int j = i+1;
          for (j = i+1; j<i+9; j++) /*check first 8 values after 'U'*/
          {
            if (text.at(j) >= 48 && text.at(j) <= 57) /*check if value is a digit*/
            {
	      ID += text.at(j);
            }
          }
          if (j=i+9)  /*check if 8 digits followed 'U'*/
          {

	     for (int z=0; z <= ID.size(); z++)
	     {
		hash = (256 * hash + ID[z])% 101;
	     }
	     if (IDhashes.size() == 0)
	     {
		IDhashes.push_back(hash);
	     }
	     else
	     {
		for (int p=0; p < IDhashes.size();p++)
		{
		  if (IDhashes[p] == hash)
		  {
		     unique = false;
		  }
		  else
		  {
		     unique = true;
		  }
		}
		if (unique == true)
		{
		  IDhashes.push_back(hash);
		  matchCount = IDhashes.size();
		}
	     }
          }
        }
      }
    }
  }
  cout << "ID count: " << matchCount << endl;
  inFile.close();
}

void fourB()
{
  wordCount++;
  ifstream inFile("BigData.txt");
  string text;
  if (!inFile.is_open())
  {
      cout << "Can't open file";
      return;
  }
  while (getline(inFile,text))
  {
    for (int i = 0; i < text.length(); i++)
    {
      bool word = true;
      if (isspace(text.at(i)) != 0) /* look for delimiters, and consider start of line to be new word*/
      {
        int j = i+1;
        word = true;
        while (isspace(text.at(j)) == 0 && j < text.length()-1) /*check for delimiter i.e ' ', '  ', '\0'*/
        {
          if ((text.at(j) >= 65 && text.at(j) <= 90) || (text.at(j) >= 97 && text.at(j) <= 122)) /*check if value is a letter*/
          {
            j++;  /* check next character */
          }
          else
          {
            word = false; /* if not a letter, change flag*/
          }
        }
        if (j > i+1 && word == true) /*check that "word" is not just two consecutive delimiters*/
        {
          wordCount++;
        }
      }
    }
  }
  inFile.close();

}

bool checkPangram ()
{
  ifstream inFile("test.txt");
  string text;
  vector<bool> mark(26, false);
  int index;
  string sentence="";
  string pangram="";

  if (!inFile.is_open())
  {
      cout << "Can't open file";
      return 1;
  }
  while (inFile >> text)
  {
    for (int p=0; p < text.length(); p++)
    {
      sentence +=tolower(text.at(p));
    }
  }

  for (int i = 0; i < sentence.length(); i++)
  {
    /*if (pangram == "" && sentence.length() - i >= 25)
    {
      for (int t=0; t<26; t++)
      {
        pangram += sentence.at(i+t);
      }
    }*/
    for (int j=i+1; j<sentence.length()-2; j++)
    {
      pangram += sentence.at(j);
      for (int b=0; b<pangram.length(); b++)
      {
          if('a' <= pangram[b] && pangram[b] <= 'z')
              index = pangram[b] - 'a';
          mark[index] = true;
      }
      for (int i=0; i<=25; i++)
          if (mark[i] == false)
            {  panCount++;
              pangram = "";
            }
      pangram += sentence.at(i);
    }
  }
}

void fourC()
{
  ifstream inFile("BigData.txt");

  if (!inFile.is_open())
  {
      cout << "Can't open file";
      return;
  }

  string sentence = "";
  string text;
  string pangram = "";
  int letterCount = 0;
  bool done = false;
  if (inFile)
  {
    while (inFile >> text)
    {
        sentence.append(text);
    }
    for (int i=0; i < sentence.length()-1; i++)
    {
	letterCount = 0;
        int j=i+1;
        while (done == false && j < sentence.length() -2)
        {
          pangram += sentence.at(j);
	  if (pangram.length() >= 26)
	  {
          for (int x = 0; x < 26; x++)
          {
            if ((pangram.find('A' + x) !=string::npos) || (pangram.find('a'+x) != string::npos))  /* look for letters */
            {
              letterCount++;
            }
          }
	  if (letterCount >=23)
	  {
	    panCount++;
	    pangram = "";
	    letterCount = 0;
	    done = true;
	  }
	}
	j++;
        }
      }
    }
  inFile.close();
}

int main(int argc, const char * argv[])
{
  checkPangram();
  cout <<panCount<<endl;
}
