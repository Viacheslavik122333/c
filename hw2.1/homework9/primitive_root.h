#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using ll = long long;

long long pow_mod(long long pw, long long n, long long p) 
{
    long long res = 1;
    pw %= p;
    while (n > 0) 
    {
        if (n % 2 == 1) res = (res * pw) % p;

        pw = (pw * pw) % p;

        n /= 2;
    }
    return res;
}

long long pow_mod(long long pw, long long n) 
{
    long long res = 1;
    while (n > 0) 
    {
        if (n % 2 == 1) res = (res * pw);

        pw = (pw * pw);

        n /= 2;
    }
    return res;
}


std::vector<long long> prime_factors(long long n) 
{
    std::vector<long long> factors;
    long long d = 2;
    while (d * d <= n)
    {
        if (n % d == 0) 
        {
            factors.push_back(d);
            
            while (n % d == 0) n /= d;
        }
        ++d;
    }

    if (n > 1) factors.push_back(n);
        
    return factors;
}


long long primitive_root(long long p) 
{
    if (p == 2) return 1;
    
    std::vector<long long> factors = prime_factors(p - 1);
    
    for (long long g = 2; g < p; ++g) 
    {
        bool ok = true;

        for (long long q : factors) 
        {
            if (pow_mod(g, (p - 1) / q, p) == 1) 
            {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
    return -1;
}