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
#define sum_mod(a, b, m) ((a % m) + (b % m) % m)
#define mul_mod(a, b, m) ((a % m) * (b % m) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

ll ext_euclidean_gcd(ll a, ll b, ll &x, ll &y) // Extended Euclidean Algorithm,  Solves ax + by = gcd(a, b)
{
        if (b == 0)
        {
                x = 1, y = 0;
                return a;
        }
        ll x1, y1;
        ll d = ext_euclidean_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return d;
}

ll mod_inverse(ll b, ll m) // modular inverse of b mod m using Extended Euclid
{
        ll x, y;
        ll g = ext_euclidean_gcd(b, m, x, y);
        if (g != 1)
                return -1;
        return (x % m + m) % m; // normalize x to positive mod
} // --> find a / b & mod

int modInverse(int A, int M) // brute-force modular inverse
{
        for (int X = 1; X < M; X++)
                if (((A % M) * (X % M)) % M == 1)
                        return X;
}