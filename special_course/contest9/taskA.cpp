#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int INF = 1e9;

std::vector<int> dijkstra (std::vector<std::vector<std::pair<int, int>>> A, int s)
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

    return dist;
}

int main() 
{
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> markets(k);

    std::vector<bool> used_market(n, false);

    for (int i = 0; i < k; ++i) 
    {
        std::cin >> markets[i];
        markets[i]--;
        used_market[markets[i]] = true;
    }

    std::vector<std::vector<std::pair<int, int>>> A(n);

    for (int i = 0; i < m; ++i) 
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        A[a].push_back({b, c});
        A[b].push_back({a, c});
    }

    std::vector<std::vector<int>> d_market(k, std::vector<int>(n, INF)); // от рынка до каждого города

    for (int i = 0; i < k; i++) 
    {
        int start = markets[i];
        d_market[i] = dijkstra(A, start);
    }

    std::vector<std::vector<int>> market_dist(k, std::vector<int>(k, INF)); // растояние между рынками
    for (int i = 0; i < k; ++i)  
    {
        for (int j = 0; j < k; ++j) 
        {
            market_dist[i][j] = d_market[i][markets[j]];
        }
    }

    int ans = INF;
    
    for (int res = 0; res < n; ++res) 
    {
        if (used_market[res]) continue; //город с рынком
        
        bool tmp = true; // проверка постижимости рынка 
        for (int i = 0; i < k; i++) 
        {
            if (d_market[i][res] == INF) 
            {
                tmp = false;
                break;
            }
        }
        if (!tmp) continue;
        
        
        std::vector<int> perestanovka(k); // все перестановки порядка посещения рынков
        
        for (int i = 0; i < k; ++i) perestanovka[i] = i;
        
        do {

            int length = 0;
            
            // От фермы до первого рынка
            length += d_market[perestanovka[0]][res];
            
            // Между рынками по перестановке
            for (int i = 0; i < k - 1; ++i) length += market_dist[perestanovka[i]][perestanovka[i + 1]];
            
            // От последнего рынка обратно к ферме
            length += d_market[perestanovka[k - 1]][res];
            
            ans = std::min(ans, length);
            
        } while (std::next_permutation(perestanovka.begin(), perestanovka.end()));
    }

    std::cout << ans << std::endl;

    return 0;
}