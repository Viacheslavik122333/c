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
    int tmp1, tmp2, n, m;
    vector<int> K(n);
    vector<pair<int, int>> arr(m);
    cin >> n >> m;
    for(int i=0; i<n; ++i){cin >> tmp1; K[i]=tmp1;}
    for(int i=0; i<m; ++i){cin >> tmp1 >> tmp2; arr[i]={tmp1, tmp2};}


    return 0;
}