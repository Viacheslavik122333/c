#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>

std::vector<int> bfs (std::vector<std::vector<int>> A, int s)
{
    std::vector<int> dist(A.size(), 0);
    std::vector<bool> used(A.size(), false);
    std::queue<int> q;
    q.push(s);
    used[s] = true;
    while(q.size()>0)
    {
        int v = q.front();
        q.pop();
        for(int u : A[v])
        {
            if(!used[u])
            {
                dist[u] = dist[v]+1;
                q.push(u);
                used[u] = true;
            }
        }
    }
    for(int i=0; i<A.size(); ++i)
    {
        if(!used[i]) dist[i]=-1;
    }
    return dist;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> A(n);

    for(int i=0; i<m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    std::vector<int> res = bfs(A, 0);
    for(int i=0; i<res.size(); ++i)
    {
        std::cout << res[i] << " ";
    }
}

