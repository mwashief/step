/*
    Washief Hossain Mugdho
    11 September 2020
    Tree Basics E
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
#define mx 300005
using namespace std;
int tt = -1, n;
int startTime[mx];
int endTime[mx];
double t[2 * mx];
vector<int> adj[mx];

void dfs(int a, int p)
{
    startTime[a] = ++tt;
    for (int i = 0; i < adj[a].size(); i++)
        if (adj[a][i] != p)
            dfs(adj[a][i], a);
    endTime[a] = tt;
}

void modify(int p, double value)
{
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

double query(int l, int r)
{
    double res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
            modify(startTime[x], log10(y));
        else
        {
            double a = query(startTime[x], endTime[x] + 1);
            double b = query(startTime[y], endTime[y] + 1);

            double ans = a - b;
            if (ans >= 9.0)
                cout << "1000000000" << endl;
            else
                cout << fixed << setprecision(9) << pow(10, ans) << endl;
        }
    }
}
