/*
    Following divide and conquer algorithm we find the
    maximum sum subarray.
      1) Divide the array into two halves
      2) Return the maximum of following tree
           a) maximum subarray sum in left half (make a recursion call)
           b) maximum subarray sum in right half (make a recursion call)
           c) maximum subarray sum such that the subarray crosses the midpoint. (it can calculate the linear manner).
*/


#include <bits/stdc++.h>
using namespace std;
int maxCrossingSum(int arr[], int l,int mid, int r){
    int sum=0, left_sum= INT_MIN;
    for(int i=mid; i>=l; i--){
        sum+=arr[i];
        if(sum > left_sum) left_sum = sum;
    }
    sum=0;
    int right_sum=INT_MIN;
    for(int i=mid+1; i<=r; i++){
        sum+= arr[i];
        if(sum> right_sum) right_sum = sum;
    }
    return max(max(left_sum+right_sum, left_sum), right_sum);
}
int maxSubarraySum(int arr[], int l, int r){
    if(l==r)return arr[l]; // base case in recursion.
    int mid = (l+r)/2;
    int left_sum = maxSubarraySum(arr, l, mid);
    int right_sum = maxSubarraySum(arr, mid+1, r);
    int crossing_sum = maxCrossingSum(arr, l, mid, r);
    return max(max(left_sum, right_sum), crossing_sum);

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<maxSubarraySum(arr, 0, n-1)<<endl;
}

