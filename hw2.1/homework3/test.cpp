#include <iostream>
#include <vector>
using std::endl;
using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;


bool _checkBST(int v, int& min_val, int& max_val, vector<int>& val, vector<int>& lft, vector<int>& rgt) {
    if (v == 0) return true;
    
    int lmin, lmax, rmin, rmax;
    lmin = lmax = rmin = rmax = val[v];
    
    bool lval = true;
    bool rval = true;

    if (lft[v] != 0) {
        lval = _checkBST(lft[v], lmin, lmax, val, lft, rgt);
        if (lmax >= val[v]) {
            lval = false;
        }
    }

    if (rgt[v] != 0) {
        rval = _checkBST(rgt[v], rmin, rmax, val, lft, rgt);
        if (rmin <= val[v]) {
            rval = false;
        }
    }
    
    min_val = min(lmin, val[v]);
    max_val = max(rmax, val[v]);
    
    return lval && rval;
}

int main() {
    int i;
    int n;
    vector<int> val;
    vector<int> lft;
    vector<int> rgt;
    cin >> n;
    
    val.resize(n + 1);
    lft.resize(n + 1);
    rgt.resize(n + 1);
    
    for (i = 1; i <= n; i++) {
        cin >> val[i];
    }
    
    for (i = 1; i <= n; i++) {
        cin >> lft[i] >> rgt[i];
    }
    
    int min_val, max_val;
    if (_checkBST(1, min_val, max_val, val, lft, rgt)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}