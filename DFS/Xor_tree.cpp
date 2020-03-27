//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

#define ull    unsigned long long
#define ll    long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses   "\n"

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const int N=1e6+5;
const ll M=1e18;
/////////////////////////////////////////////////////////////////////////////
vector<ll> used,ans;
vector<ll>adj[100001];
void DFS(ll current_node,ll parent, ll given[], ll target[],ll need_to_flip_now,ll need_to_flip_my_child)
{
//cout<<"flip "<<need_to_flip_now<<ses;
    if(need_to_flip_now)
        given[current_node]^=1;
    if(given[current_node]!=target[current_node])
    {
        ans.push_back(current_node);
        need_to_flip_now^=1;
    }
    for(ll u=0; u<adj[current_node].size(); u++)
    {
        if(adj[current_node][u]!=parent)
        {
            //   cout<<adj[current_node][u]<<" "<<parent<<ses;
            DFS(adj[current_node][u],current_node,given,target,need_to_flip_my_child,need_to_flip_now);
        }
    }
}

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    ll node;
    cin>>node;
    ll edge=node-1;
    while(edge--)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll given[node+1],target[node+1];
    for(ll i=1; i<=node; i++)
        cin>>given[i];
    for(ll i=1; i<=node; i++)
        cin>>target[i];
    DFS(1,0,given,target,0,0);
    cout<<ans.size()<<ses;
    for(auto i : ans)
    {
        cout<<i<<ses;
    }
}





//Alhamdulillah
