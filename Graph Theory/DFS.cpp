#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define nl '\n'
#define ll long long
#define int long long
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define fixed(n) fixed << setprecision(n)
#define min_count(x) order_of_key(x)
#define num_in_pos(x) find_by_order(x)
#define ull unsigned long long
const double pi = 3.141592653589793;
const long long INF = 1e18;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5;

struct DFS
{
    int n;
    vector<int> adj[N];
    vector<bool> vis;
    vector<int> parent;
    vector<int> topo;
    vector<int> dist;

    DFS(int n)
    {
        this->n = n;
        vis.assign(n, false);
        parent.assign(n, -1);
        dist.assign(n, 0);
    }

    void addEdge(int u, int v, bool directed = false)
    {
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    void dfs(int node)
    {
        vis[node] = true;

        for(int child : adj[node])
        {
            if(!vis[child])
            {
                parent[child] = node;
                dist[child] = dist[node] + 1; // distance from root
                dfs(child);
            }
        }
    }


    int connected_components()
    {
        int cnt = 0;
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }

        return cnt;
    }


    vector<int> shortest_path(int src) // tree, unwighted graphs
    {
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), 0);
        fill(parent.begin(), parent.end(), -1);
        dfs(src);
        return dist; // distance from src
    }


    void topo_dfs(int node)
    {
        vis[node] = true;

        for(int child : adj[node])
        {
            if(!vis[child]) topo_dfs(child);
        }

        topo.push_back(node);
    }

    vector<int> topological_sort()
    {
        fill(vis.begin(), vis.end(), false);
        topo.clear();

        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) topo_dfs(i);
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};


void solve()
{
    int n, m;
    cin >> n >> m;

    DFS g(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }

    cout << "Connected Components : " << nl;
    cout << g.connected_components() << nl; //connected components


    vector<int> dist = g.shortest_path(0);

    cout << "Distances from node 1:" << nl;
    for(int i = 0; i < n; i++)
    {
        cout << dist[i] << nl;
    }


    cout << "Parents:" << nl;
    for(int i = 0; i < n; i++)
    {
        if(g.parent[i] == -1) cout << "None";
        else cout << g.parent[i] + 1;
        cout << nl;
    }


    cout << "Topological Sort:" << nl;

    vector<int> topo = g.topological_sort();
    for(int x : topo) cout << x + 1 << " ";
    cout << nl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        if(tc) cout << nl;
    }
    return 0;
}