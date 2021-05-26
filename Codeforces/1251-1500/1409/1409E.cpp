/*
    Washief Hossain Mugdho
    18 September 2020
    Codeforces 1409E
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
int T, n, k, a;
vector<int> arr;
vector<int> res;
vector<int> fromRight;
vector<int> fromLeft;
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
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        arr = vector<int>(n);
        res = vector<int>(n);
        fromRight = vector<int>(n + 2, 0);
        fromLeft = vector<int>(n + 2, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> a;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int c = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();
            res[i] = c - i;
        }
        for (int i = 0; i < n; i++)
            fromLeft[i + 1] = max(fromLeft[i], res[i]);
        for (int i = n - 1; i >= 0; i--)
            fromRight[i + 1] = max(fromRight[i + 2], res[i]);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int c = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();
            ans = max(ans, fromLeft[i + 1] + fromRight[c + 1]);
        }
        cout << ans << endl;
    }
}
