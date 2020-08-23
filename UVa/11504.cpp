/*
    Washief Hossain Mugdho
    22 August 2020
    UVa 11504
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
bool visited[100005];
vector<int> adj[100005];
vector<int> sorted;
int n, m, x, y;

void dfs(int a)
{
    visited[a] = 1;
    for (int i = 0; i < adj[a].size(); i++)
        if (visited[adj[a][i]] == 0)
            dfs(adj[a][i]);
    sorted.pb(a);
}
void dfs2(int a)
{
    visited[a] = 1;
    for (int i = 0; i < adj[a].size(); i++)
        if (visited[adj[a][i]] == 0)
            dfs2(adj[a][i]);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        sorted.clear();
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x - 1].pb(y - 1);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            if (visited[i] == 0)
                dfs(i);

        ms(visited, 0);
        for (int i = n - 1; i >= 0; i--)
            if (visited[sorted[i]] == 0)
                dfs2(sorted[i]), res++;
        cout << res << endl;
    }
}
