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
 
const int N = 2e5;
int n, m;
vector<pair<int, int>> gr[N];
int vis[N]{0};
vector<int> dis;
 
void dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    dis[node] = 0;
    while(!pq.empty())
    {
        auto [co, no] = pq.top();
        pq.pop();
        if(vis[no])
        {
            continue;
        }
        vis[no] = 1;
        for(auto [a, b] : gr[no])
        {
            if(dis[a] > co + b)
            {
                dis[a] = co + b;
                pq.push({dis[a], a});
            }
        }
    }
}
 
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        gr[i].clear();
    }
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    dis.assign(n + 1, INF);
    for(int i = 0; i < m; i++)
    {
        int x, y, c; cin >> x >> y >> c;
        gr[x].push_back({y, c});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        cout << dis[i] << " "; // distance from node 1 to node n
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