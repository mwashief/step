/*
    Washief Hossain Mugdho
    24 December 2020
    Codeforces 169C
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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n, q;
vi a, t;

void update(int node, int start, int finish, int l, int r)
{
    if (start >= l && finish <= r)
    {
        t[node]++;
        return;
    }
    if (start > r || finish < l)
        return;
    int mid = (start + finish) >> 1;
    int leftNode = (node << 1) + 1;
    int rightNode = (node << 1) + 2;
    update(leftNode, start, mid, l, r);
    update(rightNode, mid + 1, finish, l, r);
}

int query(int node, int start, int finish, int index)
{
    if (start == index && finish == index)
        return t[node];
    if (start > index || finish < index)
        return 0;
    int mid = (start + finish) >> 1;
    int leftNode = (node << 1) + 1;
    int rightNode = (node << 1) + 2;
    t[leftNode] += t[node];
    t[rightNode] += t[node];
    t[node] = 0;
    return query(leftNode, start, mid, index) + query(rightNode, mid + 1, finish, index);
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    input(n, q);
    a = vi(n);
    t = vi(4 * n, 0);
    rep(i, n) input(a[i]);
    sort(a.begin(), a.end(), greater<int>());
    rep(i, q)
    {
        int l, r;
        input(l, r);
        update(0, 0, n - 1, l - 1, r - 1);
    }
    priority_queue<int> PQ;
    rep(i, n)
        PQ.push(query(0, 0, n - 1, i));
    ll res = 0;
    int i = 0;
    while (!PQ.empty())
    {
        res += (ll)PQ.top() * a[i];
        PQ.pop();
        i++;
    }
    print(res, "\n");
}
