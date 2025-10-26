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

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
            
        vector<ll> B;
        vector<ll> R;

        bool possible = true;

        for (int i = 0; i < n; ++i) // создаем массивы B и R
        {
            char x;
            cin >> x;
            if (x == 'B') B.push_back(A[i]);
            if (x == 'R') R.push_back(A[i]);
        }

        sort(B.begin(), B.end());
        sort(R.begin(), R.end());

        

        for (int i = 0; i < B.size(); i++) 
        {
            ll target = i + 1;
            if (B[i] > target) continue;
            else if (B[i] < target) 
            {
                possible = false;
                break;
            }
        }
        
        for (int i = 0; i < R.size(); i++) 
        {
            ll target = n - R.size() + 1 + i;
            if (R[i] < target) continue;
            else if (R[i] > target) 
            {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}