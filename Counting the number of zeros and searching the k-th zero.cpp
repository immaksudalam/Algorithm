#include <bits/stdc++.h>
using namespace std;
#define maxsize 1005
int arr[maxsize];
int tree[4*maxsize];
int Merge(int a, int b){
    return a+b;
}

int find_kth_pos(int node, int L, int R, int k){

    if(k>tree[node])return -1;
    if(L==R) return L;
    int lefNode = node*2;
    int rightNode = node *2 +1;
    int mid = (L+R)/2;
    if(tree[lefNode]>=k){
        return find_kth_pos(lefNode, L, mid, k);
    }
    else {
        return find_kth_pos(rightNode, mid+1, R, (k-tree[lefNode]));
    }

}
void buildTree(int node, int left, int right){
     if(left == right){
        if(arr[left]==0)
        tree[node] = 1;
     else tree[node]=0;
        return;
     }
      int leftTree = 2*node;
      int rightTree = 2*node+1;
      int mid = (left + right)/2;
        buildTree(leftTree, left, mid);
        buildTree(rightTree, mid+1, right);
        tree[node]= Merge(tree[leftTree],tree[rightTree]);


}
int Query(int node, int L,int R , int l, int r)
{
    if(l>R || r<L) return 0;
    if(L>=l && R<=r) return tree[node];
    int leftNode = 2*node;
    int rightNode = 2*node +1;
    int mid = (L+R)/2;
    int x = Query(leftNode, L, mid, l, r);
    int y = Query(rightNode, mid+1, R,l,r);
    return Merge(x,y);
}
void Update(int node, int L, int R, int pos, int NewVal){
    if(pos>R || pos<L)return;
    if(L==pos && R==pos){
        if(NewVal==0) tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    int leftNOde = 2*node;
    int rightNode = 2*node +1;
    int mid = (L+R)/2;
    Update(leftNOde, L, mid, pos, NewVal);
    Update(rightNode,mid+1, R, pos, NewVal);
    tree[node] = Merge(tree[leftNOde], tree[rightNode]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    buildTree(1,1,n);
    for(int i=1; i<=(2*n)-1; i++){
        cout<<tree[i]<<" ";
    }cout<<endl;
   // Update(1,1,n,5,-200);
    int q;
    cin>>q;
    for(int i=1; i<=q; i++){
        int l,r;
        cin>>l>>r;
        cout<<Query(1,1,n,l,r)<<endl;
    }
    cout<<find_kth_pos(1,1,n,3)<<endl;
}

