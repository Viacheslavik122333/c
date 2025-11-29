// Алгоритм Тонелли — Шенкса (названный Шенксом алгоритмом RESSOL)
// x^2 == a (mod p)

#include "primitive_root.h"

ll ressol (ll a, ll p)
{
    // p-1 = Q * 2^S
    ll Q = p - 1;
    ll S = 0;
    while (Q % 2 == 0) 
    {
        Q /= 2;
        ++S;
    }
    
    // квадратичный невычет z
    ll z = 2;
    while (pow_mod(z, (p - 1) / 2, p) == 1) ++z;
        
    ll M = S;
    ll c = pow_mod(z, Q, p);
    ll R = pow_mod(a, (Q + 1) / 2, p);
    ll t = pow_mod(a, Q, p);
    
    
    while (t != 1) 
    {
        // надо: t^(2^i) == 1 (mod p)
        ll i = 0;
        ll tmp = t;

        while (tmp != 1) 
        {
            tmp = (tmp * tmp) % p;
            ++i;
        }
        
        ll b = pow_mod(c, pow_mod(2, M - i - 1), p);
        R = (R * b) % p;
        t = (t * b % p * b) % p;
        c = (b * b) % p;
        M = i;
    }
    
    return R;
}

int main()
{
    ll p, a;
    std::cout << "p, a: ";
    std::cin >> p >> a;

    if (p == 2) 
    {
        if (a % 2 == 1) std::cout << "Ответ: 1" << std::endl;
        else std::cout << "Ответ: 0" << std::endl;
        return 0;
    }

    ll res = ressol(a, p);

    if(res!= -1) std::cout << "Ответ: " << res << " и " << p - res<< std::endl;

    else std::cout << "Нет решения :( " << std::endl;
    
    return 0;
}