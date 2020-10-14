/*
    Washief Hossain Mugdho
    14 October 2020
    Codeforces 31E
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

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
string s;
ll a[40], memo[40][40];
bool visited[40][40];
bool taken[40][40];

ll dp(int now, int pos)
{
    if (pos > n || (now - pos) > n)
        return INT32_MIN;
    if (now >= 2 * n)
        return 0;
    if (visited[now][pos])
        return memo[now][pos];
    visited[now][pos] = 1;

    ll first = 1LL * (s[now] - '0') * a[n - pos] + dp(now + 1, pos + 1);
    ll second = 1LL * (s[now] - '0') * a[n + pos - now] + dp(now + 1, pos);
    if (first > second)
    {
        taken[now][pos] = 1;
        return memo[now][pos] = first;
    }
    return memo[now][pos] = second;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    a[1] = 1;
    for (int i = 2; i < 40; i++)
        a[i] = a[i - 1] * 10;
    cin >> n >> s;
    dp(0, 0);
    int pos = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (taken[i][pos])
        {
            pos++;
            cout << 'M';
        }
        else
            cout << 'H';
    }
    cout << endl;
}
