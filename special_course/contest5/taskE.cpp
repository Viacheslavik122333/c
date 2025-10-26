#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
 
using namespace std;
using ll = long long;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int count=0;

    while(!A.empty())
    {
        // for(int i=0; i<A.size(); ++i) cout << A[i] << " "; cout << "\n";
        vector<int> B;
        for(int i=0; i<A.size()-1; ++i)
        {
            if(A[i]==A[i+1]) B.push_back(A[i]);
        }
        A=B;
        // for(int i=0; i<A.size(); ++i) cout << A[i] << " "; cout << "\n";
        
        ++count;

    }
    cout << n-count << "\n";
    
    return 0;
}