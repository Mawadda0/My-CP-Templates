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

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

struct Edge
{
    int u, v, w;
};

vector<Edge> read_graph(int m)
{
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    return edges;
}

// Bellman-Ford
void bellman_ford(int n, const vector<Edge> &edges, vector<int> &dist, vector<int> &par)
{
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(auto [u, v, w] : edges)
        {
            if(dist[u] < INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
}


int detect_cycle(int n, const vector<Edge> &edges, vector<int> &dist, vector<int> &par)
{
    int node = -1;

    for(auto [u, v, w] : edges)
    {
        if(dist[u] < INF && dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            par[v] = u;
            node = v;
        }
    }

    if(node == -1) return -1;

    // ندخل جوه cycle
    for(int i = 0; i < n; i++)
    {
        node = par[node];
    }

    return node;
}


vector<int> get_cycle(int start, const vector<int> &par)
{
    vector<int> cycle;
    int cur = start;

    cycle.push_back(cur);
    for(int v = par[cur]; v != start; v = par[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(start);

    reverse(all(cycle));
    return cycle;
}

