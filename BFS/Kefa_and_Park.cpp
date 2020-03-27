
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
const int M=(int)1e9+7;


/////////////////////////////////////////////////////////////////////////////
vector<ll> adj[100001];
map<ll,ll> mp,dis;

ll n,m,ans=0;
ll arr[100001];

ll BFS(int src){
mp[src]=1;
queue<ll> st;
st.push(src);

if(arr[src]==1){dis[src]=1;}
else dis[src]=0;

while(!st.empty()){
    ll v = st.front();
    st.pop();
    if(adj[v].size()==1 && dis[adj[v][0]]<=m && mp[adj[v][0]])ans++;
    for(ll u : adj[v]){
              if(!mp[u]){
                mp[u]=1;
                if(arr[u])dis[u]=dis[v]+1;
                else {dis[u]=0;}
                if(dis[u]<=m){st.push(u);}
              }
    }
}
return ans;
}
////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main(){
cin>>n>>m;
for(ll i=0;i<n;i++)cin>>arr[i];
n--;
while(n--){
                ll x,y;
                cin>>x>>y;
                x--,y--;
                adj[x].push_back(y);
                adj[y].push_back(x);
}
cout<<BFS(0);
}





//Alhamdulillah
