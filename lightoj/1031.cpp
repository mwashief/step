/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1031
*/

#pragma GCC optimize("O3")
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
int arr[105];
int memo[105][105];
bool visited[105][105];

int dp(int a, int b)
{
    if (a > b)
        return 0;
    if (a == b)
        return arr[a] - arr[a - 1];
    if (visited[a][b])
        return memo[a][b];
    visited[a][b] = 1;
    int result = INT16_MIN;
    for (int i = a; i <= b; i++)
        result = max(result, arr[i] - arr[a - 1] - dp(i + 1, b));
    for (int i = b; i >= a; i--)
        result = max(result, arr[b] - arr[i - 1] - dp(a, i - 1));
    return memo[a][b] = result;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(visited, 0);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i], arr[i] += arr[i - 1];
        printf("Case %d: %d\n", tt, dp(1, n));
    }
}
