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
    
    int n;
    cin >> n;
    vector<int> v (n, 0);
    for(int i=0; i<n; ++i)
    {
        char x; 
        cin >> x;
        if(x == 'f') v[i]=1;
    }

    int mod = 1e9+7;

    vector<int> dp(n, 0); // кол-во способов 
    dp[0] = 1;

    for (int i = 0; i < n - 1; ++i) 
    {
        vector<int> new_dp(n, 0);

        if (v[i]) 
        {
            for (int j = 1; j < n; j++) 
            {
                new_dp[j] = dp[j - 1];
            }
        } 
        else 
        {
            int total = 0;
            for (int j = 0; j < n; j++) 
            {
                total = (total + dp[j]) % mod;
            }

            new_dp[0] = total;

            for (int j = 1; j < n; j++) 
            {
                new_dp[j] = (new_dp[j - 1] - dp[j - 1] + mod) % mod;
            }
        }
        dp = new_dp;
    }
    
    int ans = 0;
    for (int j = 0; j < n; j++) ans = (ans + dp[j]) % mod;

    cout << ans << endl;

    return 0;
}