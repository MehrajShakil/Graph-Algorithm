
///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.


///   Author : Md Mehraj Hossain
///   Tag :

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
/// order_of_key return number of elements less than x
/// find_by_order return index.

using namespace std;
using namespace __gnu_pbds;

#define ull      unsigned long long
#define ll       long long
#define ld       long double
#define pb       push_back
#define MOHAMMAD ios::sync_with_stdio(0);cin.tie(0);
#define ses      "\n"
#define all(x)   (x).begin(), (x).end()
#define pi       2*acos(0.0)
#define AE       cout << fixed << setprecision(10);

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=3e5+1;
const ll MOD = 1e9+7;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template < class T > inline T modinverse( T a,T M )
{
    return bigmod( a,M-2,M );   // when M is prime;
}

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/// Fast read.
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


//***********************************************  The END **********************************************************************************************************************************

/////////////////////////////////////////////////////////////////////////////

vector< ll > e[MAXN], cycle[MAXN];
ll color[MAXN], parent[MAXN];
ll white = 0, gray = 1,black = 2, cyclenumber = 0;

void dfs ( ll u, ll par )
{
    if(color[u]==black)
        return;

    if(color[u]==gray)
    {
        cyclenumber++;
        ll cur = par;
         cycle[cyclenumber].pb(cur);
        while(cur!=u)
        {
            cur = parent[cur];
            cycle[cyclenumber].pb(cur);
        }
        return;
    }
    parent[u] = par;
    color[u] = gray;

    for ( auto v : e[u] )
    {
        if(v==parent[u])
            continue;
        dfs ( v, u );
    }
    color[u] = black;

}




////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{

    /// MOHAMMAD

    ll node, edge, u, v;
    cin >> node >> edge;
    for ( ll i = 0 ; i<=node ; ++i )
        color[i] = white;

    while(edge--)
    {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    for ( ll i = 1 ; i<=node ; ++i )
    {
        if(color[i]==white)
        {
            dfs ( i, -1 );
        }
    }

    for ( ll i = 1 ; i<=node+10 ; ++i )
    {
        if(cycle[i].size())
        {
            for ( auto n : cycle[i] )
                cout << n << " ";
            cout << ses;
        }

    }

}

/*

6 7
1 2
2 3
1 3
4 1
4 5
5 6
6 4



  Alhamdulillah
*/

