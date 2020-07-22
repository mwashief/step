#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;
ull coins[] = {1, 5, 10, 25, 50};
ull ways[30002][5];

ull dp(int money, int taken)
{
    if (taken < 0 || money < 0)
        return 0;
    if (taken == 0)
        return 1;
    if (ways[money][taken])
        return ways[money][taken];
    return ways[money][taken] = dp(money - coins[taken], taken) + dp(money, taken - 1);
}

int main()
{
    int n;

    while (cin >> n)
    {
        if (dp(n, 4) == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << dp(n, 4) << " ways to produce " << n << " cents change." << endl;
    }
}