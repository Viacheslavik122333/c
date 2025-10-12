#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
using ll = long long;

bool cmp(ll x, ll y){ return x<y;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // колличесво столбиков
    ll tmp;
    cin >> n;

    vector<ll> v;
    for(int i=0; i<n; ++i) { cin >> tmp; v.push_back(tmp); }

    sort(v.begin(), v.end(), cmp);

    int count = n;
    
    int j = 0; // указатель на первый столбец с высотой > x
    for (int i = 0; i <= *(v.end()-1); ++i) // i - кол-во горизонтальных проходов 
    {
        while (j < n && v[j] <= i) 
        {
            j++;
        }
        int vertical = n - j; // кароче кол-во столбцов, которые нужно красить вертикально
        count = min(count, i + vertical);
    }

    cout << count << endl;
    return 0;
}