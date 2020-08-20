/*
    Washief Hossain Mugdho
    20 August 2020
    UVa 11080
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

int T, v, e, f, t, sz, guards;
vector<int> adj[205];
int visited[205];
bool impossible;

void dfs(int pos, int g)
{
    sz++;
    if (g)
        guards++;
    visited[pos] = g;
    for (int i = 0; i < adj[pos].size(); i++)
    {
        if (visited[adj[pos][i]] == -1)
            dfs(adj[pos][i], (g + 1) % 2);
        else if (visited[adj[pos][i]] == g)
        {
            impossible = true;
            return;
        }
    }
}

int main()
{

    cin >> T;
    while (T--)
    {
        cin >> v >> e;
        for (int i = 0; i < v; i++)
            adj[i].clear(), visited[i] = -1;
        impossible = false;
        for (int i = 0; i < e; i++)
        {
            cin >> f >> t;
            adj[f].pb(t);
            adj[t].pb(f);
        }
        int res = 0;
        for (int i = 0; i < v; i++)
        {
            if (impossible)
                break;
            if (visited[i] == -1)
            {
                sz = 0;
                guards = 0;
                dfs(i, 1);
                if (sz == 1)
                    res++;
                else
                    res += min(guards, sz - guards);
            }
        }
        if (impossible)
            cout << "-1";
        else
            cout << res;
        cout << endl;
    }
}
