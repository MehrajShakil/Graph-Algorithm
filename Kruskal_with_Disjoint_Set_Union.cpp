
//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Allah amader korona virus theke rokkha korun.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll    long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses   "\n"
#define all(x) (x).begin(), (x).end()
//#define INF   ((int)2e18)
#define ii pair<ll, ll>

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const int N=1e6+5;
const ll M=1e18;

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

struct Edge {int u, v , weight ;bool operator<(Edge const& other) {return weight < other.weight;}}; // eta joss jinis.krsukal er jnno and sort 1 out of 3 or more er jnno better

/////////////////////////////////////////////////////////////////////////////
vector<Edge> e;
vector<ll>parent,Size;

void makeSet(int n)
{
    parent[n]=n;
    Size[n] = 1;
}

int Find(int reprasentative)
{
    if (parent[reprasentative] == reprasentative)
    {
        return reprasentative;
    }
    return parent[reprasentative] = Find(parent[reprasentative]);
}

void Union(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
    {
            if (Size[a] < Size[b])
                swap(a, b);
                parent[b]=a;
                Size[a]+=Size[b];
   }
}

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
 ll node,edge,cost=0;
 cin>>node>>edge;
 parent.resize(node+1);
 Size.resize(node+1);
 for(ll i=1;i<=node;i++)makeSet(i);
 for(ll i=1;i<=edge;i++){
                ll u,v,weight;
                cin>>u>>v>>weight;
                //Union(u,v);
                Edge get;
                get.u=u;
                get.v=v;
                get.weight=weight;
                e.push_back(get);
 }
sort(all(e));
for(Edge i : e){
        if(Find(i.u)!=Find(i.v)){
                cost+=i.weight;
                Union(i.u,i.v);
        }
}
cout<<cost;
}

/*

8 11

1 2 4
1 5 2
1 4 10
2 4 8
2 3 18
5 4 5
3 4 11
4 7 11
4 8 9
8 6 2
7 6 1

*/



//Alhamdulillah
