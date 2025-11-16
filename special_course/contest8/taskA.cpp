#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

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
            std::queue<int> q;
            us[i] = true;
            q.push(i);
            int a=0; // кол-во вершин
            int b=0; // кол-во ребер

            while(!q.empty())
            {
                int tmp = q.front();
                q.pop();
                ++a;
                b += A[tmp].size();
                
                for (int v : A[tmp]) 
                {
                    if (!us[v]) 
                    {
                        us[v] = true;
                        q.push(v);
                    }
                }
            }

            b /=2;

            if(b == a - 1) res++;
        }
    }

    std::cout << res << std::endl;

    return 0;
}
