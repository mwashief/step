/*
    Washief Hossain Mugdho
    26 August 2020
    UVa 11367
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

int p[1003];
int n, m, q, x, y, z;
vector<vector<pair<int, int>>> adj;

void dijkstra()
{
    int res = INT32_MAX;
    vector<vector<int>> d = vector<vector<int>>(n, vector<int>(z + 1, INT32_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;
    PQ.push(mp(0, mp(x, 0)));
    d[x][0] = 0;
    while (!PQ.empty())
    {
        int val = PQ.top().fr;
        int node = PQ.top().sc.fr;
        int tank = PQ.top().sc.sc;
        PQ.pop();
        if (node == y)
        {
            res = d[node][tank];
            break;
        }
        if (val > d[node][tank])
            continue;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i].fr;
            int edge = adj[node][i].sc;
            if (edge > z)
                continue;
            for (int j = max(edge, tank); j <= z; j++)
            {
                int cost = val + (j - tank) * p[node];
                if (cost < d[next][j - edge])
                {
                    d[next][j - edge] = cost;
                    PQ.push(mp(cost, mp(next, j - edge)));
                }
            }
        }
    }
    if (res == INT32_MAX)
        cout << "impossible" << endl;
    else
        cout << res << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        adj[x].pb(mp(y, z));
        adj[y].pb(mp(x, z));
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> z >> x >> y;
        dijkstra();
    }
}
