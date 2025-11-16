#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n+1);

    for (int i = 0; i < n-1; ++i) 
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    vector<int>col(n+1);
    for(int i=1; i<=n; ++i) cin >> col[i];

    bool tmp = true;
    for (int i = 2; i <= n; i++) 
    {
        if (col[i] != col[1]) 
        {
            tmp = false;
            break;
        }
    }
    if (tmp) 
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }

    vector<int> count(n + 1, 0);

    for (int u = 1; u <= n; u++) 
    {
        for (int v : A[u]) 
        {
            if (col[u] != col[v]) count[u]++;
        }
    }

    int res = 0;
    for (int u = 1; u <= n; u++) res += count[u];

    res /= 2;

    for (int i = 1; i <= n; i++) 
    {
        if (count[i] == res) 
        {
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}