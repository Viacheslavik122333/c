#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для pair

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp, m, l, r, tmp1, tmp2; 
    cin >> n;
    vector<int> A(n); 
    for(int i=0; i<n; ++i) {cin >> tmp; A[i] = tmp;}
    sort(A.begin(), A.end());

    cin >> m;

    for(int i = 0; i < m; ++i) 
    {
        int l, r;
        cin >> l >> r;
        
        auto left_it = lower_bound(A.begin(), A.end(), l);
        auto right_it = upper_bound(A.begin(), A.end(), r);
        
        if(left_it == right_it) 
        {
            cout << "0\n";
            continue;
        }
        
        right_it--;
        cout << *right_it - *left_it << "\n";
    }
    return 0;
}