// #include "bits/stdc++.h"
#include "iostream"

using namespace std;
using ll = long long;

bool proof(string text)
{
    size_t t = text.size();
    char tmp = text.front();
    for (int i=1; i < t/2; ++i)
    {
        if(text[i] != tmp) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    string text;
    for(int i=0; i<t; ++i)
    {
        cin >> text;
        proof(text) ? cout << "YES" <<"\n" : cout << "NO" <<"\n"; 
    }
    return 0;
}

