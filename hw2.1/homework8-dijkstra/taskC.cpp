#include <iostream>
#include <vector>
#include <utility>

const int INF = 1e9;

bool Bellman_Ford(const std::vector<std::vector<std::pair<int, int>>>& A)
{
    std::vector<int> dist(A.size(), 0);
    dist[0] = 0;
    
    for (int iter = 0; iter < A.size() - 1; ++iter)
    { 
        for (int v = 0; v < A.size(); ++v) 
        {
            for (std::pair<int, int> u : A[v]) 
            {
                dist[u.first] = std::min(dist[u.first], dist[v] + u.second);
            }
        }
    }

    for (int v = 0; v < A.size(); ++v) 
    {
        for (std::pair<int, int> u : A[v]) 
        {
            if (dist[v] + u.second < dist[u.first]) 
            {
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> A(n);
    
    for(int i=0; i<m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a; --b;
        A[a].push_back({b, c});
    }

    bool res = Bellman_Ford(A);
    
    std::cout << (res ? "YES" : "NO") << std::endl;
    
    return 0;
}