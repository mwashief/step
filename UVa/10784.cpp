#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 1;
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            return 0;
        long long ans = ceil((3.0 + sqrt(9.0 + 8.0 * x)) / 2.0);
        cout << "Case " << T << ": " << ans << endl;
        T++;
    }
}