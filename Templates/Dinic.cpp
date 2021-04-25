/*
    Washief Hossain Mugdho
    09 September 2020
    Algorithm Dinic
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

struct Edge
{
    int u, v, cap, flow;
};

struct Dinic
{
    vector<Edge> e;
    vector<vector<int>> adj;
    vector<int> ptr;
    vector<int> level;
    int n, source, sink;
    Dinic(int n, int s, int t) : n(n), source(s), sink(t)
    {
        level.assign(n, -1);
        adj.assign(n, vector<int>());
        ptr.assign(n, 0);
    }
    void addEdge(int a, int b, int c)
    {
        int k = e.size();
        e.push_back({a, b, c, 0});
        e.push_back({b, a, c, c});
        adj[a].push_back(k);
        adj[b].push_back(k + 1);
    }
    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> Q;
        Q.push(source);
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i : adj[x])
            {
                if (level[e[i].v] == -1 && e[i].flow < e[i].cap)
                {
                    level[e[i].v] = level[x] + 1;
                    Q.push(e[i].v);
                }
            }
        }
        return level[sink] != -1;
    }
    int dfs(int x, int pushed)
    {
        if (x == sink)
            return pushed;
        for (int &id = ptr[x]; id < (int)adj[x].size(); id++)
        {
            int i = adj[x][id];
            if (level[e[i].v] == level[x] + 1 && e[i].flow < e[i].cap)
            {
                int f = dfs(e[i].v, min(pushed, e[i].cap - e[i].flow));
                if (f > 0)
                {
                    e[i].flow += f;
                    e[i ^ 1].flow -= f;
                    return f;
                }
            }
        }
        return 0;
    }
    int calc()
    {
        int ans = 0;
        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (true)
            {
                int f = dfs(source, INT_MAX);
                if (f == 0)
                    break;
                ans += f;
            }
        }
        return ans;
    }
};
int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
}
