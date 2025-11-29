//Реализация дискретного логарифма

#include "primitive_root.h"
// const int p = 1e9+9;

ll discrete_log(ll g, ll a, ll p)
{
    if (a == 1) return 0;
        

    ll M = sqrt(p - 1);
    while (M * M < p - 1) ++M;

    std::unordered_map<ll, ll> baby_steps; // Хеш-таблица для хранения значений a*g^0, a*g^1, ... , a*g^(M-1)

    ll tmp = a % p;

    for (ll j = 0; j < M; ++j) 
    {
        baby_steps[tmp] = j;
        tmp = (tmp * g) % p;
    }

    ll giant_step = pow_mod(g, M, p);
    tmp = 1;

    for (ll i = 1; i <= M; ++i) 
    {
    
        if (baby_steps.find(tmp) != baby_steps.end())
        {
            ll res = i * M - baby_steps[tmp];

            if (res < 0) res += (p - 1);
            
            return res;
        }

        tmp = (tmp * giant_step) % p;
    }
    return -1;
}
    
int main()
{
    ll p, g, a;
    std::cout << "p, a: ";
    std::cin >> p >> a;

    g = primitive_root(p);

    std::cout << "Первообразный корень g = " << g << std::endl;

    ll y = discrete_log(g, a, p);

    std::cout << y << std::endl;
    return 0;
}