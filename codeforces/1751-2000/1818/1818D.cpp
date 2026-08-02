/*
    29 April 2023
    Codeforces 1751-2000 1818 1818D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
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

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
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

    rep(i, n) if (gsz(adj[i]) > 3)
    {
        DSU dsu(n);
        rep(j, n) if (j != i) for (auto c : adj[j]) if (c != i) dsu.join(c, j);
        mii reps;
        int u = -1, v = -1;
        for (auto c : adj[i])
        {
            int rep = dsu.getRepresentative(c);
            if (reps.find(rep) != reps.end())
            {
                u = c;
                v = reps[rep];
                break;
            }
            reps[rep] = c;
        }
        if (u != -1)
        {
            pyes << endl;
            queue<int> q;
            vi dis(n, INT32_MAX);
            vi parent(n, -1);
            dis[u] = 0;
            dis[i] = -1;
            q.push(u);
            while (gsz(q))
            {
                int x = q.front();
                q.pop();
                for (auto c : adj[x])
                    if (dis[c] > dis[x] + 1)
                    {
                        dis[c] = dis[x] + 1;
                        parent[c] = x;
                        q.push(c);
                    }
            }
            seti extra;
            for (auto c : adj[i])
                if (c != u && c != v)
                    extra.insert(c);

            int now = v;
            vi res;
            while (now != -1)
            {
                if (extra.contains(now))
                {
                    res.clear();
                    extra.erase(now);
                    extra.insert(v);
                    v = now;
                }

                res.pb(now);

                now = parent[now];
            }

            cout << gsz(res) + 3 << endl;
            cout << i + 1 << " " << u + 1 << endl;
            cout << i + 1 << " " << v + 1 << endl;
            repe(j, gsz(res) - 1) cout << res[j] + 1 << " " << res[j - 1] + 1 << endl;
            cout << i + 1 << " " << *extra.begin() + 1 << endl;
            extra.erase(extra.begin());
            cout << i + 1 << " " << *extra.begin() + 1 << endl;

            return;
        }
    }
    pno << endl;
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/