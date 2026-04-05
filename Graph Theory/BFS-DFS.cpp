#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define nl '\n'
#define ll long long
#define int long long
#define fixed(n) fixed << setprecision(n)
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define min_count(x) order_of_key(x)
#define num_in_pos(x) find_by_order(x)
#define ull unsigned long long

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ" 
const int N = 2e5 + 5;

// -- DFS IMPLEMENTATION --
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

// -- BFS IMPLEMENTATION --
struct BFS
{
    int n;
    vector<int> adj[N];
    vector<bool> vis;
    vector<int> parent;
    vector<int> dist;

    BFS(int n)
    {
        this->n = n;
        vis.assign(n, false);
        parent.assign(n, -1);
        dist.assign(n, -1); // -1 = not reachable
    }

    void addEdge(int u, int v, bool directed = false)
    {
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);

        vis[src] = true;
        dist[src] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int child : adj[node])
            {
                if(!vis[child])
                {
                    vis[child] = true;
                    parent[child] = node;
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
    }

    int connected_components()
    {
        int cnt = 0;
        fill(vis.begin(), vis.end(), false);

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                bfs(i);
                cnt++;
            }
        }

        return cnt;
    }

    vector<int> shortest_path(int src) // correct for unweighted graphs
    {
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), -1);
        fill(parent.begin(), parent.end(), -1);

        bfs(src);
        return dist;
    }

    vector<int> get_path(int src, int dest)
    {
        vector<int> path;

        if(dist[dest] == -1) return path; // no path

        for(int v = dest; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());
        return path;
    }
};
