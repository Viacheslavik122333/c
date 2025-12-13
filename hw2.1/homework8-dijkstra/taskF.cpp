#include <iostream>
#include <vector>
#include <utility>
#include <set>

const int INF = 1e9;

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> market(k);
    for(int i=0; i<k; ++i)
    {
        int a;
        std::cin >> a;
        market[i] = a-1;
    } 

    std::vector<std::vector<int>> A(n, std::vector<int>(n, INF));

    for(int i=0; i<n; ++i) A[i][i] = 0;

    for(int i=0; i<m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        A[a-1][b-1]=c;
        A[b-1][a-1]=c;   
    }

    for(int d=0; d<n; ++d)
    {
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                A[i][j] = std::min(A[i][j], A[i][d] + A[d][j]);
            }
        }
    }

    int res=INF;
    int tmp=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<k; ++j)
        {
            tmp += A[i][market[j]];
        }
        res = std::min(res, tmp);
        tmp=0;
    }

    std::cout << res << std::endl;
    
}