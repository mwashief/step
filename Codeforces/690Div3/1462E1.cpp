/*
    Washief Hossain Mugdho
    15 December 2020
    690Div3 1462E1
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
int arr[200105];

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

    int tc, n, x;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i = 0; i < n + 20; i++)
            arr[i] = 0;
        ull res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr[x - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            res += (ull)arr[i] * (arr[i] - 1) * (arr[i] - 2) / 6;
            res += ((ull)arr[i] * (arr[i] - 1) * arr[i + 1]) >> 1;
            res += ((ull)arr[i] * arr[i + 1] * (arr[i + 1] - 1)) >> 1;
            res += (ull)arr[i] * arr[i + 1] * arr[i + 2];
            res += ((ull)arr[i] * (arr[i] - 1) * arr[i + 2]) >> 1;
            res += ((ull)arr[i] * arr[i + 2] * (arr[i + 2] - 1)) >> 1;
        }
        cout << res << endl;
    }
}
