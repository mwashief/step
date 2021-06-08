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

typedef long long ll;
typedef unsigned long long ull;

template <class T>
T OP(T value1, T value2)
{
    //change here
    return max(value1, value2);
}

template <class T>
class LCA
{
public:
    static const int logHeight = 24; // change here
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

    void dfs(int node, int parent, T edge)
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

        for (auto child : edges[node])
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

int main()
{
}