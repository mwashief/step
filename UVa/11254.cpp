#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll x;
    while (1)
    {
        cin >> x;
        if (x <= -1)
            break;
        for (ll i = sqrt(2 * x); i >= 1; i--)
        {
            ll LHS = 2 * x + i - i * i;
            if (LHS >= 0 && (LHS + 2 * i - 1) / 2 / i == LHS / 2 / i)
            {
                cout << x << " = " << LHS / 2 / i << " + ... + " << LHS / 2 / i + i - 1 << endl;
                break;
            }
        }
    }
}