/*
    Washief Hossain Mugdho
    20 August 2020
    UVa 10305
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
int a, b, n, m, curTime;
int finish[110];
bool visited[110];
vector<int> adj[110];

void dfs(int a)
{
    visited[a] = 1;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (!visited[adj[a][i]])
            dfs(adj[a][i]);
    }
    curTime++;
    finish[a] = curTime;
}

int main()
{
    while (cin >> n >> m && (n || m))
    {
        ms(visited, 0);
        curTime = 0;

        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
        }
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                dfs(i);

        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        sort(v.begin(), v.end(), [](const int &lhs, const int &rhs) {
            return finish[lhs] > finish[rhs];
        });
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
}
