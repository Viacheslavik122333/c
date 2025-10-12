#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
using ll = long long;

// ll dist(ll x1, ll y1, ll x2, ll y2) { return abs(x1-x2) + abs(y1-y2); }

bool cmp (ll a, ll b) {return (a<b);}

int main()
{
    int t, n;
    cin >> t;
    vector<ll> res;

    for(int i=0; i<t; ++i)
    {
        vector<ll> X, Y;
        cin >> n;
        for(int j=0; j<n; ++j)
        {
            ll x, y;
            cin >> x >> y;
            X.push_back(x);
            Y.push_back(y);
        }
        if(n%2==1) 
        {
            res.push_back(1);
            continue;
        }
        sort(X.begin(), X.end(), cmp);
        sort(Y.begin(), Y.end(), cmp);

        ll x_median1 = X[(n-1)/2];
        ll x_median2 = X[(n)/2];

        ll y_median1 = Y[(n-1)/2];
        ll y_median2 = Y[(n+1)/2];

        res.push_back((x_median2 - x_median1 + 1) * (y_median2 - y_median1 + 1));

    }
    for(int i=0; i<t; ++i) {cout << res[i] << "\n";}
    return 0;
}