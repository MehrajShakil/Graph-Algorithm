#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g,gr;
vector<int> order, component;
vector<bool> vis;

void dfs1(int src)
{
    vis[src]=true;

    for(auto v : g[src])
    {
        if(!vis[v])
            dfs1(v);
    }
    order.push_back(src);
}

void dfs2(int src)
{

    vis[src]=true;

    component.push_back(src);

    for(auto v : gr[src])
    {
        if(!vis[v])
            dfs2(v);
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    g.resize(n+1);
    gr.resize(n+1);
    vis.assign(n+1,false);

    while(m--)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    vis.assign(n+1,false);

    for(int i=1; i<=n ; ++i)
    {
        int v =order[n-i]; /// order should be count reverse order.
        if(!vis[v])
        {
            dfs2(v);

            for(auto u : component)
            {
                cout<<u<<" ";
            }
            cout<<'\n';
            component.clear();
        }
    }

}
