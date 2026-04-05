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
const int MOD = 1e9 + 7;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"
 

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

// standard bfs for distance
vector<int> bfs_dist(const vector<vector<int>> & adj, int src)
{
    int n = sz(adj);
    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);  
    
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }    
        }
    }

    return dist;
}

// bfs with parent reconstruction
pair<vector<int>, vector<int>> bfs_parent(const vector<vector<int>> & adj, int src)
{
    int n = sz(adj);
    vector<int> dist(n, -1), par(n, -1);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }    
        }
    }

    return {dist, par};
}


//multi starting source bfs on grid
vector<vector<int>> multisource_bfs(const vector<string> & grid)
{
    int n = sz(grid), m = sz(grid[0]);
    vector<vector<int>> dist(n, vector<int> (m, -1));
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }    
        }
    }


    while(!q.empty())
    {
        auto [i, j] = q.front(); q.pop();
        for(int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m || dist[ni][nj] != -1)
            {
                continue;
            }
            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});    
        }
    }

    return dist;
}


// bfs 1-0 on deque "bfs on weighted graph with wights 0 or 1 "
vector<int> bfs01(const vector<vector<pair<int, int>>> & adj, int src)
{
    const int INF = 1e9;
    int n = sz(adj);
    vector<int> dist(n, INF);
    deque<int> q;
    
    dist[src] = 0;
    q.push_front(src);

    while(!q.empty())
    {
        int u = q.front(); q.pop_front();
        for(auto [v, w] : adj[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                w ? q.push_back(v) : q.push_front(v); // if w = 0 push front
            }    
        }
    }

    return dist;
}

// kahn algorithm for topo sort on bfs
vector<int> kahn(const vector<vector<int>> & adj)
{
    int n = sz(adj);
    vector<int> indeg(n, 0);
    
    for(int u = 0; u < n; u++)
    {
        for(int v : adj[u]) indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(!indeg[i]) q.push(i);
    }

    vector<int> order;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v : adj[u])
        {
            if(!--indeg[v])
            {
                q.push(v);
            }    
        }
    }
    
    if(sz(order) != n) return {}; // cycle detected
    return order;
}

