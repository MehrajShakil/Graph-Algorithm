#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector< pair<int,int> > adj[10000];
vector<int> d,p;

void dijkstra(int s) {
    int n = 10000;
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    cout<<d[5]<<endl;
}
int main(){
int node;
cin>>node;
while(node--){
 int a,b,cost;
 cin>>a>>b>>cost;
 adj[a].push_back(make_pair(b,cost));
 adj[b].push_back(make_pair(a,cost));
}
dijkstra(1);
}
