#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" 
 
using namespace std;
using ll = long long;
 
const int MAX_K = 500;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c (n);
    for(int i=0; i < n; ++i) cin >> c[i];

    // dp[i][j] = можно ли набрать первое подмножество суммы i и второе подмножество суммы j
    vector<vector<bool>> dp (k + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;

    for (int cost : c) 
    {
        for (int i = k; i >= 0; i--) 
        {
            for (int j = k; j >= 0; j--) 
            {
                if (dp[i][j]) 
                {
                    if (i + cost <= k) 
                    {
                        dp[i + cost][j] = true;
                    }
                    if (j + cost <= k) 
                    {
                        dp[i][j + cost] = true;
                    }
                    // 
                }
            }
        }
    }


    vector<int> res;
    for (int i = 0; i <= k; i++) 
    {
        if (dp[i][k - i]) res.push_back(i);
    }

    cout << res.size() << endl;

    for (int x : res) cout << x << " ";

    cout << endl;

    return 0;
}