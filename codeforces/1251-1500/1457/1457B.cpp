/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 1457B
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
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
int n, k, gColor;
int arr[100005];

int getDays(int from)
{
    int res = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] == gColor)
            i++;
        else
        {
            res++;
            i += k;
        }
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    unordered_set<int> colors;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        colors.insert(arr[i]);
    }
    int res = n;
    for (auto color : colors)
    {
        gColor = color;
        res = min(res, getDays(0));
        if (res == 0)
            break;
    }
    cout << res << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
