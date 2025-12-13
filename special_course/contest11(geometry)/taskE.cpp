#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>

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
    ll cross = prod(a.x - p.x, a.y - p.y, b.x - p.x, b.y - p.y);
    if (cross != 0) return cross > 0; // против часовой стрелки...

    ll dist1 = (a.x - p.x)*(a.x - p.x) + (a.y - p.y)*(a.y - p.y);
    ll dist2 = (b.x - p.x)*(b.x - p.x) + (b.y - p.y)*(b.y - p.y);

    return dist1 < dist2;
}

ll fun(vector<pair<int, int>> point) 
{
    int m = point.size();

    ll res = 0;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 2; j < m; ++j)
        {
            int k = i + 1;
            ll area1 = 0;

            for (int t = i + 1; t < j; ++t) 
            {
                ll tmp = abs(prod(
                    point[j].x - point[i].x, 
                    point[j].y - point[i].y,
                    point[t].x - point[j].x, 
                    point[t].y - point[j].y));

                if (tmp > area1) 
                {
                    area1 = tmp;
                    k = t;
                }
            }

            int l = (j + 1) % m;
            ll area2 = 0;

            for (int t = j + 1; t < j + m; ++t) 
            {
                int idx = t % m;
                if (idx == i) break;

                ll tmp = abs(prod(
                    point[j].x - point[i].x, 
                    point[j].y - point[i].y,
                    point[idx].x - point[j].x, 
                    point[idx].y - point[j].y));

                if (tmp > area2) 
                {
                    area2 = tmp;
                    l = idx;
                }
            }
            res = max(res, area1 + area2);
        }
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
    }

    for (auto pt : v) 
    {
        if (pt.y < p.y || (pt.y == p.y && pt.x < p.x)) p = pt;
    }
    
    vector<pair<int, int>> point;
    // point.push_back(p);

    std::sort(v.begin(), v.end(), cmp);

    point.push_back(v[0]); // p
    point.push_back(v[1]);

    // for(int i=0; i<n; ++i) cout << v[i].x << " " << v[i].y << "\n";

    for(int i=2; i<n; ++i) // линейная оболочка
    {
        while(prod(
            (*(point.end()-1)).x - (*(point.end()-2)).x, 
            (*(point.end()-1)).y - (*(point.end()-2)).y,  
            v[i].x - (*(point.end()-1)).x, 
            v[i].y - (*(point.end()-1)).y
            ) <0 )
        {
            // cout << (*(point.end()-1)).x << " " << (*(point.end()-1)).y << "\n";
            point.pop_back();
        }
        point.push_back(v[i]);
    }


    ll res = 0;
    if(point.size() > 3) res = fun(point);

    else
    { 
        ll bigArea = abs(prod(
            point[1].x - point[0].x, 
            point[1].y - point[0].y, 
            point[2].x - point[0].x, 
            point[2].y - point[0].y));

        ll minvalue = 1e12;

        for(auto pt : v) // ищем неиспользовунные точки
        {
            bool flag = 0;
            for(auto tmp : point)
            {
                if(tmp.x == pt.x && tmp.y == pt.y) 
                {
                    flag = 1;
                    break;
                }
            }

            if(flag) continue;

            ll smallArea1 = abs(prod(
                point[1].x - point[0].x, 
                point[1].y - point[0].y, 
                pt.x - point[0].x, 
                pt.y - point[0].y));

            ll smallArea2 = abs(prod(
                point[2].x - point[1].x, 
                point[2].y - point[1].y, 
                pt.x - point[1].x, 
                pt.y - point[1].y));

            ll smallArea3 = abs(prod(
                point[2].x - point[0].x, 
                point[2].y - point[0].y, 
                pt.x - point[0].x, 
                pt.y - point[0].y));

            ll cur = min({smallArea1, smallArea2, smallArea3});
            minvalue = min(minvalue, cur);
        }
        res = bigArea - minvalue;
    }
    
    cout << fixed << setprecision(1) << double(res)/2.0 << endl;
    
    return 0;
}

#undef x
#undef y