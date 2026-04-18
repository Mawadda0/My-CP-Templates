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
const int MAX = 1e5;

vector<ll> fact(MAX);                 // array to store factorial values modulo 'mod'
const int mod = 998244353;            // fixed modulo value (can be changed)

// Precompute factorials modulo 'mod'
void precalc_factorial() {
    fact[0] = 1;                      // 0! = 1
    for (int i = 1; i < MAX; i++) {
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod; // fact[i] = i! % mod
    }
}


// Count occurrences of a prime factor p in n! (Legendre's formula)
ll count_p_in_factorial_n(ll n, ll p)
{
    ll res = 0;                 // stores the total exponent of p in n!
    while (n) {
        res += n / p;           // add number of multiples of p, p^2, p^3...
        n /= p;                 // reduce n by dividing by p
    }
    return res;                 // return the exponent of p in n!
}
