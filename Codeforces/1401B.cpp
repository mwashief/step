/*
    Washief Hossain Mugdho
    16 September 2020
    Codeforces 1401B
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

int arr[2][3], t, oneStart, oneEnd, twoStart, twoEnd, a, n;
int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    fastio;
    untie;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                cin >> arr[i][j];
        int res = INT32_MIN;
        n = 0;
        for (int i = 0; i < 3; i++)
            n += arr[0][i];

        oneStart = arr[0][2] + arr[0][0];
        oneEnd = n;
        twoStart = min(arr[0][2], arr[1][1]);
        twoEnd = twoStart + arr[1][2];
        a = min(twoEnd, oneEnd) - max(oneStart, twoStart);
        cout << 2 * (min(arr[0][2], arr[1][1]) - (a > 0 ? a : 0)) << endl;
    }
}
