#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "iomanip" // для точности ответа

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10); // для точности ответа

    int t_;
    cin >> t_;
    for(int h=0; h<t_; ++h)
    {
        int n;
        cin >> n;
        vector<double> x(n), t(n);
        for(int i=0; i<n; ++i) cin >> x[i];
        for(int i=0; i<n; ++i) cin >> t[i];

        double L = 1e9;
        double R = -1e9;
        
        for (int i = 0; i < n; i++) 
        {
            double left = x[i] - t[i];
            double right = x[i] + t[i];
            
            if (left < L) L = left;
            if (right > R) R = right;
        }
        
        double res = (L + R) / 2.0;
        cout << res << "\n";
    }
    return 0;
}