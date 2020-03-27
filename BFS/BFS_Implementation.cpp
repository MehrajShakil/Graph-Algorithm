#include<bits/stdc++.h>
using namespace std;
vector<int> edge[10000],d(10000);

int BFS(int src, int destination){
for(int i=0;i<10000;i++)d[i]=100000;
queue<int> q;
q.push(src);
d[src]=0;
while(q.size()>0){
          int u = q.front();
          q.pop();
          for(int v : edge[u]){
                if(d[v]>(d[u]+1)){
                d[v]=d[u]+1;
                q.push(v);
                }
          }
}
return d[destination];
}

int main(){
   int node,destination;
   cin>>node;
   while(node--){
       int a,b;
       cin>>a>>b;
       edge[a].push_back(b);
       edge[b].push_back(a);
   }
   cin>>destination;
   cout<<BFS(1,destination);
}
