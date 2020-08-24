/*
    Washief Hossain Mugdho
    24 August 2020
    UVa 11631
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
int n, m, x, y, z, total;
vector<pair<int, pair<int, int>>> edges;
int parent[200009];

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
    int MSTweight = 0;
    int taken = 0;
    initializeDSU();
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size() && taken < n - 1; i++)
    {
        int w = edges[i].fr;
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (getParent(a) == getParent(b))
            continue;
        taken++;
        MSTweight += w;
        DSUunion(a, b);
    }
    cout << total - MSTweight << endl;
}

int main()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        total = 0;
        edges.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            edges.pb(mp(z, mp(x, y)));
            total += z;
        }
        kruskal();
    }
}
