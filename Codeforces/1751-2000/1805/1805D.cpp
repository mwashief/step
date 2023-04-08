/*
    02 April 2023
    Codeforces 1751-2000 1805 1805D
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
    int n;
    cin >> n;

    vvi adj(n);

    auto farthest = [&](int node) -> int
    {
        vb visited(n);
        visited[node] = true;
        queue<int> q;
        q.push(node);
        while (gsz(q))
        {
            node = q.front();
            q.pop();
            for (auto child : adj[node])
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
        }
        return node;
    };

    auto getDist = [&](int node)
    {
        vi dist(n, n), parent(n);
        dist[node] = 0;
        parent[node] = node;
        queue<int> q;
        q.push(node);
        while (gsz(q))
        {
            node = q.front();
            q.pop();
            for (auto child : adj[node])
                if (dist[child] > dist[node] + 1)
                {
                    q.push(child);
                    parent[child] = node;
                    dist[child] = dist[node] + 1;
                }
        }
        return pair{dist, parent};
    };

    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int u = farthest(0);
    int v = farthest(u);

    auto [dist, parent] = getDist(u);
    vi res(n, -1);

    int now = v;
    int d = 0;
    while (true)
    {
        res[now] = d;
        if (now == parent[now])
            break;
        now = parent[now];
        d++;
    }

    rep(i, n) if (res[i] != -1) res[i] = min(res[i], dist[v] - res[i]);

    rep(i, n) if (res[i] != -1)
    {
        y_combinator(
            [&](auto self, int node) -> void
            {
                for (auto child : adj[node])
                    if (res[child] == -1)
                    {
                        res[child] = res[node] - 1;
                        self(child);
                    }
            })(i);
    }

    vi pack(n);
    rep(i, n) pack[dist[v] - 1 - res[i]]++;
    for (int i = dist[v] - 1; i >= 0; i--)
        pack[i] += pack[i + 1];
    rep(i, n) cout << n - pack[i] + (pack[i] ? 1 : 0) << " ";
    cout << endl;
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