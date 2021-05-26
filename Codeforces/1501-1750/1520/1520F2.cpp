/*
    Washief Hossain Mugdho
    05 May 2021
    Codeforces 1520 1520F2
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
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 4

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

class BIT
{
private:
    vector<int> ft;

public:
    int query(int x)
    {
        x++;
        int sum = 0;
        while (x > 0)
        {
            sum = sum + ft[x];
            x = x - (x & (-x));
        }
        return sum;
    }

    int query(int start, int end)
    {
        return query(end) - query(start - 1);
    }

    void update(int pos, int value)
    {
        pos++;
        while (pos <= ft.size())
        {
            ft[pos] += value;
            pos = pos + (pos & (-pos));
        }
    }

    BIT(vector<int> array)
    {
        int n = array.size();
        ft.assign(n + 1, 0);
        for (int i = 0; i < n; ++i)
            update(i, array[i]);
    }

    BIT(int n)
    {
        ft.assign(n + 1, 0);
    }
};

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int temp;
    cin >> temp;
    return r - l + 1 - temp;
}

int main()
{
    fastio;
    int n, t, last;
    cin >> n >> t >> last;
    int segs = (n + 9) / 10;
    BIT cnt(segs + 5);
    rep(i, segs) cnt.update(i, query(10 * i + 1, min(n, 10 * i + 10)));

    auto find = [&](int a, int b, int c) -> int {
        int l = a;
        int r = b;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(a, mid) >= c)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    };

    repe(i, t)
    {
        int now = last;
        int l = 0;
        int r = segs - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (cnt.query(mid) < now)
                l = mid + 1;
            else
                r = mid;
        }
        int look = 0;
        if (l != 0)
            look = cnt.query(l - 1);
        look = last - look;
        int temp = find(10 * l + 1, min(n, 10 * l + 10), look);
        cout << "! " << temp << endl;
        cnt.update(l, -1);
        if (i != t)
            cin >> last;
    }
}
