/*
    Washief Hossain Mugdho
    09 December 2020
    Codeforces 686F
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
int n;
vector<int> t;
vector<int> arr;

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r)
{ // min in interval [l, r)
    int res = INT32_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, t[l++]);
        if (r & 1)
            res = min(res, t[--r]);
    }
    return res;
}

void solve()
{
    cin >> n;
    t = vector<int>(2 * n + 5);
    for (int i = 0; i < n; i++)
        cin >> t[i + n];
    build();
    int a = 0, b = n - 1;
    int left = 0, right = 0;
    while (b - a > 1)
    {
        left = max(left, t[a + n]);
        right = max(right, t[b + n]);
        if (left > right)
            b--;
        else if (left < right)
            a++;
        else
        {
            bool le = false, re = false;
            while (b - a > 1) //shrinking middle partition as possible
            {
                if (t[a + 1 + n] <= left && t[b - 1 + n] <= left) // shrinkable from both sides
                {
                    if (t[a + 1 + n] <= t[b - 1 + n]) //eat up the smaller number
                    {
                        a++;
                        le = true;
                    }
                    else
                    {
                        b--;
                        re = true;
                    }
                }
                else if (t[a + 1 + n] <= left) // shrinkable from left
                {
                    a++;
                    le = true;
                }
                else if (t[b - 1 + n] <= left) // shrinkable from right
                {
                    b--;
                    re = true;
                }
                else
                    break;
            }
            int d = query(a + 1, b);
            if (left == d)
            {
                cout << "YES" << endl;
                cout << a + 1 << " " << b - a - 1 << " " << n - b << endl;
                return;
            }
            else
            {
                if (le) //if left was expanded then we cat take a element from left for middle partition
                {
                    d = query(a, b);
                    if (left == d)
                    {
                        cout << "YES" << endl;
                        cout << a << " " << b - a << " " << n - b << endl;
                        return;
                    }
                }
                if (re) //if right was expanded then we cat take a element from right for middle partition
                {
                    d = query(a + 1, b + 1);
                    if (left == d)
                    {
                        cout << "YES" << endl;
                        cout << a + 1 << " " << b - a << " " << n - b - 1 << endl;
                        return;
                    }
                }
                a++;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
