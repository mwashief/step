/*
    Washief Hossain Mugdho
    21 August 2020
    UVa 796
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
int n, x, y, server, curTime;
char dummy;
vector<int> discoveryTime;
vector<int> lowTime;
vector<vector<int>> adj;
vector<pair<int, int>> links;

void dfs(int a, int parent)
{
    discoveryTime[a] = curTime;
    lowTime[a] = curTime;
    curTime++;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (discoveryTime[adj[a][i]] == -1)
        {
            dfs(adj[a][i], a);
            if (discoveryTime[a] < lowTime[adj[a][i]])
                links.pb(mp(min(a, adj[a][i]), max(a, adj[a][i])));
            lowTime[a] = min(lowTime[a], lowTime[adj[a][i]]);
        }
        else if (adj[a][i] != parent)
            lowTime[a] = min(lowTime[a], discoveryTime[adj[a][i]]);
    }
}

int main()
{
    while (cin >> n)
    {
        curTime = 0;
        discoveryTime = vector<int>(n, -1);
        lowTime = vector<int>(n);
        adj = vector<vector<int>>(n, vector<int>());
        links.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> server;
            cin >> dummy >> x >> dummy;
            for (int j = 0; j < x; j++)
            {
                cin >> y;
                adj[server].pb(y);
            }
        }
        for (int i = 0; i < n; i++)
            if (discoveryTime[i] == -1)
                dfs(i, -1);

        sort(links.begin(), links.end());
        cout << links.size() << " critical links" << endl;
        for (int i = 0; i < links.size(); i++)
            cout << links[i].fr << " - " << links[i].sc << endl;
        cout << endl;
    }
}
