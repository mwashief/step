#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull T, n, K, M, total, x;

ull bigMod(ull N, ull p)
{
    if (p == 0)
        return 1;
    ull ans = bigMod(n, p / 2);
    ans = (ans * ans) % M;
    if (p & 1)
        ans = (N * ans) % M;
    return ans;
}

int main()
{
    cin >> T;
    for (ull t = 1; t <= T; t++)
    {
        cin >> n >> K >> M;
        total = 0;
        for (ull i = 0; i < n; i++)
        {
            cin >> x;
            total += x;
            total %= M;
        }
        ull kMod = K % M;
        total = (total * kMod) % M;
        total = (total * bigMod(n, K - 1)) % M;
        cout << "Case " << t << ": " << total << endl;
    }
}