/* Isabella Kuhl 11/20/19
/ This program implements Huffmans Algorithm. This can be used to encode
/ a given character array and decode a text file with an encoded message
/ corresponding to the Huffman tree */

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <queue>
#include <Huffman.h>

// Constructor
Node::Node(string text, int freq)
{
    this->text += text;
    this->freq = freq;
    this->left = nullptr;
    this->right = nullptr;
}

// Huffman Tree constructor
Huffman::Huffman()
{
 priority_queue <Node*, vector<Node*>, lessThanFreq> pq;
}

// Huffman Tree destructor
Huffman::~Huffman()
{
  while(this->pq.empty() == false)
  {
    Node *curr = pq.top();
    pq.pop();
    delete curr;
  }
}

// assigns leaf codes
void assignCodes(Node* root, string Huffcode)
{
    if (!root)
        return;

    if (root->text.length() == 1)
    {
      cout.width(19); cout << left << Huffcode << root->text << endl;
    }

    assignCodes(root->left, Huffcode + "0");
    assignCodes(root->right, Huffcode + "1");
}

// build huff tree
void Huffman::buildHuffmanTree(char text[], int freq[], int size)
{
  for (int i = 0; i < size; i++)
  {
    string s(1,text[i]);  // convert char to string
    pq.push(new Node(s, freq[i]));
  }

  Node* root; // root of tree
  Node* leftNode; // left node of tree
  Node* rightNode; // right node of tree
  while (pq.size() > 1) // build Huff tree until queue is empty
  {
    leftNode = pq.top();  // min frequency is left node
    pq.pop();
    rightNode = pq.top(); // next min frequency is right node
    pq.pop();
    string newText = leftNode->text + rightNode->text;  // combine node characters
    int newFreq = leftNode->freq + rightNode->freq; // combine node frequencies

    root = new Node(newText, newFreq);  // create new node with combined data
    root->left = leftNode;
    root->right = rightNode;

    pq.push(root);  // push new combined node to priority_queue
  }
}

// decodes text from endcoded text file
void Huffman::decodeText(const char *argv)
{
  ifstream file;
  string codedLine;
  string decodedText = "";  // decoded text from file
  file.open(argv);
  Node *root = pq.top();
  Node *curr = root;
  while (file >> codedLine)
  {
    for (int i=0; i<codedLine.length(); i++) // run through each digit in code
    {
      if (codedLine.at(i) == '0')
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
      if (curr->left == NULL && curr->right == NULL)  // if node is leaf
      {
        decodedText += curr->text;
        curr = root;  // start from beginning of Huff tree
      }
    }
    cout << "The decoded text is: " << decodedText << endl;
  }
}

// print codes in table format
void Huffman::printCodes()
{
  cout << "Huffman Code   Character" << endl;
  cout << "-------------------------" << endl;
  while (pq.empty() == false) {
    Node *curr = pq.top();
    assignCodes(curr, "");
    pq.pop();
  }
  cout << endl;
}
