/*
    Washief Hossain Mugdho
    24 August 2020
    UVa 11747
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

int n, m, x, y, z;
vector<pair<int, pair<int, int>>> edges;
int parent[1004];

void iniDSU()
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

void DSU(int a, int b)
{
    parent[parent[a]] = parent[parent[b]] = min(getParent(a), getParent(b));
}

void kruskal()
{
    int taken = 0;
    bool forest = false;
    iniDSU();
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (taken == n - 1 || getParent(a) == getParent(b))
        {
            if (forest)
                cout << " ";
            forest = true;
            cout << edges[i].fr;
            continue;
        }
        taken++;
        DSU(a, b);
    }
    if (!forest)
        cout << "forest";
    cout << endl;
}

int main()
{
    while (cin >> n >> m && n != 0)
    {
        edges.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            edges.pb(mp(z, mp(x, y)));
        }
        kruskal();
    }
}
