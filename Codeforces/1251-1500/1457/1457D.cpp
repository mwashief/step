/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 1457D
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
    vector<int> arr;
    int n, x;
    cin >> n;
    arr.pb(0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.pb(arr[arr.size() - 1] ^ x);
    }
    if (arr.size() > 65)
    {
        cout << 1 << endl;
        return 0;
    }
    int res = INT32_MAX;
    for (int leftStart = 1; leftStart < n; leftStart++)
        for (int leftEnd = leftStart; leftEnd < n; leftEnd++)
            for (int rightEnd = leftEnd + 1; rightEnd <= n; rightEnd++)
                if ((arr[leftEnd] ^ arr[leftStart - 1]) > (arr[rightEnd] ^ arr[leftEnd]))
                    res = min(res, rightEnd - leftStart - 1);

    if (res == INT32_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
}
