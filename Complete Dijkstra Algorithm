#include <bits/stdc++.h>
using namespace std;
#define inf 1LL<<62
#define mx 1000000
#define ll long long
vector<ll>g[mx];
vector<ll>cost[mx];
ll dis[mx], par[mx];

struct node
{
    ll city, dist;
    node(ll a, ll b){city = a, dist = b; }
    bool operator <(const node& p) const
    {
        return p.dist < dist;
    }
};

ll dijktra (ll src, ll des)
{
    for(ll i=0; i<mx; i++)dis[i]=inf;
    memset(par, -1, sizeof(par));
    priority_queue<node>q;
    dis[src]=0;
    q.push(node(src, 0));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        ll u = top.city;
        if(u==des) return dis[u];
        for(ll i=0; i<g[u].size(); i++){
            ll v = g[u][i];
            if(dis[u]+cost[u][i]<dis[v]){
                dis[v]= dis[u]+cost[u][i];
                par[v]= u;
                q.push(node(v,dis[v]));
            }
        }
    }
    return -1;
}

int main()
{
    ll node, egde;
    cin>>node>>egde;
    for(ll i=0; i<egde; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int res = dijktra(1,node);
    if(par[node]==-1){
        cout<<-1<<endl;
        return 0;
    }
    else{
        ll u =node;
        vector<ll>path;
        while(u!=-1){
            path.push_back(u);
            u = par[u];
        }
        reverse(path.begin(), path.end());
        for(auto it = path.begin(); it!= path.end(); it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
    for(ll i=0; i<mx; i++){
        g[i].clear();
        cost[i].clear();
    }
    return 0;
}
