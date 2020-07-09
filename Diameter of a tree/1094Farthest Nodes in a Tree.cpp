///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.

/// Tag:: graph

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
//***********************************************  The END **********************************************************************************************************************************
using ll = long long;
const ll N = 3e4 + 1;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

vector < ll > e[N],cost[N];
map < pair < ll , ll > , ll > mp;
ll  weight[N];
bool vis[N];

void dfs ( ll node ){

   vis[node] = true;

   for ( ll i = 0 ; i<e[node].size() ; ++i ){
         ll child = e[node][i];
         if ( !vis[child] ){
             weight[child] = weight[node] + cost[node][i];
             dfs ( child );
         }
    }
}

void solve ( ll tc ){

  ll node , edge , u , v , we;
  cin >> node;
  edge = node - 1;

  while ( edge-- ){
      cin >> u >> v >> we;
      e[u].push_back (v);
      e[v].push_back (u);
      cost[u].push_back( we );
      cost[v].push_back ( we );
  }

  dfs ( 1 );

  ll mxdistance = -1 , X , mx = 0 , maxi = 0;

  for ( ll i = 0 ; i<node ; ++i ){
       if ( mxdistance<weight[i] ){
           mxdistance = weight[i];
           X = i;
       }
       vis[i] = weight[i] = 0;
  }

  dfs ( X );

  for ( ll i = 0 ; i<node ; ++i ){
       if ( weight[i]>maxi ){
          maxi = max ( maxi , weight[i]);
       }
  }

  cout << "Case " << tc << ": " << maxi << "\n";

}

void init ( ){

  for ( ll i = 0 ; i<N ; ++i ) {
       e[i].clear();
       cost[i].clear();
       vis[i] = false;
       weight[i] = 0;
  }

}


int main()
{

  MOHAMMAD

  ll t , tc = 0;
  cin >> t;
  while ( t-- ){
         init ( );
         solve ( ++tc );
  }

}


/*





  Alhamdulillah
*/

