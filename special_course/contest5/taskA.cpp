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
    int n;
    cin >> n;
    vector<pair<char, int>> A;
    vector<pair<char, int>> B;
    vector<int> At;
    vector<int> Bt;
    for (int i = 0; i < n; ++i)
    {
        char x;
        cin >> x;
        A.push_back({x, 1});
        if(A[i].first == '?')  At.push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        char x;
        cin >> x;
        B.push_back({x, 1});
        if(B[i].first == '?')  Bt.push_back(i);
    }

    vector<vector<int>> s_l(26), t_l(26);

    int count = 0;
    vector<pair<int, int>> res;
    

    for (int i = 0; i < n; ++i) if (A[i].first != '?' && A[i].second == 1) s_l[A[i].first - 'a'].push_back(i);

    for (int i = 0; i < n; ++i) if (B[i].first != '?' && B[i].second == 1) t_l[B[i].first - 'a'].push_back(i);


    for (int i = 0; i < n; ++i) 
    {
        if (A[i].second == 1 && A[i].first != '?') 
        {
            char c = A[i].first;
            if (!t_l[c - 'a'].empty()) 
            {
                int j = t_l[c - 'a'].back();
                t_l[c - 'a'].pop_back();
                
                res.push_back({i, j});
                ++count;
                A[i].second = 0;
                B[j].second = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        if (Bt.empty()) break;
        if (A[i].second == 1 && A[i].first != '?') 
        {
            int j = Bt.back();
            Bt.pop_back();
            res.push_back({i, j});
            ++count;
            A[i].second = 0;
            B[j].second = 0;
        }
    }
    

    for (int i = 0; i < n; ++i) 
    {
        if (At.empty()) break;
        if (B[i].second == 1 && B[i].first != '?') 
        {
            int j = At.back();
            At.pop_back();
            res.push_back({j, i});
            ++count;
            B[i].second = 0;
            A[j].second = 0;
        }
    }
    
    while (!At.empty() && !Bt.empty()) 
    {
        int i = At.back(); At.pop_back();
        int j = Bt.back(); Bt.pop_back();
        if (A[i].second == 1 && B[j].second == 1) 
        {
            res.push_back({i, j});
            ++count;
            A[i].second = 0;
            B[j].second = 0;
        }
    }
    
    cout << count << "\n";
    for(int i=0; i<count; ++i) cout << res[i].first + 1 << " " << res[i].second + 1  << "\n";
    return 0;
}