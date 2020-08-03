/*
    Washief Hossain Mugdho
    03 August 2020
    LightOJ 1079
*/

//#pragma GCC optimize("O3")
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
double p;
double proba[105];
int mill[105];
bool visited[110][10010];
double memo[110][10010];
double dp(int a, int money)
{
    if (money <= 0)
        return 0.0;
    if (a == n)
        return -1.0;
    if (visited[a][money])
        return memo[a][money];
    visited[a][money] = 1;
    double ans = 1.0;
    bool flag = true;
    double x = dp(a + 1, money - mill[a]);
    if (!(x < 0.0))
    {
        ans = min(ans, proba[a] + x * (1.0 - proba[a]));
        flag = false;
    }
    x = dp(a + 1, money);
    if (!(x < 0.0))
    {
        ans = min(ans, dp(a + 1, money));
        flag = false;
    }
    if (flag)
        ans = -1.0;
    return memo[a][money] = ans;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> p >> n;
        ms(visited, 0);
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> mill[i] >> proba[i];
            start += mill[i];
        }
        for (int i = start; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp(j, i) <= p && dp(j, i) >= 0.0)
                {
                    cout << "Case " << tt << ": " << i << endl;
                    i = -1;
                    break;
                }
            }
        }
    }
}
