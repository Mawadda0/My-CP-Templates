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

const int N = 200005;

vector<int> gr[N];
vector<bool> vis;

void dfs_itr(int node) // dfs iterative
{
    stack<int> st;
    st.push(node);
    vis[node] = 1;

    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        cout << tp << " ";

        for (int i : gr[tp])
        {
            if (!vis[i])
            {
                st.push(i);
                vis[i] = 1;
            }
        }
    }
    cout << nl;
}

void dfs_rec(int node) // dfs recursive
{
    vis[node] = 1;
    cout << node << " ";

    for (int i : gr[node])
    {
        if (!vis[i])
        {
            dfs_rec(i);
        }
    }
}

void bfs_itr(int node) // bfs iterative
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        cout << tp << " ";

        for (int i : gr[tp])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    cout << nl;
}

void bfs_rec(int node) // bfs recursive
{
    // Still thinking how to implement...
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vis.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
        gr[i].clear();

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    int root = 1;

    dfs_itr(root);
    fill(all(vis), false);

    dfs_rec(root);
    fill(all(vis), false);

    cout << nl;
    bfs_itr(root);
    fill(all(vis), false);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
        if (tc) cout << nl;
    }
    return 0;
}
