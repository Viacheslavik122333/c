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
    
    int n, c;
    cin >> n >> c;
    vector<int> a (n-1);
    vector<int> b (n-1);
    for(int i=0; i < n-1; ++i) cin >> a[i];
    for(int i=0; i < n-1; ++i) cin >> b[i];

    vector<int> dp (n, 0);
    int taxi = INT_MAX;

    for(int i = 1; i<n; ++i)
    {
        int tmp_taxi;
        if (taxi == INT_MAX) 
        {
            tmp_taxi = dp[i - 1] + c + b[i - 1];
        } 
        else 
        {
            tmp_taxi = min(taxi + b[i - 1], dp[i - 1] + c + b[i - 1]);
        }

        dp[i] = min(dp[i - 1] + a[i - 1], tmp_taxi);
        
        taxi = tmp_taxi;
    }

    for(int i : dp) cout << i << " ";
    cout << endl;
 
    return 0;
}