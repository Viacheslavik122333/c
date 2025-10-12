#include "iostream"
#include "vector"

using namespace std;
using ll = long long;

struct Node 
{
    int i; int x;
    Node(int a, int b){i = a; x = b;}
    void print()
    {
        cout << i << " " << x << "\n";
    }
};

void fun (int n, vector<ll> &N)
{
    int count=0;
    vector<Node> arr;
    for(int i=0; i<n; ++i)
    {
        ll power = 1;
        while (power < N[i]) 
        {
            power *= 2;
        }
        ll x = power - N[i];
        if (x > 0) 
        {
            Node newnode(i+1, x);
            arr.push_back(newnode);
            count++;
        }
        N[i]+=x;
        // cout << "i = "<< i << " " << "x = " << x << "\n";

    }
    cout << count << "\n";
    for (int i=0; i<count; ++i)
    {
        arr[i].print();
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> t;
    for (int i=0; i<t; ++i)
    {
        cin >> n;
        vector<ll> N(n);
        for(int j=0; j<n; ++j)
        {
            cin >> N[j];
        }
        fun(n, N);
        // for(int k=0; k<n; ++k)
        // {
        //     cout << N[k] << " ";
        // }
        // cout << "stop" << "\n";
    }

    return 0;
}