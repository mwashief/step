/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 1451E2
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
int n, temp;
unordered_map<int, int> earlyResults;
vector<int> result;
pair<int, int> same = {-1, -1};
pair<int, int> inverse = {-1, -1};

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    result = vector<int>(n + 1);
    int bits = 31 - __builtin_clz(n);
    int mask = (1 << bits) - 1;
    for (int i = 2; i <= n; i++)
    {
        cout << "XOR 1 " << i << endl;
        cout.flush();
        cin >> result[i];
        if (result[i] == 0)
            same = {1, i};
        else if (earlyResults.find(result[i]) != earlyResults.end())
            same = {earlyResults[result[i]], i};
        else if (earlyResults.find(mask ^ result[i]) != earlyResults.end())
            inverse = {earlyResults[mask ^ result[i]], i};
        earlyResults[result[i]] = i;
    }
    int first = 0;
    if (same.fr != -1)
    {
        cout << "OR " << same.fr << " " << same.sc << endl;
        cout.flush();
        cin >> temp;
        first = temp ^ result[same.fr];
    }
    else
    {
        cout << "AND 1 " << inverse.fr << endl;
        cout.flush();
        cin >> first;
        cout << "AND 1 " << inverse.sc << endl;
        cout.flush();
        cin >> temp;
        first |= temp;
    }
    cout << "! " << first;
    for (int i = 2; i <= n; i++)
        cout << " " << (first ^ result[i]);
    cout << endl;
}
