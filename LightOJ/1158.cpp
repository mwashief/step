/*
    Washief Hossain Mugdho
    02 August 2020
    LightOJ 1158
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
int memo[1 << 11][1200];
bool visited[1 << 11];
string s;
int d;

void add(int maska, int maskb, int shift)
{
    for (int i = 0; i < d; i++)
        memo[maska][i] += (memo[maskb][(i - shift + d) % d]);
}

void dp(int mask, int p)
{
    if (visited[mask])
        return;
    visited[mask] = 1;
    int taken[11];
    ms(taken, -1);

    for (int i = 0; i < s.size(); i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            if (taken[s[i] - '0'] != -1)
            {
                visited[mask | (1 << i)] = 1;
                for (int j = 0; j < d; j++)
                    memo[mask | (1 << i)][j] = memo[taken[s[i] - '0']][j];
            }
            else
            {
                taken[s[i] - '0'] = i;
                dp(mask | (1 << i), (p * 10) % d);
                add(mask, mask | (1 << i), ((s[i] - '0') * p) % d);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s >> d;
        ms(memo, 0);
        ms(visited, 0);
        memo[(1 << s.size()) - 1][0] = 1;
        visited[(1 << s.size()) - 1] = 1;
        dp(0, 1);
        printf("Case %d: %d\n", tt, memo[0][0]);
    }
}