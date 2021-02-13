/*
    Washief Hossain Mugdho
    12 February 2021
    701Div2 E
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
int n;
vector<unordered_set<int>> child;
vvi levelWise;
vi levelMax, levelMin;
vi cost;
vl memo;

void dfs(int node, int level)
{
    if (levelWise.size() < level + 1)
        levelWise.pb(vi());
    levelWise[level].pb(node);
    for (auto chi : child[node])
        dfs(chi, level + 1);
}

inline void _()
{
    cin >> n;
    child = vector<unordered_set<int>>(n);
    levelWise.clear();
    cost = vi(n);
    memo = vl(n);
    levelMax.clear();
    levelMin.clear();
    repe(i, n - 1)
    {
        int x;
        cin >> x;
        x--;
        child[x].insert(i);
    }
    repe(i, n - 1) cin >> cost[i];
    dfs(0, 0);
    for (int i = 0; i < levelWise.size(); i++)
    {
        int mini = INT32_MAX;
        int maxi = 0;
        for (auto x : levelWise[i])
        {
            mini = min(mini, cost[x]);
            maxi = max(maxi, cost[x]);
        }
        levelMin.pb(mini);
        levelMax.pb(maxi);
    }
    ll valPLus = INT64_MIN, valMinus = INT64_MIN;
    for (int i = 0; i < levelWise.back().size(); i++)
    {
        valPLus = max(valPLus, memo[levelWise.back()[i]] + cost[levelWise.back()[i]]);
        valMinus = max(valMinus, memo[levelWise.back()[i]] - cost[levelWise.back()[i]]);
    }

    rrep(i, levelWise.size() - 1)
    {
        ll tempPlus = INT64_MIN;
        ll tempMinus = INT64_MIN;
        for (int j = 0; j < levelWise[i].size(); j++)
        {
            int node = levelWise[i][j];
            ll maxi = 0;
            ll mini = INT64_MAX;
            for (auto chi : child[node])
            {
                maxi = max(maxi, (ll)cost[chi]);
                mini = min(mini, (ll)cost[chi]);
                memo[node] = max(memo[node], memo[chi] + max(abs(cost[chi] - levelMax[i + 1]), abs(cost[chi] - levelMin[i + 1])));
            }
            memo[node] = max({memo[node], valPLus - mini, valMinus + maxi});
            tempPlus = max(tempPlus, memo[node] + cost[node]);
            tempMinus = max(tempMinus, memo[node] - cost[node]);
        }
        valPLus = tempPlus;
        valMinus = tempMinus;
    }
    cout << memo[0] << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
