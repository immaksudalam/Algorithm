#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int l, int mid, int r){
	int n1 = mid - l +1;
	int n2 = r - mid;
	vector<int>larray(n1), rarray(n2);
	for(int i=0; i<n1; i++){
		larray[i] = v[l + i];
	}
	for(int j=0; j<n2; j++){
		rarray[j] = v[mid + 1 + j];
	}
	int i=0, j=0, k = l;
	while(i < n1 && j< n2){
		if(larray[i]<= rarray[j]){
			v[k] = larray[i];
			i++;
		}
		else{
			v[k]= rarray[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		v[k] = larray[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k] = rarray[j];
		j++;
		k++;
	}
}
void mergesort(vector<int>&v, int l, int r){
	if(l>= r) return;
	int mid = (l + r)/2;
	mergesort(v, l, mid);
	mergesort(v, mid+1, r);
	
	merge(v, l, mid, r);
}
int main()
{
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	mergesort(v, 0, n-1);
	for(int i=0; i<n; i++) cout<<v[i]<<" ";
}
