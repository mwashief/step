#include <bits/stdc++.h>
using namespace std;

int memo[22][202];
vector<int> garments[22];
int M, C;

int dp(int garment, int remainingMoney)
{
    if (memo[garment][remainingMoney])
        return memo[garment][remainingMoney];
    if (garment == C - 1)
    {
        int remain = 9999999;
        int ans = -1;
        for (int i = 0; i < garments[garment].size(); i++)
        {
            if (garments[garment][i] <= remainingMoney && remainingMoney - garments[garment][i] < remain)
            {
                remain = remainingMoney - garments[garment][i];
                ans = garments[garment][i];
            }
        }
        return memo[garment][remainingMoney] = ans;
    }
    int ans = -1;
    for (int i = 0; i < garments[garment].size(); i++)
    {
        if (garments[garment][i] <= remainingMoney)
        {
            int d = dp(garment + 1, remainingMoney - garments[garment][i]);
            if (d != -1)
                ans = max(ans, garments[garment][i] + d);
        }
    }
    return memo[garment][remainingMoney] = ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> M >> C;
        memset(memo, 0, sizeof(memo));
        for (int i = 0; i < 22; i++)
            garments[i].clear();
        for (int i = 0; i < C; i++)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int d;
                cin >> d;
                garments[i].push_back(d);
            }
        }
        int ans = dp(0, M);
        if (ans == -1)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
}