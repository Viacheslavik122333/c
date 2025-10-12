#include "update_treap.h"

#include "iostream"
#include "algorithm"
#include "vector"
#include "ctime"

int main()
{
    srand(time(NULL));
    
    for (long long n=10; n<1e7; n*=5) // колличесво элементов в дереве (массиве)
    {

        std::vector<int> v(n);

        Treap tree; 

        for(long long i=0; i<n; ++i)
        {
            v[i] = rand()%(n*100);
        }

        sort(v.begin(), v.end());

        auto last = std::unique(v.begin(), v.end());
        v.erase(last, v.end());                      // удаляем дубликаты
        
        n = v.size();

        int k = rand()%n;
        int res = v[k-1];

        int j=0;
        for(int i=0; i<n; ++i)
        {
            if(v[i]>k){j = i; break;}
        }

        for(long long i=0; i<n; ++i)
        {
            tree.insert(v[i]);
        }

        std::cout << "k = " << k << " : res = " << res << " : tree.k_statistics(x) = " << tree.k_statistics(k) << "\n";
        std::cout << "k = " << k << " : j = " << j << " : tree.quantity(k) = " << tree.quantity(k) << "\n";
        // std::cout << n << std::endl;
    }
    
    return 0;
}