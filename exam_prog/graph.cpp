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
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::vector<int>& operator[] (int v) {return g[v];}

    int size() const { return g.size(); }
        
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

int bfs (Graph &A, int v) 
{
    int n = A.size();
    std::vector<bool> us(n, false);
    std::queue<int> q;
    int start = 0;
    us[start] = true;
    q.push(start);
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        
        // Обрабатываем соседей
        for (int w : A[v])
        {
            if (!us[w])
            {
                us[w] = true;
                q.push(w);
            }
        }
    }
}