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
 
const int N = 510; // an initial size of array
int n, m; // global for more usage
int dist[N][N]{0}; // adj matrix for calculating distance 
 
void solve()
{
    int q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
 
 
    for(int i = 0; i < m; i++)
    {
        int x, y, c; cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], c); // undirected graph representation
        dist[y][x] = min(dist[y][x], c);
    }
 
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // floyed implementation
            }
        }
    }
 
    while(q--)
    {
        int a, b; cin >> a >> b;
        if(dist[a][b] == INF) cout << -1 << nl; // if there is no such path
        else cout << dist[a][b] << nl;
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
