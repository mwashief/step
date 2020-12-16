/*
    Washief Hossain Mugdho
    16 December 2020
    690Div3 690D
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

void solve()
{
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int groups = n; groups > 0; groups--)
    {
        if (sum % groups)
            continue;
        int groupSum = sum / groups;
        int i = 0, s = 0;
        while (i < n)
        {
            s += arr[i];
            if (s == groupSum)
                s = 0;
            else if (s > groupSum)
                break;
            i++;
        }
        if (!s)
        {
            cout << n - groups << endl;
            return;
        }
    }
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
