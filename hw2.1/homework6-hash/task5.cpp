#include <iostream>
#include <vector>
#include <string>
#include <utility> // pair

const long long base = 31;
const long long mod = 1e9 + 7;

std::vector<int> pow_base;
std::vector<int> hash_v;

long long getHash(int l, int r) 
{
    if (l > r) return 0;
    int len = r - l + 1;
    long long h = (hash_v[r+1] - hash_v[l] * pow_base[len] % mod + mod) % mod;
    return h;
}


struct cmp
{
private:
    std::string s;
public:
    cmp(const std::string str){s = str;}

    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        int l1 = a.first, r1 = a.second;
        int l2 = b.first, r2 = b.second;
        int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        int low = 0, high = std::min(len1, len2);
        

        while (low <= high) 
        {
            int mid = (low + high) / 2;
            long long h1 = getHash(l1, l1 + mid - 1);
            long long h2 = getHash(l2, l2 + mid - 1);
            if (h1 == h2) low = mid + 1;    
            else high = mid - 1;

        }
        
        int tmp = high;
        if (tmp == len1 && tmp == len2) return false; //  равны
        if (tmp == len1) return true;
        if (tmp == len2) return false; 
        

        return static_cast<long long>(s[l1 + tmp]) < static_cast<long long>(s[l2 + tmp]);
    }
};

int main()
{
    std::string s;
    std::cout << "Введите s: "; std::cin >> s;
    int n = s.length(), t;
    std::cout << "Введите кол-во подстрок: "; std::cin >> t;

    std::vector<std::pair<int,int>> v;
    for(int i=0; i<t; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back({a-1, b});
    }

    pow_base.resize(n+1, 1);
    hash_v.resize(n+1, 0);
    
    for (int i = 1; i <= n; i++) 
    {
        pow_base[i] = (pow_base[i-1] * base) % mod;
        hash_v[i] = (hash_v[i-1] * base + s[i-1]) % mod;
    }

    cmp tmp(s);

    std::sort(v.begin(), v.end(), tmp);

    for(int i=0; i<t; ++i)
    {
        for(int j=v[i].first; j< v[i].second; ++j)
        {
            std::cout << s[j];
        }
        std::cout << std::endl;
    }

    return 0;
}


