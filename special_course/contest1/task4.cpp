#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Box 
{
    int matches;
    ll count;      
};

bool compare(const Box& a, const Box& b) 
{
    return a.matches > b.matches;  //сортируем по убыванию
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int m;
    cin >> n >> m;
    
    vector<Box> boxes(m);
    for (int i = 0; i < m; ++i) 
    {
        ll count;
        int matches;
        cin >> count >> matches;
        boxes[i] = {matches, count};
    }


    sort(boxes.begin(), boxes.end(), compare);

    ll total_matches = 0;
    
    for (int i = 0; i < m && n > 0; ++i) 
    {
        if (boxes[i].count >= n) 
        {
            total_matches += n * boxes[i].matches;
            n = 0;
        } 
        else 
        {
            total_matches += boxes[i].count * boxes[i].matches;
            n -= boxes[i].count;
        }
    }
    
    cout << total_matches << "\n";
    return 0;
}