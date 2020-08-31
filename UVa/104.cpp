/*
    Washief Hossain Mugdho
    31 August 2020
    UVa 104
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

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    while (cin >> n)
    {
        double adj[n][n];
        int parent[n + 1][n][n];
        int edges[n + 1];
        double val[n + 1][n][n];

        for (int i = 0; i <= n; i++)
        {
            edges[i] = 100;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    val[i][j][k] = 0.0;
                    parent[i][j][k] = k;
                }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 1.0;
                    val[0][i][j] = 1.0;
                    continue;
                }
                cin >> adj[i][j];
            }
        }

        for (int start = 0; start < n; start++)
        {
            int e;
            bool changed = true;
            for (e = 1; e <= n && changed && val[e - 1][start][start] <= 1.01; e++)
            {
                changed = false;
                for (int i = 0; i < n; i++)
                    if (val[e - 1][start][i] > 0)
                        for (int j = 0; j < n; j++)
                            if (i != j)
                            {
                                if (val[e - 1][start][i] * adj[i][j] > val[e][start][j])
                                {
                                    val[e][start][j] = val[e - 1][start][i] * adj[i][j];
                                    parent[e][start][j] = i;
                                    changed = true;
                                }
                            }
            }
            if (val[e - 1][start][start] > 1.01)
                edges[start] = min(edges[start], e - 1);
        }

        int e = n + 1;
        int start = n + 1;
        for (int i = 0; i < n; i++)
            if (edges[i] < e)
            {
                e = edges[i];
                start = i;
            }
        if (e > n)
            cout << "no arbitrage sequence exists" << endl;
        else
        {
            int temp = start;
            stack<int> s;
            while (e > 0)
            {
                s.push(parent[e][start][temp] + 1);
                temp = parent[e][start][temp];
                e--;
            }
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            cout << start + 1 << endl;
        }
    }
}
