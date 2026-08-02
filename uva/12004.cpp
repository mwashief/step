#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long x;
        cin >> x;
        long long mul = x * (x - 1);
        if (mul % 4 == 0)
            cout << "Case " << i << ": " << mul / 4 << endl;
        else if (mul % 2 == 0)
            cout << "Case " << i << ": " << mul / 2 << "/2" << endl;
        else
            cout << "Case " << i << ": " << mul << "/4" << endl;
    }
}
