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

const int MAXI = 5e5 + 5;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"




struct DSU
{
    vector<int> parent, group;
    int comps, maxi_comp_size;


    DSU(int n)
    {
        parent.resize(n);
        group.resize(n);
        comps = n, maxi_comp_size = 1;
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            group[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b) return false;    
        if(group[a] < group[b]) swap(a, b);

        group[a] += group[b];
        parent[b] = a;
        comps--;
        maxi_comp_size = max(maxi_comp_size, group[a]);
        return true;
    }
    
    bool same_set(int a, int b)
    {
        return find(a) == find(b);
    }

    int get_size(int x)
    {
        return group[find(x)];
    }
  
};

vector<int> nxt; // nxt[i] = i , initialize with size n in solve
int get_next(int x)
{
    if(nxt[x] == x) return x;
    return nxt[x] = get_next(nxt[x]);
}

void unite_ranges(int l, int r, DSU & dsu) // [l, r]
{
    int cur = get_next(l);

    while(cur < r && cur + 1 < sz(nxt))
    {
        dsu.unite(cur, cur + 1);

        int tmp = cur;
        cur = get_next(cur + 1);

        nxt[tmp] = tmp + 1;
    }
}



signed main()
{
    
    return 0;
}
