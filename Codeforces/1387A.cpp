/*
    Washief Hossain Mugdho
    01 February 2021
    Codeforces 1387A
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
int n, m;
vpii eqn;
vector<vpii> adj;
unordered_set<int> covered;
vb visited;
bool calculated = false;
double x = 0.0;

void dfs(int node)
{
    covered.insert(node);
    visited[node] = 1;
    for (auto nei : adj[node])
    {
        int index = nei.fr;
        int edge = nei.sc;
        if (visited[index])
        {
            int constant = eqn[index].fr + eqn[node].fr;
            int coeff = eqn[index].sc + eqn[node].sc;
            if (coeff == 0)
            {
                if (constant != edge)
                {
                    cout << "NO" << endl;
                    exit(0);
                }
            }
            else if (calculated)
            {
                double newVal = 1.0 * (edge - constant) / coeff;
                if (abs(newVal - x) > 1e-6)
                {
                    cout << "NO" << endl;
                    exit(0);
                }
            }
            else
            {
                calculated = 1;
                x = 1.0 * (edge - constant) / coeff;
            }
        }
        else
        {
            eqn[index] = {edge - eqn[node].fr, -eqn[node].sc};
            dfs(index);
        }
    }
}

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
    eqn = vpii(n);
    adj = vector<vpii>(n, vpii());
    visited = vb(n);
    rep(i, m)
    {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x - 1].pb({y - 1, c});
        adj[y - 1].pb({x - 1, c});
    }
    vector<double> res(n);
    rep(i, n) if (visited[i] == 0)
    {
        covered.clear();
        calculated = 0;
        eqn[i] = {0, 1};
        dfs(i);
        if (!calculated)
        {
            vi all;
            for (auto node : covered)
                all.pb(-1 * eqn[node].sc * eqn[node].fr);
            sort(all.begin(), all.end());
            if (all.size() & 1)
                x = 1.0 * all[all.size() / 2];
            else
                x = 1.0 * (all[all.size() / 2] + all[(all.size() / 2) - 1]) / 2.0;
        }
        for (auto node : covered)
            res[node] = 1.0 * eqn[node].fr + x * eqn[node].sc;
    }
    cout << "YES" << endl;
    rep(i, n) cout << fixed << setprecision(11) << res[i] << " ";
}
