#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 1;
    while (1)
    {
        int x;
        cin >> x;
        if (!x)
            return 0;
        cout << "Case " << T << ": " << x / 2 << endl;
        T++;
    }
}