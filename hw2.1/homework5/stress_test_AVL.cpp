#include "iostream"
#include "algorithm"
#include "utility"
#include "cmath"
#include "ctime"
#include "random"

#include "AVL.h"
#include "Treap.h"


int stressTest (int n) 
{
    std::mt19937 rd(time(NULL));

	Treap t1;
	AVL_tree t2;

	long long mod = pow(10, 8);

	for (int i = 0; i < n; i++) 
    {
		int typ = rd() % 3;
		if (typ == 0) 
        {
			int x = rd() % mod;
			t1.insert(x);
			t2.insert(x);
		}
		if (typ == 1) 
        {
			int d = t2.find_rnd();
			t1.erase(d);
			t2.erase(d);
		}
		if (typ == 2) 
		{
			int x = (rd() % 2 == 0) ? rd() % mod : t2.find_rnd();
			if (t1.find(x) != t2.find(x)) 
			{
				std::cout << "хаха - неработает :(" << std::endl;
				return 0;
			}
		}
	}
	return 1;
}


int main()
{
	int n;
	std::cin >> n;
    if(stressTest(n)) std::cout << "все правильно работает :)" << std::endl;
    return 0;
}
