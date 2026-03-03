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


// Disjoint Set Union (Union-Find) data structure
// Used for efficient connectivity queries in graphs
struct DSU
{
    vector<int> parent; // parent array for union-find operations
    
    // Constructor: initialize DSU with n elements
    DSU(int n)
    {
        parent.resize(n);
        // Each element starts as its own parent (disjoint sets)
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    
    // Find operation with path compression
    // Returns the representative (root) of the set containing x
    int find(int x)
    {
        // If x is its own parent, it's the root
        if(parent[x] == x) return x;
        // Recursively find root and compress path
        return parent[x] = find(parent[x]);
    }
    
    // Union operation: merge sets containing a and b
    // Returns true if sets were merged, false if they were already in same set
    bool unite(int a, int b)
    {
        a = find(a); // Find root of a's set
        b = find(b); // Find root of b's set
        if(a == b) return false; // Already in same set
        parent[b] = a; // Make a the parent of b
        return true;
    }
    
    // Check if two elements are in the same set
    bool same_set(int a, int b)
    {
        return find(a) == find(b);
    }
};



void solve()
{
    int n, m; 
    cin >> n >> m; // n = number of nodes, m = number of edges
    
    vector<tuple<int, int, int>> edg; // Vector to store edges as (weight, u, v)
    
    // Read all edges from input
    for(int i = 0; i < m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        u--; // Convert to 0-based indexing
        v--; // Convert to 0-based indexing
        edg.push_back({w, u, v}); // Store as (weight, from, to)
    }
    
    // Sort edges by weight in non-decreasing order (Kruskal's algorithm step 1)
    sort(edg.begin(), edg.end());
    
    DSU dsu(n); // Initialize DSU with n nodes
    
    int mst = 0; // Total weight of Minimum Spanning Tree
    
    // Process edges in sorted order (Kruskal's algorithm step 2)
    for(auto & [w, u, v] : edg)
    {
        // If u and v are in different sets, add this edge to MST
        if(dsu.unite(u, v)) 
            mst += w; // Add edge weight to total MST weight
    }
    
    // total weight of the Minimum Spanning Tree
    cout << mst;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
        if (tc)
            cout << nl;
    }
    return 0;
}