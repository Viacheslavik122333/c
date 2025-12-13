#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using ll = long long;
using namespace std;

ll prod(ll vx, ll vy, ll wx, ll wy)
{
    return vx * wy - vy * wx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bool res = false;

    ll AB = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    ll BC = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);

    ll tmp = prod(bx - ax, by - ay, cx - bx, cy - by);

    if(AB == BC && tmp != 0) res = true;

    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}