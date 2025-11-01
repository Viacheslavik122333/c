#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" 
#include "climits"
 
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    bool res = false;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
    {
        int x;
        cin >> x;
        x = x % m;
        if(x==0) res = true;
        v[i] = x;
    }

    if(res || n>= m) {cout << "YES" << endl; return 0;}

    vector<bool> dp(m, false);

    for (int i = 0; i < n; ++i) 
    {
        vector<bool> new_dp = dp;

        new_dp[v[i]] = true;

        for (int j = 0; j < m; ++j) 
        {
            if (dp[j]) 
            {
                int new_r = (j + v[i]) % m;
                new_dp[new_r] = true;
            }
        }
        dp = new_dp;
        if (dp[0]) 
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}