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


void prefix_sum(int n, int q, const vector<int> & a)
{
    vector<int> pre(n, 0);
    pre[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    while(q--)
    {
        int l, r; cin >> l >> r;
        l--, r--; //for based-0
        if(l > r) swap(l, r);
        cout << pre[r] - (l > 0 ? pre[l - 1] : 0) << nl;
    }
}




void two_D_prefix(int n, int m, int q, const vector<vector<int>> & a)
{
    vector<vector<int>> pre(n + 1, vector<int> (m + 1));
    // for 2d prefix : 
    // prefix[i][j] = arr[i][j] + prefix[i - 1][j]  + prefix[i][j - 1] - prefix[i - 1][j - 1]

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            pre[i][j] = a[i][j] + pre[i - 1][j]  + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    while(q--)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        int res = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        cout << res << nl;
    }
}
