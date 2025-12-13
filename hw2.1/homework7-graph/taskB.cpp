#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct Graph 
{
    std::vector<std::vector<int>> g;

    Graph (int n = 1) {g.resize(n);}
    ~Graph () = default;

    void add_edge (int a, int b) 
    {
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::vector<int>& operator[] (int v) {return g[v];}
        
};


void dfs(Graph A, int v, std::vector<bool> &used) 
{
    used[v] = true;
    for (int u : A[v]) 
    {
        if (!used[u]) dfs(A, u, used);
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    if (m != n - 1)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    Graph A(n);

    int a, b;
    for (int i = 0; i < m; i++) 
    {
        std::cin >> a >> b;
        A.add_edge(a, b);
    }
    std::vector<bool> used(n, false);
    dfs(A, 0, used);

    for (int i = 0; i < n; ++i) 
    {
        if (!used[i]) 
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}
