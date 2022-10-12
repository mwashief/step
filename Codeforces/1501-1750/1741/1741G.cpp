/*
    Washief Hossain Mugdho
    11 October 2022
    Codeforces 1501-1750 1741 1741G
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

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
    vi level(n, n);

    queue<int> q;
    q.push(0);
    level[0] = 0;

    while (gsz(q))
    {
        int u = q.front();
        q.pop();

        for (auto child : adj[u])
            if (level[child] > level[u] + 1)
            {
                level[child] = level[u] + 1;
                q.push(child);
            }
    }

    int f;
    cin >> f;
    vi h(f);
    rep(i, f)
    {
        cin >> h[i];
        h[i]--;
    }

    int k;
    cin >> k;
    vi carless(k);
    rep(i, k)
    {
        cin >> carless[i];
        carless[i]--;
    }

    sort(a2z(carless), [&](int a, int b) -> bool
         { return level[h[a]] < level[h[b]]; });

    auto hasCar = [&](int i) -> bool
    {
        rep(j, k) if (carless[j] == i) return false;
        return true;
    };

    map<int, vi> nodeToFriends;

    rep(i, f) if (hasCar(i)) nodeToFriends[h[i]].pb(i);

    vvb canTake(1 << k, vb(f));
    for (int i = 1; i < (1 << k); i++)
    {
        vi candidates;
        rrep(j, k) if (i & (1 << j)) candidates.pb(h[carless[j]]);

        int lastBoy = candidates[0];

        q = queue<int>();
        q.push(0);

        while (gsz(q))
        {
            int u = q.front();
            q.pop();
            while (gsz(candidates) && u == candidates.back())
            {
                candidates.pop_back();
                q = queue<int>();
            }

            if (gsz(candidates) == 0)
                break;

            for (auto child : adj[u])
                if (level[child] > level[u])
                    q.push(child);
        }

        if (gsz(candidates) == 0)
        {
            q = queue<int>();
            q.push(lastBoy);
            while (gsz(q))
            {
                int u = q.front();
                q.pop();

                for (auto frnd : nodeToFriends[u])
                    canTake[i][frnd] = true;

                for (auto child : adj[u])
                    if (level[child] > level[u])
                        q.push(child);
            }
        }
    }

    vvi memo(1 << k, vi(f + 1, -1));

    cout << y_combinator([&](auto self, int mask, int frnd) -> int
                         {
                             if(memo[mask][frnd] != -1) return memo[mask][frnd];
                             if (frnd == f)
                             {
                                 int remaining = 0;
                                 rrep(j, k) if (mask & (1 << j)) remaining++;
                                 return memo[mask][frnd] = remaining;
                             }
                             if (!hasCar(frnd))
                                 return memo[mask][frnd] = self(mask, frnd + 1);

                            int res = self(mask, frnd+1);

                            for (int s=mask; s; s=(s-1)&mask) if(canTake[s][frnd])
                                res = min(res, self(mask & (~s), frnd + 1));

                            return memo[mask][frnd] = res; })((1 << k) - 1, 0)
         << endl;
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