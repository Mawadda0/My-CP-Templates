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

ll fastpower(ll base, ll exp) // fast exponentiation (base^exp) without modulo
{
    ll res = 1;
    while(exp){
        if(exp & 1) res *= base;
        base *= base;
        exp >>= 1ll;
    }
    return res;
}

ll modpow(ll base, ll exp, ll mod) // fast modular exponentiation: (base^exp) % mod
{
    base %= mod;
    ll res = 1;
    while(exp){
        if(exp & 1) res = (res * base) % mod;
        base = ((base % mod) * (base % mod)) % mod;
        exp >>= 1ll;
    }
    return res;
} // (base ^ exp) % mod

// used for modular inverse: a^(mod-2) % mod when mod is prime