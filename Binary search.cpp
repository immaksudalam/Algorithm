#include <bits/stdc++.h>
using namespace std;
bool binary_search(int arr[], int n, int x){
    int left =0, right = n-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid]==x){
            return true;
        }
        if(arr[mid] < x){
            left = mid+1;
        }
        else right = mid -1;
    }
    return false;
}
int main()
{
    int arr[] ={ 1, 3, 4 , 7, 9};
    int x;
    cin>>x;
    if(binary_search(arr, 5, x)) cout<<"found"<<endl;
    else cout<<"Not found"<<endl;
}
