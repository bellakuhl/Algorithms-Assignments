/* Isabella Kuhl 09/25/19
Program that finds and prints the longest increasing sequence by cloning
and extending a sequence based on original array, then compares previous values and discards
the old subsequence. The result is the longest subsequence.
Reference: https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem */
#include <iostream>
#include <vector>
using namespace std;

void MaxIncSeq(int *nums, int len)
{
	vector<vector<int> > sequence(len);  // subsequence is at MOST as long as the total length
  vector<int> longestSeq;  // will hold longest seq

	sequence[0].push_back(nums[0]);  // initialize the first element to be the beginning of the sequence

	for (int i = 1; i < len; i++)	{  // index through starting at 1
		for (int j = 0; j < i; j++) {  // previous value index
			if ((*(nums+i) > *(nums+j)) && (sequence[i].size() < sequence[j].size() + 1)) { // compare previous values
				sequence[i] = sequence[j];  // replace previous value only if current value is larger AND current size
      }
		}
		sequence[i].push_back(*(nums+i));  // add next value to sequence
	}

	longestSeq = sequence[0];  // longest sequence starts with first element of subsequence

  for (vector<int> currentSeq : sequence) {  //  run through each element and compare
    if (currentSeq.size() > longestSeq.size()) {
      longestSeq = currentSeq;
    }
  }

	for (int p = 0; p < longestSeq.size(); p++) {  // print elements of longestSeq
    cout << longestSeq[p] << " ";
  }
  cout << endl;
  return;
}
/*
int main()
{
	int arr[] = {1,5,3,2,4};
  int *nums = arr;
  int len = 5;
	MaxIncSeq(nums, len);
}*/
