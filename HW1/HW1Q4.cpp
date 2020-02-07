// HW1Q4    Isabella Kuhl

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


void MergeFiles (int argc, char **argv) {
  ofstream out ("output.txt"); // output file
  ifstream file1;
  ifstream file2;
  string linef1; // line content of file1
  string linef2; // line content of file2
  int count = 0; // line count
  vector<string> contents; // array of merged file contents

  file1.open(argv[1]);
  file2.open(argv[2]);

  while (file1 >> linef1) {
    contents.push_back(linef1);
    count++;
  }

  while (file2 >> linef2) {
    contents.push_back(linef2);
    count++;
  }

sort(contents.begin(), contents.end());
for (int z = 0; z < count; z++) {
  out << contents[z] << endl;
}

  file1.close();
  file2.close();
  out.close();

}

int main(int argc, char **argv)
{
  MergeFiles(argc, argv);
  exit(1);
}
