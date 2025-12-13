#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;


bool cmp (const vector<int>& a, const vector<int>& b)
{
    if (a[0] != b[0]) return a[0] > b[0];
    return a[1] > b[1];
}

bool cmp2 (const vector<int>& a, const vector<int>& b)
{
    return a[2]<b[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i=0; i<n; ++i)
    {
        int r, t;
        cin >> r >> t;
        v[i] = {r, t, i+1};
    }

    sort(v.begin(), v.end(), cmp);

    vector<vector<int>> point;

   long long tmp = 0;
    for (auto& p : v) 
    {
        if (p[1] > tmp) 
        {
            point.push_back(p);
            tmp = p[1];
        }
    }

    sort(point.begin(), point.end(), cmp2);

    for(int i=0; i<point.size(); ++i) cout << point[i][2] << " ";
    
    // for(int i=0; i<n; ++i) cout << v[i].x << " " << v[i].y << "\n";

    return 0;
}



