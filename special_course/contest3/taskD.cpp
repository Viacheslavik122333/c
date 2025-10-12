#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, tmp;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> B(k);

    for(int i=0; i<n; ++i)
    {
        cin >> tmp;
        A[i] = tmp;
    }
    for(int i=0; i<k; ++i)
    {
        cin >> tmp;
        B[i] = tmp;
    }

    int c, l = -1, r=n, m;

    for(int i=0; i<k; ++i)
    {
        while(r-l>1)
        {
            m = (l+r)/2;
            if(A[m]<B[i])
            {   
                l=m;
            }
            else
            {
                r=m;
            }
        }
        if(r==n) cout << A[l] << "\n";
        else if(l==-1) cout << A[r] << "\n";
        else (abs(A[l] - B[i]) <= abs(A[r] - B[i])) ? cout << A[l] << "\n" : cout << A[r] << "\n";
        l=-1; r=n;
    }

    return 0;
}