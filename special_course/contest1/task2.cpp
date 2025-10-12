// #include "bits/stdc++.h"
#include "iostream"
#include "vector"

using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=0, res=0, tmp;
    cin >> n;
    vector<int> N(n);
    
    for(int i=0; i<n; ++i)
    {   
        cin >> tmp;
        res +=tmp;
        N[i]= res;
    }
    tmp = (res+1)/2;
    for(int i=0; i<n; ++i)
    {
        if(N[i]>= tmp) 
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}