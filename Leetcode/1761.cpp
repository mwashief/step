/*
    Washief Hossain Mugdho
    17 February 2021
    Leetcode 1761
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

class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> adj(n + 1);
        for (auto x : edges)
        {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        unsigned long long res = INT32_MAX;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = j + 1; k <= n; k++)
                    if (adj[i].find(j) != adj[i].end() && adj[i].find(k) != adj[i].end() && adj[j].find(k) != adj[j].end())
                        res = min(res, adj[i].size() + adj[j].size() + adj[k].size() - 6ULL);

        if (res == INT32_MAX)
            return -1;
        return res;
    }
};

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    Solution s;
    int n = 6;
    vvi a = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    cout << s.minTrioDegree(n, a);
}
