#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 200000;
const ll INF = 1e18;
const ll mod = 1000000007;

/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector < ll > e[N + 1];
stack < ll > st;
bool visit[N + 1];
ll timer = 1 , tin[N + 1] , low[N + 1];

void dfs ( ll node , ll par ){
tin[node] = low[node] = timer++;
visit[node] = true;
st.push(node);
for ( auto child : e[node] ){
     if ( visit[child] ) {
         /// back edge.
         low[node] = min ( low[node] , tin[child] );
     }
     else if ( tin[child]==-1 ){
         dfs ( child , node );
         low[node] = min ( low[node] , low[child] );
     }
}

  if(low[node]==tin[node]){
     cout << "SCC : ";
     while( st.top()!=node ){
           cout << st.top() << " ";
           visit[st.top()] = 0;
           st.pop();
     }
      cout << st.top() << "\n";
      visit[st.top()] = 0;
      st.pop();
  }
}

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset ( tin , -1 , sizeof tin );

  ll node , edge , u ,v;
  cin >> node >> edge;

  while ( edge-- ){
       cin >> u >> v;
       e[u].push_back( v );
  }

  for ( ll i = 0 ; i<node ; ++i ){
      if ( tin[i]!=-1 ) continue;
      dfs ( i , -1 );
  }
}



/*

11 17
0 1
0 3
1 2
1 4
2 0
2 6
3 2
4 5
4 6
5 6
5 7
5 8
5 9
6 4
7 9
8 9
9 8





  Alhamdulillah
*/
