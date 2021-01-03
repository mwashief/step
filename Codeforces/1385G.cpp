/*
    Washief Hossain Mugdho
    11 October 2020
    Codeforces 1385G
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
int n, x;
vector<pair<int, int>> adj[200005];
bool visited[200005];
vector<int> res;
void bfs(int a)
{
    queue<pair<int, int>> Q;
    vector<int> nodes[2];
    Q.push({a, 0});
    visited[a] = 1;
    while (!Q.empty())
    {
        auto f = Q.front();
        Q.pop();
        nodes[f.sc].push_back(f.fr);
        for (int i = 0; i < adj[f.fr].size(); i++)
            if (!visited[adj[f.fr][i].fr])
            {
                Q.push({adj[f.fr][i].fr, (f.sc + adj[f.fr][i].sc) & 1});
                visited[adj[f.fr][i].fr] = 1;
            }
    }
    if (nodes[0].size() < nodes[1].size())
        res.insert(res.end(), nodes[0].begin(), nodes[0].end());
    else
        res.insert(res.end(), nodes[1].begin(), nodes[1].end());
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<pair<int, int>> grid[n];
        bool impossible = false;
        ms(visited, 0);
        res.clear();
        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> x;
                x--;
                grid[x].push_back({i, j});
            }

        for (int i = 0; i < n; i++)
        {
            if (grid[i].size() != 2)
            {
                impossible = true;
                break;
            }
            if (grid[i][0].fr == grid[i][1].fr)
            {
                adj[grid[i][0].sc].pb({grid[i][1].sc, 1});
                adj[grid[i][1].sc].pb({grid[i][0].sc, 1});
            }
            else if (grid[i][0].sc != grid[i][1].sc)
            {
                adj[grid[i][0].sc].pb({grid[i][1].sc, 0});
                adj[grid[i][1].sc].pb({grid[i][0].sc, 0});
            }
        }

        if (impossible)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
                bfs(i);
        cout << res.size() << endl;
        for (auto i : res)
            cout << i + 1 << " ";
        cout << endl;
    }
}
