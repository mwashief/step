/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1283
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;

int n;
int books[105];
int memo[105][105][105];

int dp(int now, int left, int right)
{
    if (now > n + 1)
        return 0;
    if (memo[now][left][right] != -1)
        return memo[now][left][right];
    int result = 0;
    if (books[now] >= books[left] && books[now] <= books[right])
        result = max(result, 1 + max(dp(now + 1, now, right), dp(now + 1, left, now)));
    result = max(result, dp(now + 1, left, right));
    return memo[now][left][right] = result;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        cin >> n;
        books[0] = 0;
        books[1] = INT32_MAX;
        for (int i = 2; i <= n + 1; i++)
            cin >> books[i];
        cout << "Case " << tt << ": " << dp(2, 0, 1) << endl;
    }
}
