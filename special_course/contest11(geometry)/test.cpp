#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

#define x first
#define y second

using ll = long long;
using namespace std;

ll prod(ll vx, ll vy, ll wx, ll wy)
{
    return vx * wy - vy * wx;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<pair<int, int>> v;
    // for (int i=0; i<n; ++i)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     v.push_back({a, b});
    // }
    
    cout << prod(2, 1, 1, 4) << endl;
    cout << prod(1, 3, 2, 0) << endl;



    return 0;
}

#undef x
#undef y