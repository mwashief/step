/*
    Washief Hossain Mugdho
    27 March 2021
    Algorithm FST
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

template <class T>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vi(n << 1);
    }

    SegmentTree(vector<T> v)
    {
        n = v.size();
        t = vi(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, int value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    T query(int l, int r)
    {
        r++;
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
};

int main()
{
    SegmentTree<int> ss(10);
    ss.update(2, 5);
    ss.update(0, 3);
    cout << ss.query(0, 3) << endl;
}
