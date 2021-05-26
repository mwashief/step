/*
    Washief Hossain Mugdho
    17 February 2021
    1423 1423B
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

struct BipartiteMatcher
{
    vector<vector<int>> G;
    vector<int> L, R, Viz;

    BipartiteMatcher(int n, int m) : G(n), L(n, -1), R(m, -1), Viz(n) {}

    void AddEdge(int a, int b)
    {
        G[a].push_back(b);
    }

    bool Match(int node)
    {
        if (Viz[node])
            return false;
        Viz[node] = true;

        for (auto vec : G[node])
        {
            if (R[vec] == -1)
            {
                L[node] = vec;
                R[vec] = node;
                return true;
            }
        }

        for (auto vec : G[node])
        {
            if (Match(R[vec]))
            {
                L[node] = vec;
                R[vec] = node;
                return true;
            }
        }

        return false;
    }

    int Solve()
    {
        int ok = true;
        while (ok--)
        {
            fill(Viz.begin(), Viz.end(), 0);
            for (int i = 0; i < (int)L.size(); ++i)
                if (L[i] == -1)
                    ok |= Match(i);
        }

        int ret = 0;
        for (int i = 0; i < L.size(); ++i)
            ret += (L[i] != -1);
        return ret;
    }
};
int n, m;

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> m;
    vector<pair<pii, int>> all;
    vi cost;
    rep(i, m)
    {
        int x, y, z;
        cin >> x >> y >> z;
        all.pb({{x - 1, y - 1}, z});
        cost.pb(z);
    }
    sort(cost.begin(), cost.end());
    int l = 0;
    int r = m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        BipartiteMatcher bm(n, n);
        for (auto x : all)
            if (x.sc <= cost[mid])
                bm.AddEdge(x.fr.fr, x.fr.sc);
        if (bm.Solve() == n)
            r = mid;
        else
            l = mid + 1;
    }
    if (l == m)
        cout << -1 << endl;
    else
        cout << cost[l] << endl;
}
