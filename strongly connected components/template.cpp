/* SCC from BenQ */
struct SCC {
	int N;
    vector<vector<int>> adj, radj;
	vector<int> todo, comps, comp;
    vector<bool> vis;

    /// Initialization
	void init(int _N) {
	    N = _N;
		adj.resize(N);
        radj.resize(N);
        comp = vector<int>(N,-1);
        vis.resize(N);
	}

	/// added edges.
	void ae(int x, int y) {
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    /// find topoSort order.
	void dfs(int x) {
		vis[x] = 1;
        for(auto y : adj[x]) {
            if(vis[y]) continue;
            dfs(y);
        }
		todo.push_back(x);
    }

    /// find all scc
	void dfs2(int x, int v){  /// same dad of everyone 'v'.
		comp[x] = v;
		for (auto y : radj[x]) {
            if (comp[y] == -1) dfs2(y,v);
		}
    }

    /// build scc
	void gen(int _N) { // fills allComp
		for ( int i = 1 ; i < N ; ++i ){
        if (!vis[i]) dfs(i);
		}
		reverse(all(todo));
		for( auto x : todo ){
            if (comp[x] == -1) {
			dfs2(x,x);
            comps.push_back(x);
			}
		}
	}
}scc;
