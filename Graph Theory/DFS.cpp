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
vector<vector<int>> adj; // holdes the nodes and their adjacency
 
 
void graph_rep(int n, int m)
{
    adj.assign(n + 1, {});
    int u, v, t;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> t;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
 
vector<int> vis;
vector<int> color;
bool cycle = false;
 
void dfs(int node)
{
    vis[node] = 1;
    for(int ni : adj[node])
    {
        if(!vis[ni]) dfs(ni);
    }
 
}
 
 
void dfs_tree(int u, int p)
{ // for a tree (just parent and child relationship)
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs_tree(v, u);
    }
}
 
 
int dfsCount(int u)
{  // count components (neighbors and neighbors of the neighbors) for a node
    vis[u] = 1;
    int cnt = 1;
    for(int v : adj[u])
    {
        if(!vis[v]) 
        cnt += dfsCount(v);
    }
    return cnt;
}
 
bool dfs_cycle(int u)
{
    color[u] = 1; // GRAY
    for(int v : adj[u])
    {
        if(color[v] == 0)
        {
            if(dfs_cycle(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2; // BLACK
    return false;
}
 
string grid[2001];
bool vis2d[2001][2001];
int di[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};
int rows, cols;
 
bool is_valid(int r, int c)
{
    return (r >= 0 && r < rows && c >= 0 && c < cols && !vis2d[r][c] && grid[r][c] == '.');
}
 
 
 
void dfs_grid(int r, int c)
{
    vis2d[r][c] = true;
    for(int k = 0; k < 4; k++)
    {
        int nr = r + di[k];
        int nc = c + dj[k];
        if(is_valid(nr, nc)) dfs_grid(nr, nc);
    }
}
 
 
template <int N, int M>
struct ForwardStar
{
    //In case of weighted graph, put back all removed w.
    int head[N];
    int to[M];
    int nxt[M];
    //int wt[M];
    int ne;
 
    void init(int n)
    {
        ne = 0;
        fill(head, head + n + 1, -1); 
    }
 
    // Removed the 'int w' parameter
    void addEdge(int u, int v)
    {
        to[ne] = v;
        //wt[ne] = w;
        nxt[ne] = head[u];
        head[u] = ne++;
    }
 
    // Removed the 'int w' parameter
    void addBiEdge(int u, int v)
    {
        addEdge(u, v);
        addEdge(v, u);
    }
 
    void traverse(int u)
    {
        cout << "Neighbors of node " << u << ": ";
        
        for(int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e];
            //int w = wt[e];
            cout << v << " ";
        }
        cout << nl;
    }
};
 
 
int dfsDepth(int u)
{
    int maxx = 0;
    for(auto v : adj[u])
    {
        maxx = max(maxx, dfsDepth(v));
    }
    return maxx + 1;
}

vector<int> topo;
vector<int> visTopo;

void dfs_topo(int u)
{
    visTopo[u] = 1;
    for(int v : adj[u])
    {
        if(!visTopo[v])
            dfs_topo(v);
    }
    topo.push_back(u); 
}

vector<int> topological_sort(int n)
{
    visTopo.assign(n + 1, 0);
    topo.clear();

    for(int i = 1; i <= n; i++)
    {
        if(!visTopo[i])
            dfs_topo(i);
    }

    reverse(topo.begin(), topo.end());
    return topo;
}
 
