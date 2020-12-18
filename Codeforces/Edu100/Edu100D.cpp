/*
    Washief Hossain Mugdho
    18 December 2020
    Edu100 Edu100D
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
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

void run_tests()
{
    int n;
    cin >> n;
    set<int> ascendingList;
    set<int, greater<int>> descendingList;
    vector<int> given(n);

    for (int i = 1; i <= 2 * n; i++)
        ascendingList.insert(i);
    for (int i = 0; i < n; i++)
    {
        cin >> given[i];
        ascendingList.erase(given[i]);
    }
    for (auto x : ascendingList)
        descendingList.insert(x);
    int minx = n;
    for (int i = n - 1; i >= 0; i--)
    {
        auto it = descendingList.upper_bound(given[i]);
        if (it == descendingList.end())
            descendingList.erase(*descendingList.begin());
        else
        {
            minx--;
            descendingList.erase(*it);
        }
    }
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = ascendingList.upper_bound(given[i]);
        if (it == ascendingList.end())
            ascendingList.erase(*ascendingList.begin());
        else
        {
            maxx++;
            ascendingList.erase(*it);
        }
    }

    cout << maxx - minx + 1 << endl;
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

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
