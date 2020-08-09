#include <bits/stdc++.h>
using namespace std;

bool visitedA[200005];
bool visitedB[200005];
list<int> adj[200005];
int T, n, m, a, b, x, y;

void dfs(int p, int q, bool *visited)
{
    if (visited[p])
        return;
    visited[p] = true;

    for (auto it = adj[p].begin(); it != adj[p].end(); ++it)
    {
        dfs(*it, q, visited);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        memset(visitedA, 0, n + 1);
        visitedA[b] = true;
        dfs(a, b, visitedA);
        memset(visitedB, 0, n + 1);
        visitedB[a] = true;
        dfs(b, a, visitedB);

        unsigned long long adjA = 0;
        unsigned long long adjB = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visitedA[i] && !visitedB[i])
                adjA++;
            if (!visitedA[i] && visitedB[i])
                adjB++;
        }

        cout << adjA * adjB << endl;
    }
}
