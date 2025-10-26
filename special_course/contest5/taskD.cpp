#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" 
 
using namespace std;
using ll = long long;
 
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first>b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second>b.second;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) 
    {
        ll n, m, tmp_n;
        cin >> n >> m;
        
        vector<pair<ll, ll>> A(m);

        for (int i = 0; i < m; i++) cin >> A[i].first >> A[i].second;

        sort(A.begin(), A.end(), cmp);

        ll ans = 0;
        ll pref = 0;
        ll cur_max_b = 0;

        ll max_k = min(n, m);

        for (ll k = 1; k <= max_k; ++k) 
        {
            pref += A[k - 1].first;

            cur_max_b = max(cur_max_b, A[k - 1].second);

            ll this_ans = pref + (n - k) * cur_max_b;
            ans = max(ans, this_ans);
        }

        cout << ans << "\n";

    }
    
    return 0;
}
