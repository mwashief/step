#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        if (n <= 0)
            cout << "0" << endl;
        ll j, k = sqrt(n);
        ll result = 0;
        ll end = n;

        for (ll i = 1; i <= k; i++)
        {
            j = n / i;
            result += j;
        }
        for (ll i = 1; i < j; i++)
        {
            ll start = n / (i + 1);
            result += (end - start) * i;
            end = start;
        }
        cout << result << endl;
    }
}