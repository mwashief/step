/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Knapsack2
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
int N, W, w[105], v[105];

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int N, W;
    cin >> N >> W;
    int w[N], v[N];
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    int res = 0;
    int high = 1000 * N + 4;
    vector<vector<int>> memo(high, vector<int>(N + 1, INT32_MAX));

    for (int i = 0; i <= N; i++)
        memo[0][i] = 0;

    for (int i = 0; i < high; i++)
        for (int j = 1; j <= N; j++)
        {
            if (memo[i][j - 1] < W)
            {
                int weight = memo[i][j - 1] + w[j - 1];
                if (weight <= W)
                {
                    for (int k = j; k <= N; k++)
                        memo[i + v[j - 1]][k] = min(memo[i + v[j - 1]][k], weight);
                    res = max(res, i + v[j - 1]);
                }
            }
        }

    cout << res << endl;
}
