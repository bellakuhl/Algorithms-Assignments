// Isabella Kuhl 09/22/19
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sequences;  // holds all possible sequences
//int newBegin = 0;  // new start of subsequence
int first = 1;

void MaxIncSeq (int *nums, int len)
{
  static int initial_len = len;
  int *curr = nums;
  for (int seqNum = 0; seqNum < initial_len-1; seqNum++) {  // run for all possible sequences
    //while (1) {

        vector<int> seq_order = {nums[seqNum], nums[seqNum + 1]};   // start with first two elements

        if (initial_len == 1) {
          cout << *(nums) << endl;
          return;
        }
        else {
          while(1) {
              if (len == 1) {
                int seq_length = seq_order.size();
                curr++;
                nums = curr;
                first++;
                //cout << *curr <<endl;
                len = (initial_len - first);
                for (int n = 0; n <= seq_length - 1; n++) {
                  cout << seq_order[n] << " "; // print longest seq
                }
                cout << endl;
                break;
              }
            else {
              if (seq_order.back() > *(nums+1)) {
                if (seq_order[seq_order.size() - 1] < *(nums+1)) {
                  seq_order.back() = *(nums+1);
                }
                else if (seq_order[seq_order.size() - 1] > *(nums+1) && *(nums+1) > seq_order[seq_order.size() - 2]) {
                  seq_order.back() = *(nums+1);
                }
              }
              else if (seq_order.back() < *(nums+1)) {
                if (seq_order[seq_order.size() - 2] < *(nums+1)) {
                  if (seq_order.back() < seq_order[seq_order.size() - 2]) {
                    seq_order.back() = *(nums+1);
                  }
                  else {
                    seq_order.push_back(*(nums+1));
                  }
                }
              }
            }
            nums++;
            len--;
            //cout<<*nums<<endl;
          }
        }
        //break;
      //}
  }
    return;
}

int main()
{
    int arr[] = {7,4,1,10,23};
    int *nums = arr;
    int len = 5;
    //cout << *(nums) <<endl;
    MaxIncSeq(nums, len);
}
