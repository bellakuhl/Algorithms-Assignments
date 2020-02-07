// Isabella Kuhl 09/22/19
#include <iostream>
#include <vector>
using namespace std;

int first = 0;

void MaxIncSeq (int *nums, int len)
{
  static vector<int> seq_order = {nums[first], nums[first + 1]};
  static int end = nums[len-1];
  static int initial_len = len;

  if (initial_len == 1) {
    cout << *(nums) << endl;
    return;
  }
  else {
      if (len == 1) {
        int seq_length = seq_order.size();
        for (int n = 0; n <= seq_length - 1; n++) {
          cout << seq_order[n] << " "; // print longest seq
        }
        cout << endl;
        return;
      }
    else {
      if (*(nums) == end && *(nums) > seq_order.back() ) {
        seq_order.push_back(*(nums));
        return;
      }
      else if (*(nums) == end && *(nums) <= seq_order.back()) {
        return;
      }
      else if (seq_order.back() > *(nums+1)) {
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
      MaxIncSeq(nums+1, len-1);
    }
  }
  return;
}

int main()
{
    int arr[] = {7,4,1,10,23,2};
    int *nums = arr;
    int len = 6;
    MaxIncSeq(nums, len);
}
