#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull memo[1000006];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ull n, k;
    for (ull n = 4; n <= 1000000; n++)
    {
        if (n & 1)
        {
            k = (n - 3) >> 1;
            memo[n] = memo[n - 1] + (k) * (k + 1);
        }
        else
        {
            k = (n - 2) >> 1;
            memo[n] = memo[n - 1] + k * k;
        }
    }

    while (1)
    {
        cin >> n;
        if (n < 3)
            return 0;
        cout << memo[n] << endl;
    }
}