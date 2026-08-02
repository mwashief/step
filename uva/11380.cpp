/*
    Washief Hossain Mugdho
    03 September 2020
    UVa 11380
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
int n, m, x, y, p;
char arr[34][34];
int nodes[2][34][34];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int adj[1900][1900];
vector<int> parent;

inline bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < x && c < y && arr[r][c] != '~';
}

int findAug()
{
    parent = vector<int>(n, -1);
    vector<int> cost(n, 1000);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty())
    {
        int a = Q.front();
        if (a == 1)
            break;
        Q.pop();
        for (int i = 0; i < n; i++)
            if (parent[i] == -1 && adj[a][i])
                cost[i] = min(cost[a], adj[a][i]), Q.push(i), parent[i] = a;
    }
    if (parent[1] == -1)
        return 0;
    int bottleneck = cost[1];
    int a = 1;
    while (a)
    {
        adj[parent[a]][a] -= bottleneck;
        adj[a][parent[a]] += bottleneck;
        a = parent[a];
    }
    return bottleneck;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    while (cin >> x >> y >> p)
    {
        ms(adj, 0);
        n = 2;
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                {
                    nodes[0][i][j] = n;
                    nodes[1][i][j] = n;
                    n++;
                }
                else if (arr[i][j] == '#')
                {
                    nodes[0][i][j] = n;
                    nodes[1][i][j] = n;
                    adj[n][1] = p;
                    n++;
                }
                else if (arr[i][j] == '.')
                {
                    nodes[0][i][j] = n;
                    nodes[1][i][j] = n + 1;
                    adj[n][n + 1] = 1;
                    n += 2;
                }
                else if (arr[i][j] == '*')
                {
                    nodes[0][i][j] = n;
                    nodes[1][i][j] = n + 1;
                    adj[n][n + 1] = 1;
                    adj[0][n] = 1000;
                    n += 2;
                }
            }

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (arr[i][j] != '~')
                    for (int k = 0; k < 4; k++)
                        if (isValid(i + dr[k], j + dc[k]))
                            adj[nodes[1][i][j]][nodes[0][i + dr[k]][j + dc[k]]] = 1000;

        int res = 0;
        int a;
        while (a = findAug())
            res += a;
        cout << res << endl;
    }
}
