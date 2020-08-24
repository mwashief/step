/*
    Washief Hossain Mugdho
    24 August 2020
    UVa 11228
*/

//#pragma GCC optimize("O3")
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
int n, r, bigEdgeNum;
double smallEdgeWeight, bigEdgeWeight;
int x[1003];
int y[1003];
int parent[1003];
vector<pair<int, pair<int, int>>> edges;

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
    for (int i = 0; i < edges.size() && taken < n - 1; i++)
    {
        ll weight = edges[i].fr;
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (getParent(a) == getParent(b))
            continue;

        taken++;
        if (weight > r * r)
        {
            bigEdgeNum++;
            bigEdgeWeight += (sqrt(weight));
        }
        else
            smallEdgeWeight += (sqrt(weight));

        DSUunion(a, b);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> r;
        edges.clear();
        bigEdgeNum = bigEdgeWeight = smallEdgeWeight = 0;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edges.pb(mp(getDistance(i, j), mp(i, j)));
        sort(edges.begin(), edges.end());
        initializeDSU();
        kruskal();
        cout << "Case #" << tt << ": " << bigEdgeNum + 1 << " " << (int)(smallEdgeWeight + .5) << " " << (int)(bigEdgeWeight + .5) << endl;
    }
}
