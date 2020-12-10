/*
    Washief Hossain Mugdho
    10 December 2020
    Codeforces 685B
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

void solve()
{
    int n, q;
    cin >> n >> q;
    bool arr[n];
    int storage[2][2] = {{n, -1}, {n, -1}};
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            storage[1][0] = min(storage[1][0], i);
            storage[1][1] = max(storage[1][1], i);
            arr[i] = 1;
        }
        else
        {
            storage[0][0] = min(storage[0][0], i);
            storage[0][1] = max(storage[0][1], i);
            arr[i] = 0;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (storage[arr[x]][0] < x || storage[arr[y]][1] > y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
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
