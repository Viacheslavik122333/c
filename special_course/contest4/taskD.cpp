#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для pair

using namespace std;
using ll = long long;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i=0; i<t; ++i)
    {
        ll a, b, p;
        cin >> a >> b >> p;

        a %= p;
        if (a < 0) a += p;

        b %= p;
        if (b < 0) b += p;
        
        if (a == 0) 
        {
            if (b == 0) cout << "Any\n"; 
            else cout << "-1\n";   
        } 
        else 
        {
            ll inv_a = binpow(a, p-2, p);
            ll res = (p - b) % p;
            res = (res * inv_a) % p;
            if (res < 0) res += p;
            cout << res << '\n';
        }
    }
    return 0;
}