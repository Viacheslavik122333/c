#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

vector<long long> t;
vector<long long> p;
const long long INF = 1e18;

void push(int v, int l, int r)
{
    if (p[v] != 0) 
    {
        t[v] += p[v];
        if (r - l > 1) {
            p[2*v] += p[v];
            p[2*v + 1] += p[v];
        }
        p[v] = 0;
    }
}

void upd(int v, int l, int r, int L, int R, long long x)
{
    push(v, l, r);
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
        p[v] += x;
        push(v, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(2*v, l, mid, L, R, x);
    upd(2*v+1, mid, r, L, R, x);
    t[v] = min(t[2*v], t[2*v+1]);
}

long long get_min(int v, int l, int r, int L, int R)
{
    push(v, l, r);
    if (l >= R || L >= r) return INF;
    if (L <= l && r <= R) return t[v];
    int mid = (l + r) / 2;
    return min(get_min(2*v, l, mid, L, R), get_min(2*v+1, mid, r, L, R));
}

void build(vector<int>& a, int v, int l, int r)
{
    if (r - l == 1) 
    {
        if (l < a.size()) t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(a, 2*v, l, mid);
    build(a, 2*v+1, mid, r);
    t[v] = min(t[2*v], t[2*v+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    t.resize(4*n, INF);
    p.resize(4*n, 0);

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    build(a, 1, 0, n);

    int q;
    cin >> q;
    cin.ignore();

    vector<long long> res;
    while(q--)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        
        vector<int> numbers;
        int num;

        while (ss >> num) numbers.push_back(num);
        
        if (numbers.size() == 2) 
        {
            int l = numbers[0];
            int r = numbers[1];

            long long tmp;
            if (l <= r) tmp = get_min(1, 0, n, l, r + 1);
                
            else tmp = min(get_min(1, 0, n, l, n), get_min(1, 0, n, 0, r + 1));
        
            res.push_back(tmp);
        } 
        else if (numbers.size() == 3) 
        {
            int l = numbers[0];
            int r = numbers[1];
            long long x = numbers[2];

            if (l <= r) upd(1, 0, n, l, r + 1, x);
                
            else 
            {
                upd(1, 0, n, l, n, x);
                upd(1, 0, n, 0, r + 1, x);
            }
        }
    }
    
    for(int i = 0; i < res.size(); ++i) cout << res[i] << "\n";

    return 0;
}