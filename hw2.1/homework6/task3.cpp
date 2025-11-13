#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


// хеш от l до r
long long getHash(size_t l, size_t r, 
                  const std::vector<long long>& prefix_hash, 
                  const std::vector<long long>& powers_base, 
                  long long mod)
{
    long long h = (prefix_hash[r + 1] - prefix_hash[l] * powers_base[r - l + 1] % mod + mod) % mod;
    return h;
}

std::string reverse (const std::string& s)
{
    std::string rev_s = s;
    for(int i=0; i < s.length(); ++i) rev_s[s.length()-i-1] = s[i];
    return rev_s; 
}

bool isPalindrome(size_t l, size_t r, size_t n,
                const std::vector<long long>& prefix_hash,
                const std::vector<long long>& prefix_hash_rev,
                const std::vector<long long>& powers_base,
                long long mod)
{
    if (l < 0 || r >= n) return false;
    long long tmp = getHash(l, r, prefix_hash, powers_base, mod);
    long long tmp_rev = getHash(n - 1 - r, n - 1 - l, prefix_hash_rev, powers_base, mod);
    return tmp == tmp_rev;
}

int fun(const std::string& s) 
{
    int res = 1;
    size_t n = s.length();

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

    // обратная срока
    std::string rev_s = reverse(s);

    std::vector<long long> prefix_hash_rev(n + 1, 0);
    for (size_t i = 1; i <= n; ++i) 
    {
        prefix_hash_rev[i] = (prefix_hash_rev[i - 1] * base + static_cast<long long>(rev_s[i - 1])) % mod;
    }


    // нечётные
    for (int i = 0; i < n; ++i) 
    {
        int low = 0, high = std::min(i, (int)n - 1 - i) + 1;
        while (low < high) 
        {
            int mid = (low + high) / 2;
            int l = i - mid;
            int r = i + mid;
            if (isPalindrome(l, r, n, prefix_hash, prefix_hash_rev, powers_base, mod)) low = mid + 1;    
            else high = mid;
        }
        res = std::max(res, 2 * (low - 1) + 1);
    }

    // чётные
    for (int i = 0; i < n - 1; ++i) 
    {
        int low = 0, high = std::min(i + 1, (int)n - 1 - i);

        while (low < high) 
        {
            int mid = (low + high) / 2;
            int l = i - mid + 1;
            int r = i + mid;
            if (isPalindrome(l, r, n, prefix_hash, prefix_hash_rev, powers_base, mod)) low = mid + 1;
            else high = mid;

        }
        res = std::max(res, 2 * (low - 1));
    }

    return res;
}

int main() 
{
    std::string s;
    std::cout << "Введите s: ";
    std::cin >> s;

    int res = fun(s);

    if (res == 0) std::cout << "нету :(" << std::endl;  
    else std::cout << res << std::endl;
    return 0;
}