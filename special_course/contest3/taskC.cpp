#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для swap

using namespace std;
using ll = long long;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, k, tmp;
    cin >> t;

    for(int i=0; i<t; ++i)
    {
        cin >> n >> k;
        vector<int> v;
        for(int j=0; j<n; ++j) {cin >> tmp; v.push_back(tmp);}
        sort(v.begin(), v.end());

        auto last = std::unique(v.begin(), v.end());
        v.erase(last, v.end());

        bool res = false;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && v[j] - v[i] < k) 
            {
                j++;
            }
            if (j < n && v[j] - v[i] == k) 
            {
                res = true;
                break;
            }
        }
        cout << (res ? "YES\n" : "NO\n");
    }
    return 0;
}