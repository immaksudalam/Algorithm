#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&v, int l, int r){
	int pivot = v[r];
	int i = l -1;
	for(int j=l; j<r; j++){
		if(v[j]<=pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i+1], v[r]);
	return i+1;
}
void qsort(vector<int>&v, int l, int r){
	if(l>= r) return;
	int pi = partition(v, l, r);
	qsort(v, l, pi-1);
	qsort(v, pi + 1, r);
}
int main()
{
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	qsort(v, 0, n-1);
	for(int i=0; i<n; i++)cout<<v[i]<<" ";
}
