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

void solve()
{
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;
    
    vector<int> dist(n + 5, INF); // distance array initialized to INF
    vector<int> par(n + 5, -1); // parent array to reconstruct paths
    
    // Store edges as [from, to, weight]
    vector<vector<int>> adj(m, vector<int>(3));
    
    // Read all edges
    for(int i = 0; i < m; i++)
    {
        int fr, to, wi; // from, to, weight
        cin >> fr >> to >> wi;
        adj[i][0] = fr, adj[i][1] = to, adj[i][2] = wi;
    }
    
    dist[1] = 0; // Set distance of source node (node 1) to 0
    
    // Bellman-Ford main loop: relax edges (n-1) times
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int fr = adj[j][0];
            int to = adj[j][1];
            int wi = adj[j][2];

            // Relaxation condition
            if(dist[fr] + wi < dist[to])
            {
                dist[to] = dist[fr] + wi;
                par[to] = fr; // Update parent for path reconstruction
            }
        }
    }
    
    bool is_cycle = false; // Flag to detect negative cycles
    int node = 0; // Node affected by negative cycle
    
    // Check for negative cycles by relaxing one more time
    for(int i = 0; i < m; i++)
    {
        int fr = adj[i][0];
        int to = adj[i][1];
        int wi = adj[i][2];
        
        // If we can still relax, negative cycle exists
        if(dist[fr] + wi < dist[to])
        {
            is_cycle = true;
            dist[to] = dist[fr] + wi;
            par[to] = fr; 
            node = to; // Mark a node affected by the cycle
        }
    }
    
    // If no negative cycle found
    if(!is_cycle) return void(cout << "NO");
    
    // Find a node that's part of the negative cycle
    // Move back n steps to ensure we're inside the cycle
    for(int i = 0; i < n; i++)
    {
        node = par[node];
    }
    
    // Reconstruct the negative cycle
    vector<int> cy; // Cycle nodes
    int cur = node;
    cy.push_back(cur);
    
    // Traverse the cycle until we return to the starting node
    for(int i = par[cur]; i != node; i = par[i])
    {
        cy.push_back(i);
    }
    cy.push_back(node); // Complete the cycle
    reverse(cy.begin(), cy.end()); // Reverse to get correct order
    
    // Output the result
    cout << "YES" << nl;
    for(int i = 0; i < sz(cy); i++)
    {
        cout << cy[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
        if(tc) cout << nl;
    }
    return 0;
}