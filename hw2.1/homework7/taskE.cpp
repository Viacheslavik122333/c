#include <iostream>
#include <fstream>
#include <vector>


bool dfs(std::vector<std::vector<int>>&A, int v, std::vector<int>& used) 
{
    used[v] = 1; // 1 - сейчас находимся, 2 - уже вышли, 0 - ещё не вошли

    for(int u=0; u<A.size(); ++u) 
    {
        if(A[v][u]==1)
        {
            if(used[u] == 1) return true;
        
            else if(used[u] == 2) continue;

            if(dfs(A, u, used)) return true;
        }
        
    }
    used[v] = 2;
    return false;
}

int main()
{
    std::ifstream fin ("cycle.in");
    if (!fin) return -1;

    std::ofstream fout ("cycle.out");
    if (!fout) 
    {
        fin.close();
        return -1;
    }

    int n;
    fin >> n;
    std::vector<std::vector<int>> A(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) 
    {
        for(int j=0; j<n; ++j)
        {
            fin >> A[i][j];
        }
    }

    std::vector<int> used(n, 0);

    for(int i=0; i<n; ++i)
    {
        if(used[i]==0)
        {
            if(dfs(A, i, used)) 
            {
                fout << 1 << std::endl;
                return 0;
            }
        }
        
    }
    fout << 0 << std::endl;

    fin.close();
    fout.close();

    return 0;
}