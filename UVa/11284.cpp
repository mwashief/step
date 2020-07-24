#include <bits/stdc++.h>
using namespace std;

long long costa, costb;
long long graph[54][54];
long long savings[15];
long long memo[8200][15];
bool visited[8200][15];
int stores[15];
int T, n, m, x, y, complete;

int dp(int mask, int last)
{
    if (mask == complete)
        return graph[stores[last]][0] - savings[last];

    if (visited[mask][last])
        return memo[mask][last];
    visited[mask][last] = 1;

    long long result = graph[stores[last]][0];
    for (int i = 1; i <= m; i++)
        if (!(mask & (1 << i)) && graph[stores[last]][stores[i]] != INT64_MAX)
            result = min(result, graph[stores[last]][stores[i]] + dp(mask | (1 << i), i));
    result -= savings[last];

    return memo[mask][last] = result;
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        memset(visited, 0, sizeof visited);

        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (i != j)
                    graph[i][j] = INT64_MAX;

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %ld.%ld", &x, &y, &costa, &costb);
            graph[x][y] = graph[y][x] = min(graph[x][y], costa * 100 + costb);
        }

        cin >> m;
        complete = 2;
        for (int i = 1; i <= m; i++)
        {
            complete *= 2;
            scanf("%d %ld.%ld", &x, &costa, &costb);
            savings[i] = costa * 100 + costb;
            stores[i] = x;
        }
        complete--;

        for (int k = 0; k <= n; k++)
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    if (graph[i][k] != INT64_MAX && graph[k][j] != INT64_MAX)
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        long long ans = -dp(1, 0);
        if (ans <= 0)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%ld.%02ld\n", ans / 100, ans % 100);
    }
}