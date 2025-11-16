#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n+1);

    for (int i = 0; i < m; ++i) 
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    vector<int>val(n+1, 0); // вращение 
    vector<int> res;

    for (int i = 1; i <= n; ++i) 
    {
        if (val[i] == 0) 
        {
            queue<int> q;
            q.push(i);
            val[i] = 1;
            res.push_back(i);

            while (!q.empty()) 
            {   
                int u = q.front();
                q.pop();
                
                for (int v : A[u]) 
                {
                    if (val[v] == 0) 
                    {
                        val[v] = 3 - val[u];
                        q.push(v);
                    } 
                    else if (val[v] == val[u]) 
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << res.size() << endl;

    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";

    cout << endl;
    return 0;
}

