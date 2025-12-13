#include "Treap.h"

#include "iostream"
#include "vector"
#include "ctime"


int main()
{
    srand(time(NULL));
    
    for (long long n=99; n<1e7; n*=10) // колличесво элементов в дереве (массиве) и mod элемента
    {
        int x = rand()%n, res;
        std::vector<int> v(n);

        Treap tree; 

        for(long long i=0; i<n; ++i)
        {
            v[i] = rand()%n;
        }

        for(long long i=0; i<n; ++i)
        {
            tree.insert(v[i]);
        } // проверка через дерево

        sort(v.begin(), v.end());
        for(long long i=0; i<n; ++i)
        {
            if(v[i] >= x)
            {
                res = v[i];
                break;
            } 
        } // сам стресс-тест
        

        std::cout << "res = " << res << " : tree.lower_bound(x) = " << tree.lower_bound(x) << "\n";
    }
    
    return 0;
}