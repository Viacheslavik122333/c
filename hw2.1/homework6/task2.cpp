#include <iostream>
#include <vector>
#include <string>

// хеш от l до r
long long getHash(size_t l, size_t r, std::vector<long long> prefix_hash, std::vector<long long> powers_base, long long mod)     
{
    long long h = (prefix_hash[r + 1] - prefix_hash[l] * powers_base[r - l + 1] % mod + mod) % mod;
    return h;
}

std::vector<int> fun(const std::string& s, const std::string& t) 
{
    size_t n = s.length();
    size_t m = t.length();

    if (m > n || m == 0) return {};

    const long long base = 31;
    const long long mod = 1e9 + 9;

    
    std::vector<long long> powers_base(n + 1, 1);
    for (size_t i = 1; i <= n; ++i) 
    {
        powers_base[i] = (powers_base[i - 1] * base) % mod;
    }

    // хеш первых i символов
    std::vector<long long> prefix_hash(n + 1, 0);
    for (size_t i = 1; i <= n; ++i) 
    {
        prefix_hash[i] = (prefix_hash[i - 1] * base + static_cast<long long>(s[i - 1])) % mod;
    }


    long long hash_t = 0;
    for (char ch : t) 
    {
        hash_t = (hash_t * base + static_cast<long long>(ch)) % mod;
    }


    std::vector<int> res;

    for (size_t i = 0; i <= n - m; ++i) 
    {
        if (getHash(i, i + m - 1, prefix_hash, powers_base, mod) == hash_t) 
        {
            bool tmp = true;

            for (size_t j = 0; j < m; ++j) // для избежания коллизий (явная проверка)
            {
                if (s[i + j] != t[j]) 
                {
                    tmp = false;
                    break;
                }
            }

            if (tmp) 
            {
                res.push_back((int)i);
            }
        }
    }

    return res;
}

int main() 
{
    std::string s, t;
    std::cout << "Введите s: ";
    std::cin >> s;
    std::cout << "Введите t: ";
    std::cin >> t;

    std::vector<int> result = fun(s, t);

    if (result.empty()) std::cout << "нету :(" << std::endl;    
    else 
    {
        for (int i : result) std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}