#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для pair

using namespace std;
using ll = unsigned long long;

ll binpow (ll a, ll b, ll p)
{
    ll prod = 1;
    ll mlt = a;
    while (b)
    {
        if(b & 1)
        {
            prod = (prod * mlt) % p;
        }
        b >>= 1;
        mlt = (mlt * mlt) % p;
    }
    return prod;
}

// m!
// (n-1)! (m-n+1)!


int main() 
{
    int m, n;
    cin >> n >> m;
    if(n/2 > m) {cout << 0; return 0;}
    ll p = 998244353;

    if(n==2) {cout << 0; return 0;}


    vector<ll> fact(m + 1), inv_fact(m + 1);

    fact[0] = 1;

    for (ll i = 1; i <= m; i++) 
    {
        fact[i] = fact[i-1] * i % p;
    }

    inv_fact[m] = binpow(fact[m], p-2, p);

    for (ll i = m; i >= 1; i--) 
    {
        inv_fact[i-1] = inv_fact[i] * i % p;
    }
    

    ll res = fact[m] * inv_fact[n-1] % p * inv_fact[m - (n-1)] % p;
    ll ans = res * (n - 2) % p * binpow(2, n - 3, p) % p;
    
    cout << ans << endl;


    return 0;
}