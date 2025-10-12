#include "iostream"
#include "string"
#include "vector"
#include "utility" // для pair
#include "stack" 


using namespace std;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    int n = s.length(); // длина массива

    vector<int> v(n, -1);
    stack<pair<char, int>> st;


    for(int i=0; i<n; ++i)
    {
        char tmp = s[i];

        if (tmp == '(' || tmp == '[' || tmp == '{') 
        {
            st.push({tmp, i});
        }
        else
        {
            if (st.empty()) 
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                char top_char = st.top().first; 
                int top_index = st.top().second; 

                st.pop();

                if ((tmp == ')' && top_char == '(') || (tmp == ']' && top_char == '[') || (tmp == '}' && top_char == '{'))
                {
                    v[top_index] = i;
                    v[i] = top_index;
                }
                else
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }


    if (!st.empty()) 
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<v.size(); ++i) {cout << v[i] << " ";}

    return 0;
}