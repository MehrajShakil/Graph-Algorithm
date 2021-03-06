///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MOHAMMAD  ios::sync_with_stdio(0);cin.tie(0);
#define all(x)    (x).begin(), (x).end()
#define AE        cout << fixed << setprecision(2);


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

using ll = long long;
const ll MOD = 1e9 + 7;

typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//***********************************************  The END **********************************************************************************************************************************
const ll N = 2e5;
const ll INF = 1e18 + 1;
const ll limit = (1LL<<64) - 1;

vector < pair < ll , ll > > e[N+1];
queue < ll > odd , even;
ll arr[N+1] , depeven[N+1] , depodd[N+1] , dep[N+1];

void bfs1 ( ){
  while ( odd.size() ){
       ll node = odd.front();
       odd.pop();
       for ( auto child : e[node] ){
            ll go = node;
            if ( child.second == 1 ){
               go+=child.first;
            }
            else{
               go-=child.first;
            }
            ll par = arr[go] % 2;
            if ( par==1 ) continue;
            if ( depodd[node] + 1 < depodd[go] ){
                depodd[go] = depodd[node] + 1;
                odd.push ( go );
            }
       }
  }
}

void bfs2 ( ){
  while ( even.size() ){
       ll node = even.front();
       even.pop();
       for ( auto child : e[node] ){
            ll go = node;

            if ( child.second == 1 ){
               go+=child.first;
            }
            else{
               go-=child.first;
            }
            ll par = arr[go] % 2;
            if ( par==0 ) continue;
            if ( depeven[node] + 1 < depeven[go] ){
                depeven[go] = depeven[node] + 1;
                even.push ( go );
            }
       }
  }
}


int main()
{

  MOHAMMAD

  ll n;
  cin >> n;
  for ( ll i = 1 ; i<=n ; i++ ) {
     cin >> arr[i];
     ll l = i - arr[i];
     ll r = i + arr[i];
     if ( l>0 ){
        e[l].push_back ( { arr[i] , 1 } ); /// I can go from l to l + arr[i].
     }
     if ( r<=n ){
        e[r].push_back ( { arr[i] , 0 } ); /// I can go from r to r - arr[i].
     }
     if ( arr[i]&1 ) odd.push( i ) , depodd[i] = 0 , depeven[i] = INF;  /// I try to go odd number to even number with minimum number of moves.
     else even.push( i ) , depodd[i] = INF , depeven[i] = 0; /// For, even to odd.
  }

  bfs1 ( ); /// bfs1 compute the min distance from odd to even.

  for ( ll i = 1 ; i<=n ; ++i ){
       if ( arr[i]%2==0 ){
           if ( depodd[i]==INF ) dep[i] = -1;
           else dep[i] = depodd[i];
       }
  }

   bfs2 ( ); /// bfs2 compute the min distance from even to odd.

  for ( ll i = 1 ; i<=n ; ++i ){
       if ( arr[i]%2==1 ){
           if ( depeven[i]==INF ) dep[i] = -1;
           else dep[i] = depeven[i];
       }
  }

  for ( ll i = 1 ; i<=n ; ++i ){
       cout << dep[i] << " ";
  }
}


/*

Explanation:


 /// Multi source BFS.
TODO :
  1. https://www.spoj.com/problems/BITMAP/
  2.
  3.
  4. 
  5. https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/



  Alhamdulillah
*/
