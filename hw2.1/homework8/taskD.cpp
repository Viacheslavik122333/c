#include <iostream>
#include <vector>

const int INF = 1e9;

void Floyd(std::vector<std::vector<int>>& dist)
{
    for (int k = 0; k < dist.size(); ++k) 
    {
        for (int i = 0; i < dist.size(); ++i) 
        {
            for (int j = 0; j < dist.size(); ++j) 
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = std::min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }
}

int main() 
{
    int n;
    std ::cin >> n;
    
    std::vector<std::vector<int>> dist(n, std::vector<int>(n));
    
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            int x;
            std::cin >> x;
            if (x == -1) dist[i][j] = INF;
            else dist[i][j] = x;                
        }
    }

    Floyd(dist);
    
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (dist[i][j] >= INF) std::cout << -1;
            else std::cout << dist[i][j];
            if (j < n - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}