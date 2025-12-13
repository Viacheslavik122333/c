#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>

int min_d(std::vector<int>& dist, std::vector<bool>& used, long long INF)
{
    int ans = -1;
    for(int v = 0; v < dist.size(); ++v) 
    {
        if(used[v] || dist[v] == INF) continue;
        if(ans == -1 || dist[ans] > dist[v]) ans = v;
    }
    return ans;
}

std::vector<int> dijkstra (std::vector<std::vector<std::pair<int, int>>> A, int s, long long INF)
{
    std::vector<int> dist(A.size(), INF);
    std::vector<bool> used(A.size(), false);
    dist[s] = 0;
    for(int i=0; i<A.size(); ++i)
    {
        int v = min_d(dist, used, INF);
        if(v == -1) continue;
        used[v] = true;
        for(std::pair<int, int> u : A[v])
        {
            dist[u.first] = std::min(dist[u.first], dist[v]+u.second);
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