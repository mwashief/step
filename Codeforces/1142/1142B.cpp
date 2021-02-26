/*
    Washief Hossain Mugdho
    26 February 2021
    1142 1142B
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
int n, m, q, l;
vi p, a, b, previous;
vvi lift;

int getPos(int endPoint, int dist)
{
    for (int i = l - 1; i >= 0; i--)
    {
        if (endPoint == -1)
            return -1;
        if ((1 << i) <= dist)
        {
            dist -= (1 << i);
            endPoint = lift[endPoint][i];
        }
    }
    return endPoint;
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

    cin >> n >> m >> q;
    p = vi(n);
    a = vi(m);
    b = vi(m);
    previous = vi(n + 1);
    rep(i, n) cin >> p[i];
    rep(i, m) cin >> a[i];
    rep(i, n) previous[p[i]] = p[(i + n - 1) % n];
    vi track(n + 1, -1);
    rep(i, m)
    {
        b[i] = track[previous[a[i]]];
        track[a[i]] = i;
    }

    l = ceil(log2(m + 1));
    lift = vvi(m, vi(l, -1));
    rep(i, m) lift[i][0] = b[i];
    repe(i, l - 1) rep(j, m)
    {
        if (lift[j][i - 1] == -1)
            continue;
        int pre = lift[j][i - 1];
        lift[j][i] = lift[pre][i - 1];
    }

    vi nearestEnd(m, m);
    rrep(i, m)
    {
        int endPoint = getPos(i, n - 1);
        if (endPoint != -1)
            nearestEnd[endPoint] = i;
        if (i != m - 1)
            nearestEnd[i] = min(nearestEnd[i], nearestEnd[i + 1]);
    }

    rep(qq, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << (nearestEnd[x] <= y ? 1 : 0);
    }
    cout << endl;
}
