#include <iostream>
#include <vector>
#include <queue>

void dfs (std::vector<std::string>& v, int i, int j, int m, int n, std::vector<std::vector<bool>>& used) 
{
    if (i < 0 || j < 0 || i > m-1 || j > n-1) return;
    if (v[i][j] == '.' || used[i][j] == true) return;

    used[i][j] = true;

    dfs(v, i - 1, j, m, n, used); // вверх
    dfs(v, i, j - 1, m, n, used); // влево
    dfs(v, i + 1, j, m, n, used); // вниз
    dfs(v, i, j + 1, m, n, used); // вправо
}


int main() 
{
    int n, m;
    std::cin >> m >> n;

    std::vector<std::string> v(m);
    for (int i = 0; i < m; ++i) std::cin >> v[i];
    

    std::vector<std::vector<bool>> used(m, std::vector<bool>(n, false));
    
    int res = 0;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (!used[i][j] && v[i][j] == 'O') 
            {
                res++;
                dfs(v, i, j, m, n, used);
            }
        }
    }

    std::cout << res << std::endl;
    return 0;
}