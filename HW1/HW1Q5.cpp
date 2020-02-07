// Homework 1 Question 5 Isabella Kuhl 09/14/2019
#include <iostream>
#include <string>

using namespace std;

void strXpos (char *dest, const char *src) {
  if (*(src + 1) == '\0') {
    dest[0] = src[0];
    dest[1] = src[1];
    return;
  }
  else if (*(src) == '\0') {
    dest[0] = src[0];
    return;
  } else {
    char prev = src[0];
    dest[0] = src[1];
    dest[1] = prev;
    strXpos(dest + 2, src + 2);
  }
}


/*int main (int argc, char **argv) {
  char dest[200];
  string test = "12345";
  const char *test2 = test.c_str();
  strXpos(dest, test2);
  cout << dest << endl;
}*/
