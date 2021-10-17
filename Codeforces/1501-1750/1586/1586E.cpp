/*
    Washief Hossain Mugdho
    17 October 2021
    Codeforces 1501-1750 1586 1586E
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
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vvi adj(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (dsu.join(x, y))
        {
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }

    auto bfs = [&](int x, int y) -> vi
    {
        vi parent(n, -1);
        parent[x] = x;
        queue<int> q;
        q.push(x);
        vi res;
        while (gsz(q))
        {
            int u = q.front();
            q.pop();
            for (auto child : adj[u])
                if (parent[child] == -1)
                {
                    parent[child] = u;
                    q.push(child);
                }
        }
        while (y != x)
        {
            res.pb(y);
            y = parent[y];
        }
        res.pb(x);
        reverse(a2z(res));
        return res;
    };

    set<pii> parity;
    int q;
    cin >> q;
    vpii queries;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        queries.pb({x, y});
        auto path = bfs(x, y);
        rep(i, gsz(path) - 1)
        {
            int a = path[i];
            int b = path[i + 1];
            if (a > b)
                swap(a, b);
            if (parity.count({a, b}))
                parity.erase({a, b});
            else
                parity.insert({a, b});
        }
    }

    if (gsz(parity))
    {
        vector<useti> tree(n);
        for (auto p : parity)
        {
            tree[p.fr].insert(p.sc);
            tree[p.sc].insert(p.fr);
        }
        int res = 0;
        rep(i, n)
        {
            res += (gsz(tree[i]) + 1) >> 1;
            while (gsz(tree[i]))
            {
                int now = i;
                while (gsz(tree[now]))
                {
                    int u = *tree[now].begin();
                    tree[now].erase(u);
                    tree[u].erase(now);
                    now = u;
                }
            }
        }
        pno << endl;
        cout << res << endl;
    }
    else
    {
        pyes << endl;
        for (auto p : queries)
        {
            auto path = bfs(p.fr, p.sc);
            cout << gsz(path) << endl;
            for (auto node : path)
                cout << node + 1 << " ";
            cout << endl;
        }
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part again (imp**)
-> Set or multiset?
*/