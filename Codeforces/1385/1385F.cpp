/*
    Washief Hossain Mugdho
    23 April 2021
    Codeforces 1385 1385F
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

inline void _()
{
    int n, k;
    cin >> n >> k;
    seti adj[n];
    seti leaf[n];
    seti leafContaining[n];
    int leafCount[n];
    multiset<int, greater<int>> currentLeafers;
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    rep(i, n)
    {
        vi temp;
        for (auto d : adj[i])
            if ((gsz(adj[d]) + gsz(leaf[d])) == 1)
            {
                leaf[i].insert(d);
                temp.pb(d);
            }
        for (int d : temp)
            adj[i].erase(d);
        leafCount[i] = gsz(leaf[i]);
        leafContaining[leafCount[i]].insert(i);
        currentLeafers.insert(leafCount[i]);
    }
    int res = 0;
    vb erased(n);
    while (gsz(currentLeafers))
    {
        auto a = *currentLeafers.begin();
        currentLeafers.erase(currentLeafers.begin());
        if (a < k)
            break;
        int node = *leafContaining[a].begin();
        leafContaining[a].erase(leafContaining[a].begin());
        if (erased[node])
            continue;
        rep(i, k)
        {
            erased[*leaf[node].begin()] = true;
            leaf[node].erase(leaf[node].begin());
        }
        leafCount[node] = gsz(leaf[node]);

        if (leafCount[node])
        {
            leafContaining[leafCount[node]].insert(node);
            currentLeafers.insert(leafCount[node]);
        }
        else if (gsz(adj[node]) == 1)
        {
            int parent = *adj[node].begin();
            adj[parent].erase(node);
            leaf[parent].insert(node);
            leafContaining[leafCount[parent]].erase(parent);
            auto d = currentLeafers.find(leafCount[parent]);
            currentLeafers.erase(d);
            leafCount[parent]++;
            currentLeafers.insert(leafCount[parent]);
            leafContaining[leafCount[parent]].insert(parent);
        }
        res++;
    }
    cout << res << endl;
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