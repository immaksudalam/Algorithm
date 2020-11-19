#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int temp[], int left, int mid, int right){
    int i,j,k;
    i = left; // i to locate first array location
    j = mid; // i to locate second array location
    k = left; // i to locate merged array location

    while((i<= mid -1) && (j<= right)){
        if(arr[i] <= arr[j]){ // when left item is less than right item
            temp[k++] = arr[i++];

        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<= mid -1){ // if first list has remaining item, add them in temp array
        temp[k++]= arr[i++];
    }
    while(j <= right){ // if second list has remaining item, add them in temp array
        temp[k++]= arr[j++];
    }
    for(int i= left; i<=right; i++){
        arr[i]=temp[i];// store temp array to main array.
    }
}
int mergeSort(int arr[], int temp[], int left, int right){
    int mid;
    if(right > left){
        mid = (left+right)/2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid+1, right);
    }

}
int arrInversion(int arr[], int n){
    int temp[n];
    return mergeSort(arr, temp, 0, n-1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    arrInversion(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
