#include <iostream>
#include <vector>
#include <utility>
#include <set>

std::vector<int> dijkstra (std::vector<std::vector<std::pair<int, int>>> A, int s, long long INF)
{
    std::vector<int> dist(A.size(), INF);

    std::set<std::pair<int,int>> cur;

    dist[s] = 0;
    cur.insert({0, s});

    while(cur.size()!=0)
    {
        int v = cur.begin()->second;
        cur.erase({dist[v], v});
        for(std::pair<int ,int> u : A[v])
        {
            if(dist[u.first] > dist[v] + u.second)
            {
                cur.erase({dist[u.first], u.first});
                dist[u.first] = dist[v] + u.second;
                cur.insert({dist[u.first], u.first});
            }
        }
    }
    for(int i=0; i<A.size(); ++i)
    {
        if(dist[i] == INF) dist[i]=-1;
    }
    return dist;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> A(n);

    long long INF=1;

    for(int i=0; i<m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a; --b;
        A[a].push_back({b, c});
        A[b].push_back({a, c});
        INF +=c;
    }
    std::vector<int> res = dijkstra(A, 0, INF);
    for(int i=0; i<res.size(); ++i)
    {
        std::cout << res[i] << " ";
    }
}