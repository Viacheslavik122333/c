#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t>0)
    {
        int n; // кол-во городов
        int m; // кол-во дорог
        cin >> n >> m;
        vector<int> U(m); // дорога из 
        vector<int> V(m); // дорога в
        vector<int> W(m); // длина дороги 
        vector<int> S(n); // скорость каждой машины в i-ом городе
        for(int i=0; i<m; ++i) cin >> U[i] >> V[i] >> W[i];
        for(int i=0; i<n; ++i) cin >> S[i];

        
        
        --t;
    }
    return 0;
}