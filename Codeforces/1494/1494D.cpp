/*
    Washief Hossain Mugdho
    13 March 2021
    1494 1494D
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
int k;
vi parent, c;
vvi a;

void makeTree(int par, unordered_set<int> &leaves)
{
    if (leaves.size() == 1)
    {
        int index = *leaves.begin();
        parent[index] = par + 1;
        c[index] = a[index][index];
        return;
    }
    int maximum = 0;
    rep(i, k) if (leaves.find(i) != leaves.end()) for (int j = i + 1; j < k; j++) if (leaves.find(j) != leaves.end())
        maximum = max(maximum, a[i][j]);

    vector<unordered_set<int>> subTrees;
    for (auto d : leaves)
    {
        if (subTrees.size() == 0)
        {
            subTrees.pb(unordered_set<int>());
            subTrees.back().insert(d);
            continue;
        }
        bool newTree = true;
        for (unordered_set<int> &sub : subTrees)
            if (a[*sub.begin()][d] < maximum)
            {
                newTree = false;
                sub.insert(d);
                break;
            }
        if (newTree)
        {
            subTrees.pb(unordered_set<int>());
            subTrees.back().insert(d);
        }
    }
    int id = parent.size();
    parent.pb(par + 1);
    c.pb(maximum);
    for (auto sub : subTrees)
        makeTree(id, sub);
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
    cin >> k;
    a = vvi(k, vi(k));
    c = vi(k);
    parent = vi(k);
    unordered_set<int> leaves;
    rep(i, k)
    {
        rep(j, k) cin >> a[i][j];
        leaves.insert(i);
    }
    makeTree(-1, leaves);
    cout << c.size() << endl;
    for (auto cc : c)
        cout << cc << " ";
    cout << endl;
    cout << k + 1 << endl;
    for (int i = 0; i < k; i++)
        cout << i + 1 << " " << parent[i] << endl;
    for (int i = k + 1; i < parent.size(); i++)
        cout << i + 1 << " " << parent[i] << endl;
}
