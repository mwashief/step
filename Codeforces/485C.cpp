/*
    Washief Hossain Mugdho
    11 October 2020
    Codeforces 485C
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
int n, m, b;
unordered_set<int> numsHash;
bool visited[1 << 22];

inline int complement(int x)
{
    return (((1LL << n) - 1) - x);
}

void dfs(int a)
{
    for (int i = 0; i < n; i++)
        if ((a & (1 << i)) && !visited[a - (1 << i)])
        {
            visited[a - (1 << i)] = 1;
            dfs(a - (1 << i));
        }

    if (numsHash.find(a) != numsHash.end() && !visited[complement(a)])
    {
        visited[complement(a)] = 1;
        dfs(complement(a));
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
    fastio;
    untie;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        numsHash.insert(b);
    }
    int components = 0;
    for (auto x : numsHash)
        if (!visited[x])
        {
            components++;
            visited[complement(x)] = 1;
            dfs(complement(x));
        }

    cout << components << endl;
}
