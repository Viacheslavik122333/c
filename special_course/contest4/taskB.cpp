#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для pair

using namespace std;
using ll = long long;

int main() 
{
    ll n, k;
    cin >> n >> k;
    vector<ll> A;
    ll count = 0;
    ll i;
    
    for (i = 1; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            count++;
            if (count == k) 
            {
                cout << i << endl;
                return 0;
            }
            A.push_back(n / i);
        }
    }
    
    bool prof = ((i-1) * (i-1) == n);
    
    ll tmp = prof ? 2*count - 1 : 2*count;
    
    if (k > tmp) cout << -1 << endl; 
    else 
    {
        if (prof) cout << A[2*count - k - 1] << endl;
        else cout << A[2*count - k] << endl;
    }
    
    return 0;
}