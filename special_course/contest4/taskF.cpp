#include "iostream"
#include "vector"
#include "algorithm"


using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    while(b!=0)
    {
        ll tmp = b;
        b = a%b;
        a= tmp;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    ll g = 0;
    for (int i = 1; i < n; ++i) 
    {
        g = gcd(g, v[i] - v[0]);
    }
    

    for (int i = 0; i < q; ++i) 
    {
        ll x;
        cin >> x;

        ll result = gcd(v[0] + x, g);
        
        cout << result << " ";
    }

    return 0;
}