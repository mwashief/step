/*
    Washief Hossain Mugdho
    02 August 2020
    LightOJ 1021
*/

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

unordered_map<char, ull> v;
ull memo[1 << 16][20];
bool visited[1 << 16];
ull base, k;
string s;

inline void add(int maska, int maskb, int shift)
{
    for (int i = 0; i < k; i++)
        memo[maska][i] += memo[maskb][(i - shift + k) % k];
}

void dp(int mask, int p)
{
    if (visited[mask])
        return;
    visited[mask] = true;

    for (int i = 0; i < s.size(); i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            dp(mask | (1 << i), (p * base) % k);
            int shift = (p * v[s[i]]) % k;
            add(mask, mask | (1 << i), shift);
        }
    }
}

int main()
{
    for (int i = 0; i <= 9; i++)
        v.insert(mp('0' + i, i));

    for (int i = 0; i < 7; i++)
        v.insert(mp('A' + i, 10 + i));

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> base >> k >> s;
        ms(visited, 0);
        ms(memo, 0);
        memo[(1 << s.size()) - 1][0] = 1;
        visited[(1 << s.size()) - 1] = 1;
        dp(0, 1);

        printf("Case %d: %llu\n", tt, memo[0][0]);
    }
}