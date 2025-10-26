#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" 
 
using namespace std;
using ll = long long;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;

        string s;
        cin >> s;

        vector<bool> used(k, false);
        int count = 0;
        int blocks = 0;
        string block_ends;
        
        for (char c : s) 
        {
            int idx = c - 'a';
            if (idx < k && !used[idx]) 
            {
                used[idx] = true;
                count++;
            }
            
            if (count == k) 
            {
                ++blocks;
                block_ends += c;
                fill(used.begin(), used.end(), false); // заполняем used - false
                count = 0;
            }
        }
        
        if (blocks >= n) cout << "YES\n";
        else 
        {
            cout << "NO\n";

            char missing = 'a';
            for (int i = 0; i < k; i++) 
            {
                if (!used[i]) 
                {
                    missing = 'a' + i;
                    break;
                }
            }
            
            string result = block_ends;
            while (result.size() < n) result += missing;
                
            cout << result << "\n";
        }
    }


    return 0;
}