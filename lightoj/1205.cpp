/*
    Washief Hossain Mugdho
    08 August 2020
    LightOJ 1205
*/

//#pragma GCC optimize("O3")
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
ll memo[20][20][2][2][2];
ll s[20];
ll highest[20];
int n;

ll dp(int pos, int match, int zero, int isSmaller, int haveToSmaller)
{
    if (pos == match)
    {
        if (isSmaller)
            return zero + 9;

        if (haveToSmaller)
            return s[pos] - 1 + zero > 0 ? s[pos] - 1 + zero : 0;
        return s[pos] + zero;
    }

    if (match - pos == 1)
    {
        if (isSmaller)
            return zero + 9;
        if (haveToSmaller)
        {
            int a = s[pos];
            int b = s[match];
            if (b == 0)
            {
                a--;
                b = 9;
            }
            else
                b--;
            return (a >= 0 ? zero : 0) + (a - 1 > 0 ? a - 1 : 0) + ((a <= b && a > 0) ? 1 : 0);
        }
        int a = s[pos];
        int b = s[match];
        return (a >= 0 ? zero : 0) + (a - 1 > 0 ? a - 1 : 0) + ((a <= b && a > 0) ? 1 : 0);
    }
    if (memo[pos][match][zero][isSmaller][haveToSmaller] != -1)
        return memo[pos][match][zero][isSmaller][haveToSmaller];

    memo[pos][match][zero][isSmaller][haveToSmaller] = 0;
    if (isSmaller)
    {
        memo[pos][match][zero][isSmaller][haveToSmaller] += (zero + 9) * dp(pos + 1, match - 1, 1, 1, 0);
    }
    else
    {
        memo[pos][match][zero][isSmaller][haveToSmaller] += s[pos] - 1 + zero > 0 ? (s[pos] - 1 + zero) * dp(pos + 1, match - 1, 1, 1, 0) : 0;
        memo[pos][match][zero][isSmaller][haveToSmaller] += s[match] >= s[pos] ? dp(pos + 1, match - 1, 1, 0, s[match] > s[pos] ? 0 : haveToSmaller) : dp(pos + 1, match - 1, 1, 0, 1);
    }
    return memo[pos][match][zero][isSmaller][haveToSmaller];
}

void getArr(ll x)
{
    n = 0;
    while (x > 0)
    {
        s[n] = x % 10;
        x /= 10;
        n++;
    }
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
}

ll getRes(ll x)
{
    if (x < 0)
        return 0;
    getArr(x);
    if (n == 0)
        return 1;
    if (n == 1)
        return x + 1;
    ms(memo, -1);
    ll res = dp(0, n - 1, 0, 0, 0);
    for (int i = 1; i < n; i++)
        res += highest[i];
    return res;
}

int main()
{
    int T;
    cin >> T;
    ll s1, s2;
    highest[1] = 10;
    highest[2] = 9;
    for (int i = 3; i <= 18; i += 2)
    {
        highest[i] = 10 * highest[i - 1];
        highest[i + 1] = highest[i];
    }
    for (int tt = 1; tt <= T; tt++)
    {

        cin >> s1 >> s2;
        if (s1 > s2)
            swap(s1, s2);

        cout << "Case " << tt << ": " << getRes(s2) - getRes(s1 - 1) << endl;
        /*cin >> s1;
        cout << getRes(s1) << endl;*/
    }
}
