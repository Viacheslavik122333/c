#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node 
{
    int open;   // открывающие
    int close;  // закрывающие
    int full;   // Количество полных пар скобок
};

class SegmentTree 
{
private:
    vector<Node> tree;
    string s;
    int n;

    Node combine(Node left, Node right) 
    {
        Node res;
        int new_pairs = min(left.open, right.close);
        res.full = left.full + right.full + new_pairs;
        res.open = left.open + right.open - new_pairs;
        res.close = left.close + right.close - new_pairs;
        return res;
    }

    void build(int idx, int l, int r) 
    {
        if (l == r) 
        {
            if (s[l] == '(') tree[idx] = {1, 0, 0};
                
            else tree[idx] = {0, 1, 0};
    
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) 
    {
        if (ql <= l && r <= qr) return tree[idx];
            
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2 * idx, l, mid, ql, qr);
            
        else if (ql > mid) return query(2 * idx + 1, mid + 1, r, ql, qr);
            
        else 
        {
            Node left = query(2 * idx, l, mid, ql, qr);
            Node right = query(2 * idx + 1, mid + 1, r, ql, qr);
            return combine(left, right);
        }
    }

public:
    SegmentTree(const string& str) : s(str) 
    {
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int getMaxLength(int l, int r) 
    {
        Node res = query(1, 0, n - 1, l - 1, r - 1);
        return res.full * 2;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int q;
    cin >> q;

    SegmentTree st(s);

    for (int i = 0; i < q; i++) 
    {
        int l, r;
        cin >> l >> r;
        cout << st.getMaxLength(l, r) << '\n';
    }

    return 0;
}