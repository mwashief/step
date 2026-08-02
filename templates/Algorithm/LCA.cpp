/*
    Washief Hossain Mugdho
    06 June 2021
    Templates DS LCA
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

/*
 * Taken from galen's repository
 * Edited slightly
 */
struct LCA
{
    static const int logHeight = 24;
    int n;
    std::vector<int> depth;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> lift;

    LCA(int numberOfNodes) : n(numberOfNodes)
    {
        depth = vector<int>(n);
        edges = vector<vector<int>>(n, vector<int>());
        lift = vector<vector<int>>(n, vector<int>(logHeight, -1));
    }

    void addEdge(int a, int b)
    {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void attach(int node, int parent)
    {
        addEdge(node, parent);

        lift[node][0] = parent;

        for (int i = 1; i < logHeight; i++)
        {
            if (lift[node][i - 1] == -1)
                lift[node][i] = -1;
            else
                lift[node][i] = lift[lift[node][i - 1]][i - 1];
        }

        depth[node] = depth[parent] + 1;
    }

    void build(int v = 0)
    {
        depth[v] = 0;
        dfs(v, -1);
    }

    void dfs(int node, int parent)
    {
        lift[node][0] = parent;

        for (int i = 1; i < logHeight; i++)
        {
            if (lift[node][i - 1] == -1)
                lift[node][i] = -1;
            else
                lift[node][i] = lift[lift[node][i - 1]][i - 1];
        }

        for (int x : edges[node])
            if (x != parent)
            {
                depth[x] = depth[node] + 1;
                dfs(x, node);
            }
    }

    int getAncestor(int node, int steps)
    {
        for (int i = logHeight - 1; i >= 0; i--)
        {
            if (node == -1)
                return node;
            if ((1 << i) <= steps)
            {
                node = lift[node][i];
                steps -= (1 << i);
            }
        }
        return node;
    }

    int getLca(int node1, int node2)
    {
        if (depth[node1] < depth[node2])
            swap(node1, node2);
        int depthDifference = depth[node1] - depth[node2];
        node1 = getAncestor(node1, depthDifference);

        if (node1 == node2)
            return node1;
        else
            for (int i = logHeight - 1; i >= 0; i--)
                if (lift[node1][i] != lift[node2][i])
                {
                    node1 = lift[node1][i];
                    node2 = lift[node2][i];
                }
        return lift[node2][0];
    }

    int getDistance(int node1, int node2)
    {
        int lca = getLca(node1, node2);
        return depth[node1] + depth[node2] - 2 * depth[lca];
    }
};

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
}