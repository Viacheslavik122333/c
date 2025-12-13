#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SegmentTree 
{
private:
    vector<int> t;
    int n;
    
    void build(const vector<int>& arr, int v, int l, int r) 
    {
        if (l == r) {
            t[v] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*v, l, mid);
        build(arr, 2*v+1, mid+1, r);
        t[v] = t[2*v] + t[2*v+1];
    }
    
    void upd(int v, int l, int r, int pos, int val) 
    {
        if (l == r) 
        {
            t[v] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) upd(2*v, l, mid, pos, val);
            
        else upd(2*v+1, mid+1, r, pos, val);
        
        t[v] = t[2*v] + t[2*v+1];
    }
    
    int query(int v, int l, int r, int L, int R) 
    {
        if (L > r || R < l) return 0;
        if (L <= l && r <= R) return t[v];
        return query(2*v, l, (l + r) / 2, L, R) + query(2*v+1, (l + r) / 2 + 1, r, L, R);
    }
    
public:
    SegmentTree(const vector<int>& arr) 
    {
        n = arr.size();
        t.resize(4*n);
        build(arr, 1, 0, n-1);
    }
    
    void update(int pos, int val)
    {
        upd(1, 0, n-1, pos, val);
    }
    
    int rangeSum(int l, int r) 
    {
        return query(1, 0, n-1, l, r);
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.length();
    

    vector<SegmentTree> trees;
    for (int i = 0; i < 26; i++) 
    {
        vector<int> init(n, 0);
        trees.emplace_back(init);
    }
    
    for (int i = 0; i < n; i++) 
    {
        int charIndex = s[i] - 'a';
        trees[charIndex].update(i, 1);
    }
    
    int q;
    cin >> q;
    
    vector<long long> res;

    while (q--) 
    {
        int type;
        cin >> type;
        
        if (type == 1) 
        {
            int pos;
            char c;
            cin >> pos >> c;
            pos--; // в 0-индексацию
            
            int old = s[pos] - 'a';
            int new_ = c - 'a';
            
            
            trees[old].update(pos, 0); // Убираем старый символ
            
            trees[new_].update(pos, 1); // Добавляем новый символ
            
            s[pos] = c;
        } 
        else 
        {
            int l, r;
            cin >> l >> r;
            l--; r--; // в 0-индексацию
            
            int tmp = 0;
            for (int i = 0; i < 26; i++) 
            {
                if (trees[i].rangeSum(l, r) > 0) tmp++;

            }
            res.push_back(tmp);
        }
    }

    for(int i = 0; i < res.size(); ++i) cout << res[i] << "\n";
    
    return 0;
}