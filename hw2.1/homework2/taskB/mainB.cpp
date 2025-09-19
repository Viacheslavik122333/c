#include "headerB.h"

int main()
{
    int n, t, N=1;
    stack A, B;

    cin >> n;

    for (int i=0; i<n; ++i)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            A.push_back(N);
            ++N;
            break;
        case 2:
            B.push_back(N);
            ++N;
            break;

        case 3:
            if (B.real == nullptr || (A.real != nullptr && A.watch_back() < B.watch_back())) {
                A.pop_back();
            } else {
                B.pop_back();
            }
            break;
        }
    }

    cout << A.watch_back() + B.watch_back() << endl;

    return 0;
}