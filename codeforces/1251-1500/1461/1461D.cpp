/*
    Washief Hossain Mugdho
    16 December 2020
    Codeforces 1461D
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
int n, q, s;
vector<ll> arr;
vector<ll> sum;
unordered_set<ll> possible;

void traverse(int l, int r)
{
    possible.insert(sum[r + 1] - sum[l]);
    if (arr[l] == arr[r])
        return;
    int mid = (arr[l] + arr[r]) / 2;
    mid = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
    traverse(l, mid - 1);
    traverse(mid, r);
}

void solve()
{
    cin >> n >> q;
    arr = vector<ll>(n);
    sum = vector<ll>(n + 1);
    possible.clear();
    sum[0] = 0LL;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
    traverse(0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        if (possible.find(s) != possible.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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
