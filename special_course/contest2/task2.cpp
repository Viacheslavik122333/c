#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
using ll = long long;

struct N
{
    ll a;
    int i;
    N(ll x, int index) {a = x; i = index+1;}
};

bool cmp(N x, N y){ return x.a<y.a;}
bool cmp2(N x, N y){ return x.i<y.i;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; // колличесво детей
    int count=0;
    ll tmp;
    cin >> n;

    vector<N> v;
    for(int i=0; i<n; ++i)
    {
        cin >> tmp;
        N node(tmp, i);
        v.push_back(node);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n-1; ++i)
    {
        if((v[i]).a >= (v[i+1]).a)
        {
            (v[i+1]).a = (v[i]).a + 1;
        }
    }

    sort(v.begin(), v.end(), cmp2); 

    for(int i=0; i<n; ++i)
    {
        cout << (v[i]).a << " ";
    }

    return 0;
}