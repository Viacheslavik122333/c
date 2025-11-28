#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>


using namespace std;

typedef long long ll;

struct SegmentTree 
{
    int n;
    vector<ll> tree;

    SegmentTree(int n) : n(n), tree(4 * n) {}

    void build(int v, int tl, int tr, const vector<ll>& arr) 
    {
        if (tl == tr) tree[v] = arr[tl];
            
        else 
        {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, arr);
            build(v * 2 + 1, tm + 1, tr, arr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void upd(int v, int tl, int tr, int pos, ll val) 
    {
        if (tl == tr) tree[v] = val;
            
        else 
        {
            int tm = (tl + tr) / 2;

            if (pos <= tm) upd(v * 2, tl, tm, pos, val);

            else upd(v * 2 + 1, tm + 1, tr, pos, val);

            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) 
    {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
               
    }

    // Бинарный поиск
    int find(ll target) 
    {
        int v = 1, tl = 1, tr = n;
        while (tl < tr) 
        {
            int tm = (tl + tr) / 2;
            if (tree[v * 2] > target) 
            {
                v = v * 2;
                tr = tm;
            } 
            else 
            {
                target -= tree[v * 2];
                v = v * 2 + 1;
                tl = tm + 1;
            }
        }
        return tl;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> s[i];

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i) arr[i] = i;
        

    SegmentTree seg(n);
    seg.build(1, 1, n, arr);

    vector<int> p(n + 1);

    for (int i = n; i >= 1; --i) 
    {

        int low = 1, high = n, ans = n;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            ll sum = seg.query(1, 1, n, 1, mid - 1);
            if (sum <= s[i]) 
            {
                ans = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        
        p[i] = ans;
        seg.upd(1, 1, n, ans, 0); // удаляем ans
    }

    for (int i = 1; i <= n; ++i) cout << p[i] << " ";

    cout << "\n";

    return 0;
}