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

int dfs (Graph &A, int v, std::vector<bool> &us) 
{
    // us = 1, если вершина посещена, иначе = 0
    us[v] = true;
    int sm = 1;
    for (int u: A[v]) 
    {
        if (!us[u]) sm += dfs(A, u, us);
    }
    return sm; // вернули количество вершин в компоненте связности
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    Graph A(n);

    int a, b;
    for (int i = 0; i < m; i++) 
    {
        std::cin >> a >> b;
        A.add_edge(a, b);
    }

    std::vector<bool> us(n, false);
    int res = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!us[i]) 
        {
            res++; 
            dfs(A, i, us);
        }
    }

    std::cout << res << std::endl;

    return 0;
}