#include <iostream>
#include <vector>
#include <string>
#include <cmath>

const long long base = 31;
const long long mod = 1e9 + 7;

std::vector<long long > pow_base(1e5+1, 1);
std::vector<long long > hash_v(1e5+1, 0);

std::vector<int> depth(1e5+1 + 1); // глубина i вершины
std::vector<int> parent(1e5+1 + 1); // родитель i вершины
std::vector<std::vector<int>> up (1e5+1, std::vector<int>(18));

void power(int n) 
{
    for (int i = 1; i <= n; i++) pow_base[i] = (pow_base[i - 1] * base) % mod;
}

long long stringHash(std::string s) 
{
    long long k = 0;
    for (char c : s) k = (k * base + c) % mod;
    return k;
}

void dfs(int u, int p, std::vector<char> letters, std::vector<int> tree[]) 
{
    parent[u] = p;
    depth[u] = depth[p] + 1;
    
    if (p == 0) hash_v[u] = letters[u] % mod;

    else hash_v[u] = (hash_v[p] * base + letters[u]) % mod;

    
    up[u][0] = p;
    for (int j = 1; j <= 17; ++j) 
    {
        if (up[u][j - 1] != 0) up[u][j] = up[up[u][j - 1]][j - 1];
        else up[u][j] = 0;
    }
    
    for (int v : tree[u]) 
    {
        if (v == p) continue;
        dfs(v, u, letters, tree);
    }
}

int rise (int u, int k) // подъем на k уровней по дереву
{
    if (k == 0) return u;
    
    for (int j = 0; j <= 17; j++) 
    {
        int tmp = 1;
        for (int i = 0; i < j; i++) tmp *= 2;
        
        if (k >= tmp && (k / tmp) % 2 == 1) 
        {
            u = up[u][j];
            if (u == 0) break;
        }
    }
    return u;
}

int main()
{

    std::string s;
    std::cout << "Введите s: "; std::cin >> s;
    int t = s.length(); // длина s
    int  n; // кол-во вершин
    std::cout << "Введите кол-во вершин: "; std::cin >> n;
    

    std::vector<int> tree[(int)1e5 + 1]; // дерево
    std::vector<char> letters((int)1e5 + 1); // буквы в вершинах

    std::cout << "Введите связи: " << std::endl;
    for (int i = 0; i < n - 1; ++i) // заполняем дерево
    {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    std::cout << "Введите вершины (буквы): " << std::endl;
    for(int i=1; i<=n; ++i) std::cin >> letters[i]; // заполняем вершины

    power(n);
    long long target_hash_s = stringHash(s);

    depth[0] = -1;
    dfs(1, 0, letters, tree);


    int count = 0;

    for (int i = 1; i <= n; ++i) 
    {
        if (depth[i] < t - 1) continue;
        
        int u = rise(i, t - 1);
        if (u == 0) continue;
        
        long long current_hash;
        if (parent[u] == 0) current_hash = hash_v[i];
            
        else 
        {
            current_hash = (hash_v[i] - hash_v[parent[u]] * pow_base[t] % mod + mod) % mod;
        }
        
        if (current_hash == target_hash_s) count++;
    }
    
    std::cout << count << std::endl;

    return 0;
}