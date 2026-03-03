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

// segment tree for range sum queries
struct Node
{
    int sum;

    Node()
    {
        sum = 0; // the initial value
    }

    Node(int x)
    {
        sum = x;
    }

    void change(int x)
    {
        //sum += x for adding
        sum = x; //for updating
    }
};


struct segTree
{
    int tree_size;
    vector<Node> segData;

    segTree(int n)
    {
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        segData.assign(2 * tree_size, Node());
    }

    // get sum of two nodes, gcd, min or max, or lcm, or whatever yout want to get
    Node merge(Node & lf, Node & ri)
    {
        Node res = Node();
        res.mini = min(lf.mini, ri.mini);
        return res;
    }

    // ni is the number of the node(tree level by level)
    // lx and rx are the ranges of the node
    // range is from lx to rx, and rx are not included

    void setP(int idx, int val, int ni, int lx, int rx) // 0-indexed , r isn't included
    {
        if(rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }

        int mid = (lx + rx) / 2;
        if(idx < mid)
        {
            setP(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            setP(idx, val, 2 * ni + 2, mid, rx);
        }

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void set(int idx, int val)
    {
        setP(idx, val, 0, 0, tree_size);
    }

    Node getP(int l, int r, int ni, int lx, int rx) // 0-indexed , r isn't included
    {
        if(lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if(lx >= r || rx <= l)
        {
            return Node();
        }

        int mid = (lx + rx) / 2;
        Node left = getP(l, r, 2 * ni + 1, lx, mid);
        Node right = getP(l, r, 2 * ni + 2, mid, rx);

        return merge(left, right);
    }

    int get(int l, int r)
    {
        return getP(l, r, 0, 0, tree_size).mini;
    }


    void initP(vector<int> & a, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(a))
            {
                segData[ni] = Node(a[lx]);
            }
 
            return;
        }
        int mid = (lx + rx) / 2;
        initP(a, 2 * ni + 1, lx, mid);
        initP(a, 2 * ni + 2, mid, rx);
 
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
 
    void init(vector<int> & a)
    {
        initP(a, 0, 0, tree_size);
    }
};

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    segTree segmnt_tree(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segmnt_tree.init(a);

    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        //l--; in 1-based for range query, r is not included, and in 0-based -> r++
        cout << segmnt_tree.get(l, r) << nl;
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