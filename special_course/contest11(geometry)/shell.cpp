#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define x first
#define y second

using ll = long long;
using namespace std;

pair<int, int> p = {1001,1001};


ll prod(ll vx, ll vy, ll wx, ll wy)
{
    return vx * wy - vy * wx;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) 
{
    return atan2(a.y - p.y, a.x - p.x) < atan2(b.y - p.y, b.x - p.x);
}

ll Sum(vector<pair<int, int>> v, pair<int, int> P)
{
    ll res=0;
    for(int i=2; i<v.size(); ++i)
    {
        res += prod(
            v[i-1].x - v[i-2].x,
            v[i-1].y - v[i-2].y,
            v[i].x - v[i-1].x,
            v[i].y - v[i-1].y);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    // pair<int, int> p({1001,1001});
    for (int i=0; i<n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        if(b<=p.y) if(a<p.x) p = {a,b};
    }
    
    vector<pair<int, int>> point;
    point.push_back(p);

    std::sort(v.begin(), v.end(), cmp);
    point.push_back(v[1]);

    // for(int i=0; i<n; ++i) cout << v[i].x << " " << v[i].y << "\n";

    for(int i=2; i<n; ++i) // линейная оболочка
    {
        while(prod(
            (*(point.end()-1)).x - (*(point.end()-2)).x, 
            (*(point.end()-1)).y - (*(point.end()-2)).y,  
            v[i].x - (*(point.end()-1)).x, 
            v[i].y - (*(point.end()-1)).y
            )<0)
        {
            // cout << (*(point.end()-1)).x << " " << (*(point.end()-1)).y << "\n";
            point.pop_back();
        }
        point.push_back(v[i]);
    }

    ll res = Sum(point, p);

    cout << double(res/2) << endl;
    
    return 0;
}

#undef x
#undef y