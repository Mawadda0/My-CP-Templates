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


vector<ll> factors;
void primes(ll n) // get all prime factors of n (with repetition)
{
    if(n == 1){
        cout << 1 << nl;
        return;
    }
    vector<ll> factors;
    factors.push_back(1);
    while(n % 2 == 0){
        factors.push_back(2);
        n /= 2;
    }
    for(ll i = 3; i * i <= n; i += 2)
    {
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 2) factors.push_back(n);
}


vector<pair<ll,ll>> Prime_factors(ll n) // return prime factors with their counts
{
    vector<pair<ll,ll>> res;
    for(ll i = 2; i * i <= n; i++)
    {
        ll c = 0;
        if(n % i == 0)
        {
            while(n % i == 0) n /= i, c++; // --> important point, count how many times i divides n
            res.push_back({i, c});
        }
    }
    if(n > 1) res.push_back({n, 1});
    return res;

}