/*
    Washief Hossain Mugdho
    20 April 2021
    Codeforces 1333 1333D
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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    t = s;

    int r = 0;
    int last = 0;
    rep(i, n) if (s[i] == 'L')
    {
        r += i - last;
        last++;
    }
    int l = 0;
    list<int> current;
    rep(i, n - 1) if (s[i] == 'R' && s[i + 1] == 'L')
        current.pb(i + 1);

    while (!current.empty())
    {
        list<int> temp;
        while (!current.empty())
        {
            auto a = current.front();
            current.pop_front();
            swap(s[a], s[a - 1]);
            if (a - 2 >= 0 && s[a - 2] == 'R')
                temp.pb(a - 1);
            if (a + 1 < n && s[a + 1] == 'L')
                temp.pb(a + 1);
        }
        current.splice(current.end(), temp);
        l++;
    }

    if (k < l || k > r)
    {
        cout << -1 << endl;
        return 0;
    }

    rep(i, n - 1) if (t[i] == 'R' && t[i + 1] == 'L')
        current.pb(i + 1);

    int spare = r - k;
    int res[n];
    rep(kk, k)
    {
        int taken = 0;
        list<int> temp;
        while (!current.empty())
        {
            if (!taken)
            {
                auto a = current.front();
                current.pop_front();
                swap(t[a], t[a - 1]);
                if (a - 2 >= 0 && t[a - 2] == 'R')
                    temp.pb(a - 1);
                if (a + 1 < n && t[a + 1] == 'L')
                    temp.pb(a + 1);
                res[taken] = a;
                taken = 1;
            }
            else if (spare)
            {
                auto a = current.front();
                current.pop_front();
                swap(t[a], t[a - 1]);
                if (a - 2 >= 0 && t[a - 2] == 'R')
                    temp.pb(a - 1);
                if (a + 1 < n && t[a + 1] == 'L')
                    temp.pb(a + 1);
                res[taken] = a;
                spare--;
                taken++;
            }
            else
            {
                temp.splice(temp.end(), current);
                break;
            }
        }
        cout << taken << " ";
        rep(i, taken) cout << res[i] << " ";
        cout << "\n";
        current.splice(current.end(), temp);
    }
}
