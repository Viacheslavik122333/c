#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> A(n, std::vector<int>(n));

    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) std::cin >> A[i][j];

    std::vector<int> X(n);

    for(int i=0; i<n; ++i) std::cin >> X[i];

    std::vector<bool> prof(n, false);

    std::vector<long long> ans(n);


    for(int i=n-1; i>=0; --i)
    {
        int k = X[i] - 1;
        prof[k] = true;

        for (int u = 0; u < n; ++u) 
        {
            for (int v = 0; v < n; ++v) 
            {
                A[u][v] = std::min(A[u][v], A[u][k] + A[k][v]);
            }
        }

        long long sum = 0;

        for (int u = 0; u < n; ++u) 
        {
            if (!prof[u]) continue;

            for (int v = 0; v < n; ++v) 
            {
                if (!prof[v]) continue;

                sum += A[u][v];
            }
        }
        ans[i] = sum;
    }

    for (int i = 0; i < n; i++) std::cout << ans[i] << " ";

    return 0;
}