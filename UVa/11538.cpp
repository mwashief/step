#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL a, b, m, n;
    while (1)
    {
        cin >> a >> b;
        if (a == 0)
            return 0;
        m = min(a, b);
        n = max(a, b);
        LL result = m * n * (m + n - 2);
        if (m - 1 > 1)
        {
            result += 4 * (m * (m - 1) * (2 * m - 1) / 6 - m * (m - 1) / 2);
        }
        result += 2 * (n - m + 1) * m * (m - 1);
        cout << result << endl;
    }
}
