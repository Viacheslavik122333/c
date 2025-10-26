#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "utility" // для pair

using namespace std;
using ll = unsigned long long;

ll fun (ll a, ll b, ll p)
{
    ll prod = 1;
    ll mlt = a;
    while (b)
    {
        if(b & 1)
        {
            prod = (prod * mlt) % p;
        }
        b >>= 1;
        mlt = (mlt * mlt) % p;
    }
    return prod;
}


int main()
{
    ll a = 10;
    ll b = 2;
    ll p = 91;
    cout << fun(a, b, p) << endl;

    

    return 0;
}