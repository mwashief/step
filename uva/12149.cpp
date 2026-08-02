#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        unsigned long long arm;
        cin >> arm;
        if (arm)
        {
            cout << arm * (arm + 1) * (2 * arm + 1) / 6 << endl;
        }
        else
            return 0;
    }
}
