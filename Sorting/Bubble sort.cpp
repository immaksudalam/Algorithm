/*
   1. First pass fix the right possition of largest element.
   2. Each pass fix the right possition of the remaining largest unplaced element.
   3. After n-1 iteration, array will be sorted.
   4. for complexity improvement, we can use a flag to track on swap needed or not.
      if any pass not required any swap, that means array already sorted.
      
   Complexity:
   Best Case: O(n) --- when array already sorted.
   Wrost Case: O(n^2) -- when array in reverse order.

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=0; i<n-1; i++){
		bool flag = false;
		for(int j=0; j<n-i-1; j++){
			if(v[j]>v[j+1]){
			   swap(v[j], v[j+1]);
			   flag = true;
			} 
		}
		if(!flag)break;
	}
	for(int i=0; i<n; i++)cout<<v[i]<<" ";
}
