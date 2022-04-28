/*
   1. Every time we take an element and place it in correct portion of sorted side.
   2. Array has two side, one is sorted, and another is unsorted.
   3. Every iteration we choose an element from unsorted portion and place it 
      correct position in sorted portion.
   4. time coplexity improved by the condition of when one element is not less than the left 
      element in sorted portion of the sorted list. then it achieve the right place of 
      sorted list.
   Time complexity: 
     1. Best case: O(n) - when array is already sorted and don't need need to iterate inner loop.
     2. Worst case: O(n^2)-- when array is in reverse order.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=1; i<n; i++){
		int j = i;
		while(v[j] < v[j-1] && j>=1){
			swap(v[j-1], v[j]);
			j--;
		}
	}
	for(int i=0; i<n; i++) cout<<v[i]<<" ";
}
