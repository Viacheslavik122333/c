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

        Treapp::Treap t1;
	AVL_tree t2;
        std::vector<int> content;

	long long mod = pow(10, 8);

	for (int i = 0; i < n; i++) 
    {
		int typ = rd() % 3;
		if (typ == 0) 
                {
			int x = rd() % mod;
                        content.push_back(x);
			t1.insert(x);
                        t2.insert(x);
		}
		if (typ == 1) 
                {
                        // swap random with last
                        // pop_back
                        // int d = t2.find_rnd();
                        //if (rd() % 2 == 0) {
                            if(content.size()!=0)
                            {
                                int l = rd() % content.size();
                                int d = content[l];
                                content[l] = content[content.size()-1];
                                content.pop_back();
                                t1.erase(d);
                                t2.erase(d);
                            }
                        //} else {
                        //    int x = rd() % mod;
                        //    t1.erase(x);
                        //    t2.erase(x);
                        //}
		}
		if (typ == 2) 
		{
                        if(content.size()!=0)
                        {
                            int x = (rd() % 2 == 0) ? rd() % mod : content[rd() % content.size()];
                            //(void)x;
                            if (t1.find(x) != t2.find(x))
                            {
                                    std::cout << "неработает :(" << std::endl;
                                    return 0;
                            }
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
