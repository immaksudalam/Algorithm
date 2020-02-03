#include <bits/stdc++.h>
using namespace std;
#define maxsize 1005
int arr[maxsize];
int tree[4*maxsize];
int Merge(int a, int b){
    return a+b;
}

int find_position(int node, int L, int R, int x){ //position can greater or equal of x

    if(x>tree[node])return -1;
    if(L==R) return L;
    int lefNode = node*2;
    int rightNode = node *2 +1;
    int mid = (L+R)/2;
    if(tree[lefNode]>=x){
        return find_position(lefNode, L, mid, x);
    }
    else {
        return find_position(rightNode, mid+1, R, (x-tree[lefNode]));
    }

}
void buildTree(int node, int left, int right){
     if(left == right){
        tree[node] = arr[left];
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
        tree[node] = NewVal;
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
    for(int i=1; i<=(4*n); i++){
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
    int x;
    cin>>x;
    cout<<find_position(1,1,n,x)<<endl;
}


