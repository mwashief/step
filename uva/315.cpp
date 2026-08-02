/*
    Washief Hossain Mugdho
    21 August 2020
    UVa 315
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

int n, x, y, curTime, root, rootChild;
vector<int> adj[105];
char temp;
bool visited[105];
bool isCritical[105];
int discoveryTime[105];
int lowTime[105];

void dfs(int a, int parent)
{
    visited[a] = 1;
    discoveryTime[a] = curTime;
    lowTime[a] = curTime;
    curTime++;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (!visited[adj[a][i]])
        {
            if (a == root)
                rootChild++;
            dfs(adj[a][i], a);
            if (lowTime[adj[a][i]] >= discoveryTime[a])
                isCritical[a] = 1;
            lowTime[a] = min(lowTime[a], lowTime[adj[a][i]]);
        }
        else if (adj[a][i] != parent)
            lowTime[a] = min(lowTime[a], discoveryTime[adj[a][i]]);
    }
}

int main()
{
    while (cin >> n && n)
    {
        curTime = 0;
        ms(visited, 0);
        ms(isCritical, 0);
        for (int i = 1; i <= n; i++)
            adj[i].clear();

        while (cin >> x && x)
        {
            do
            {
                scanf("%d%c", &y, &temp);
                adj[x].pb(y);
                adj[y].pb(x);
            } while (temp != '\n');
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                root = i;
                rootChild = 0;
                dfs(i, -1);
                isCritical[root] = (rootChild > 1);
            }
            res += isCritical[i];
        }
        cout << res << endl;
    }
}
