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
#define AE        cout << fixed << setprecision(10);

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
const ll N = 50;
const ll INF = 1e15;
const ll limit = (1LL<<64) - 1;

char grid[N+1][N+1];
ll low[N+1][N+1] , tin[N+1][N+1];
bool visit[N+1][N+1];
ll n , m , timer = 0;
bool articulationPoint = false;
void dfs ( ll x , ll y , ll parx = -1 , ll pary = -1 ){

visit[x][y] = true;
low[x][y] = tin[x][y] = timer++;
ll children = 0;
for ( ll k = 0 ; k < 4 ; ++k ){
     ll xx = x + dx4[k];
     ll yy = y + dy4[k];
     if ( xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]=='.' or ( xx == parx and yy == pary ) ) continue;
     if ( visit[xx][yy] ){ /// back edge
         low[x][y] = min ( low[x][y] , tin[xx][yy] );
     }
     else{
         dfs ( xx , yy , x , y );
         low[x][y] = min ( low[x][y] , low[xx][yy] );
         if ( tin[x][y]<=low[xx][yy] and parx!=-1 and pary!=-1 ) articulationPoint = true;
         children++;
     }
}
 if ( children >1 and parx == -1 and pary == -1 ) articulationPoint = true;
}


int main()
{

  MOHAMMAD
  cin >> n >> m;

  for ( ll i = 0 ; i<n ; ++i ){
       for ( ll j = 0 ; j<m ; ++j ) cin >> grid[i][j];
  }

  for ( ll i = 0 ; i<n ; ++i ){
       for ( ll j = 0 ; j<m ; ++j ){
            if ( visit[i][j] or grid[i][j]=='.' ) continue;
            dfs ( i , j );
       }
  }
  bool ok = true;
  for ( ll i = 0 ; i<n ; i++ ){
      for ( ll j = 0 ; j<m ; ++j ){
           ll temp = 0 ,  dot = 0;
           if ( grid[i][j]=='#' ){
              for ( ll k = 0 ; k<4 ; ++k ){
                   ll xx = i + dx4[k];
                   ll yy = j + dy4[k];
                   if ( xx<0 or xx>=n or yy<0 or yy>=m ) continue;
                   if ( grid[xx][yy]=='#' ) dot++;
                   temp++;
                }
           }
           if ( dot>1 ) ok = false;
      }
  }
  if ( ok ) cout << -1 << "\n";
  else if ( articulationPoint ) cout << 1 << "\n";
  else cout << 2 << "\n";



}


/*







  Alhamdulillah
*/
