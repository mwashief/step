/*
    Washief Hossain Mugdho
    25 August 2020
    UVa 10369
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

int n, r;
int x[503];
int y[503];
int parent[503];
vector<pair<int, pair<int, int>>> edges;
pair<int, pair<int, int>> res;

inline int getDistance(int a, int b)
{
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

void initializeDSU()
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int getParent(int a)
{
    if (parent[a] != a)
        parent[a] = getParent(parent[a]);
    return parent[a];
}

void DSUunion(int a, int b)
{
    parent[parent[a]] = parent[parent[b]] = min(getParent(a), getParent(b));
}

void kruskal()
{
    int taken = 0;
    for (int i = 0; i < edges.size() && taken < n - r; i++)
    {
        ll weight = edges[i].fr;
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (getParent(a) == getParent(b))
            continue;

        taken++;
        res = edges[i];
        DSUunion(a, b);
    }
    cout << fixed << setprecision(2) << sqrt(res.fr) << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> r >> n;
        edges.clear();
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edges.pb(mp(getDistance(i, j), mp(i, j)));
        sort(edges.begin(), edges.end());
        initializeDSU();
        kruskal();
    }
}
