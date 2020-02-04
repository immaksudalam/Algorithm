#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
int arr[MAX];

struct data{
   int sum, pref, suff, ans;
};
data Tree[4*MAX];
data Combine(data l, data r)
{
    data result;
    result.sum =l.sum + r.sum;
    result.pref = max(l.pref, (l.sum+r.pref));
    result.suff = max(r.suff,(r.sum+l.suff));
    result.ans = max(max(l.ans,r.ans),(l.suff+r.pref));
    return result;
}

data make_data(int val){
    data result;
    result.sum = val;
    result.pref = result.suff=result.ans = max(0,val);
    return result;
}

void build(int node, int L, int R){
    if(L==R){
        Tree[node] = make_data(arr[L]);
        return;
    }
    int leftNode = 2*node;
    int rightNode = 2*node +1;
    int mid = (L+R)/2;
    build(leftNode,L,mid);
    build(rightNode,mid+1, R);
    Tree[node] = Combine(Tree[leftNode],Tree[rightNode]);

}

void Update(int node, int L, int R, int pos, int newVal)
{
    if(pos>R || pos<L)return;
    if(pos == L && pos == R){
        Tree[node] = make_data(newVal);
        return;
    }
    int leftNOde = 2*node;
    int rightNode = 2*node +1;
    int mid = (L+R)/2;
    if(pos<=mid)
        Update(leftNOde, L, mid, pos, newVal);
    else
        Update(rightNode, mid+1, R, pos, newVal);
    Tree[node] = Combine(Tree[leftNOde], Tree[rightNode]);
}

data query(int node, int L, int R, int l, int r){
    if(l>r) return make_data(0);
    if(l==L && r==R) return Tree[node];
    int leftNOde = 2*node;
    int rightNode= 2*node+1;
    int mid = (L+R)/2;
    data x = query(leftNOde, L,mid, l,min(r,mid));
    data y = query(rightNode, mid+1, R, max(l,mid+1), r);
    return Combine(x,y);

}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    for(int i=1; i<=q; i++){
        int l,r;
        cin>>l>>r;
        data a = query(1,1,n,l,r);
        cout<<a.ans<<endl;
    }

}
