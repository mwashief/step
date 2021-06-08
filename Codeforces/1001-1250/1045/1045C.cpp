/*
    Washief Hossain Mugdho
    07 June 2021
    Codeforces 1001-1250 1045 1045C
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

template <class T>
T OP(const T &value1, const T &value2)
{
    //change here
    return value1 + value2;
}

template <class T>
class LCA
{
public:
    static const int logHeight = 18; // change here
    int n;
    T initialValue;
    std::vector<int> depth;
    std::vector<std::vector<std::pair<int, T>>> edges;
    std::vector<std::vector<int>> lift;
    std::vector<std::vector<T>> value;

    LCA(int numberOfNodes, T ini) : n(numberOfNodes), initialValue(ini)
    {
        depth = vector<int>(n);
        edges = vector<vector<std::pair<int, T>>>(n, vector<std::pair<int, T>>());
        lift = vector<vector<int>>(n, vector<int>(logHeight, -1));
        //change here
        value = vector<vector<T>>(n, vector<T>(logHeight, ini));
    }

    void addEdge(int a, int b, T val)
    {
        edges[a].push_back(std::make_pair(b, val));
        edges[b].push_back(std::make_pair(a, val));
    }

    void attach(int node, int parent, T val)
    {
        addEdge(node, parent, val);

        lift[node][0] = parent;
        value[node][0] = val;

        for (int i = 1; i < logHeight; i++)
        {
            if (lift[node][i - 1] == -1)
            {
                lift[node][i] = -1;
                value[node][i] = value[node][i - 1];
            }
            else
            {
                value[node][i] = OP(value[node][i - 1], value[lift[node][i - 1]][i - 1]);
                lift[node][i] = lift[lift[node][i - 1]][i - 1];
            }
        }

        depth[node] = depth[parent] + 1;
    }

    void build(int v = 0)
    {
        depth[v] = 0;
        //dfs(v, -1, initialValue);
        bfs(v);
    }

    void dfs(int node, int parent, const T &edge)
    {
        lift[node][0] = parent;
        value[node][0] = edge;

        for (int i = 1; i < logHeight; i++)
        {
            if (lift[node][i - 1] == -1)
            {
                lift[node][i] = -1;
                value[node][i] = value[node][i - 1];
            }
            else
            {
                value[node][i] = OP(value[node][i - 1], value[lift[node][i - 1]][i - 1]);
                lift[node][i] = lift[lift[node][i - 1]][i - 1];
            }
        }
        for (pair<int, T> &child : edges[node])
            if (child.first != parent)
            {
                depth[child.first] = depth[node] + 1;
                dfs(child.first, node, child.second);
            }
    }

    void bfs(int node)
    {
        std::queue<tuple<int, int, T>> q;
        q.push({node, -1, initialValue});
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            node = std::get<0>(u);
            int parent = std::get<1>(u);
            auto edge = std::get<2>(u);
            lift[node][0] = parent;
            value[node][0] = edge;
            for (int i = 1; i < logHeight; i++)
            {
                if (lift[node][i - 1] == -1)
                {
                    lift[node][i] = -1;
                    value[node][i] = value[node][i - 1];
                }
                else
                {
                    value[node][i] = OP(value[node][i - 1], value[lift[node][i - 1]][i - 1]);
                    lift[node][i] = lift[lift[node][i - 1]][i - 1];
                }
            }
            for (pair<int, T> &child : edges[node])
                if (child.first != parent)
                {
                    depth[child.first] = depth[node] + 1;
                    q.push({child.first, node, child.second});
                }
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

    T getUpValue(int node, int steps)
    {
        T result = initialValue;
        for (int i = logHeight - 1; i >= 0; i--)
        {
            if (node == -1)
                return result;
            if ((1 << i) <= steps)
            {
                result = OP(result, value[node][i]);
                node = lift[node][i];
                steps -= (1 << i);
            }
        }
        return result;
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

    int getEdgesBetween(int node1, int node2)
    {
        int lca = getLca(node1, node2);
        return depth[node1] + depth[node2] - 2 * depth[lca];
    }

    T getValueBetween(int node1, int node2)
    {
        int lca = getLca(node1, node2);
        T value1 = getUpValue(node1, depth[node1] - depth[lca]);
        T value2 = getUpValue(node2, depth[node2] - depth[lca]);
        return OP(value1, value2);
    }
};

class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        return parent[subset] = getRepresentative(parent[subset]);
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    bool join(int subset1, int subset2)
    {
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
            swap(subset1, subset2);
        subsetSize[subset1] += subsetSize[subset2];
        parent[subset2] = subset1;
        return true;
    }
};

namespace std
{

    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

    template <class T>
    T &unmove(T &&t) { return t; }

}

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
    int n, m, q;
    cin >> n >> m >> q;
    vvi adj(n);

    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vb visited(n);
    vi stk;
    stk.reserve(n + 1);
    vi inStack(n, INT32_MAX);
    vvi cliques;
    set<pii> taken;
    cliques.reserve(n);
    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     if (visited[node])
                         return;
                     visited[node] = true;
                     int cycleStart = INT32_MAX;
                     inStack[node] = stk.size();
                     stk.pb(node);
                     for (int &child : adj[node])
                         if (child != parent)
                         {
                             cycleStart = min(cycleStart, inStack[child]);
                             self(child, node);
                         }

                     if (cycleStart != INT32_MAX && node != parent && taken.find(mp(min(node, parent), max(node, parent))) == taken.end())
                     {
                         cliques.pb(vi());
                         cliques.back().reserve(stk.size() - cycleStart + 1);
                         for (int i = cycleStart; i < stk.size(); i++)
                         {
                             cliques.back().pb(stk[i]);
                             if (i != stk.size() - 1)
                                 taken.insert(mp(min(stk[i], stk[i + 1]), max(stk[i], stk[i + 1])));
                         }
                     }

                     inStack[node] = INT32_MAX;
                     stk.pop_back();
                 })(0, 0);
    DSU dsu(n);
    LCA<int> lca(n + cliques.size(), 0);

    for (int i = 0; i < cliques.size(); i++)
        rep(j, cliques[i].size())
        {
            lca.addEdge(n + i, cliques[i][j], 1);
            dsu.join(cliques[i][0], cliques[i][j]);
        }

    rep(i, n) for (auto child : adj[i]) if (child < i && !dsu.isConnected(i, child)) lca.addEdge(i, child, 2);
    lca.build();
    rep(i, q)
    {
        int u, v;
        cin >> u >> v;
        auto res = lca.getValueBetween(u - 1, v - 1);
        cout << (res >> 1) << endl;
    }
}