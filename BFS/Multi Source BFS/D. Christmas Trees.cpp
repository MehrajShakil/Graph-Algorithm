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
const ll INF = 1e15;
const ll limit = (1LL<<64) - 1;

ll x[N+1] , ans = 0;
vector < ll > res;
map < ll , ll > covered , d , root;
queue < ll  > q;

int main()
{

  MOHAMMAD

  ll n , m;
  cin >> n >> m;

  for ( ll i = 0 ; i<n ; i++ ){
      cin >> x[i];
      d[x[i]] = 0;
      q.push ( x[i] ); /// Take every point as a source.
  }



  while ( q.size( ) ){

      if ( res.size() == m ) break;
      ll node = q.front();
      q.pop();
      
      if ( d[node]!=0 ){
          ans+=d[node];
          res.push_back( node ); 
      }
      if ( d.count ( node - 1 ) == 0 ){ /// If there is no people or tree at node - 1
            q.push( node - 1 );
            d[node - 1] = d[node] + 1;
      }
      if ( d.count( node + 1 ) == 0 ){  /// If there is no people or tree at node - 1
            q.push( node + 1 );
            d[node+1] = d[node] + 1;
      }
  }

  cout << ans << " \n";
  for ( auto  it : res ) cout << it << " ";





}


/*

Explanation:


 /// Multi source BFS.
TODO :
  1. https://www.spoj.com/problems/BITMAP/
  2. https://codeforces.com/contest/1283/problem/D
  3. https://codeforces.com/contest/986/problem/A
  4. https://codeforces.com/contest/1272/problem/E
  5. https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/



  Alhamdulillah
*/
