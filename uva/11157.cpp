/*
    Washief Hossain Mugdho
    30 July 2020
    UVa 11157
*/

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

int leap(vector<int> &v)
{
    int ans = 0;
    for (int i = 2; i < v.size(); i++)
        ans = max(ans, v[i] - v[i - 2]);
    return ans;
}

int main()
{
    int T, n, d, x;
    char c, junk;
    cin >> T;

    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> d;
        vector<vector<int>> intervals;
        intervals.push_back(vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> c >> junk >> x;
            intervals[intervals.size() - 1].push_back(x);
            if (c == 'B')
            {
                intervals[intervals.size() - 1].push_back(x);
                intervals.push_back(vector<int>(2, x));
            }
        }
        intervals[intervals.size() - 1].push_back(d);
        intervals[intervals.size() - 1].push_back(d);
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++)
            ans = max(ans, leap(intervals[i]));
        cout << "Case " << tt << ": " << ans << endl;
    }
}
