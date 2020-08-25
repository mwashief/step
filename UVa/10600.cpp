/*
    Washief Hossain Mugdho
    25 August 2020
    UVa 10600
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

int n, m, x, y, z, mstCost;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> MST;
int parent[105];

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
    initializeDSU();
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size() && taken < n - 1; i++)
    {
        int w = edges[i].fr;
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (getParent(a) == getParent(b))
            continue;
        mstCost += w;
        MST.pb(edges[i]);
        taken++;
        DSUunion(a, b);
    }
}

void secondBest()
{
    int taken = 0;
    vector<pair<int, pair<int, int>>> remaining;
    for (int i = 0; i < edges.size(); i++)
    {
        if (taken < n - 1 && edges[i] == MST[taken])
        {
            taken++;
            continue;
        }
        remaining.pb(edges[i]);
    }

    int res = INT32_MAX;
    for (int i = 0; i < MST.size(); i++)
    {
        initializeDSU();
        for (int j = 0; j < MST.size(); j++)
            if (i != j)
                DSUunion(MST[j].sc.fr, MST[j].sc.sc);

        for (int j = 0; j < remaining.size(); j++)
            if (getParent(remaining[j].sc.fr) != getParent(remaining[j].sc.sc))
                res = min(res, remaining[j].fr - MST[i].fr);
    }
    cout << mstCost << " " << mstCost + res << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        edges.clear();
        MST.clear();
        mstCost = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            edges.pb(mp(z, mp(x - 1, y - 1)));
        }
        kruskal();
        secondBest();
    }
}
