/*
    Washief Hossain Mugdho
    30 July 2020
    UVa 1237
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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<pair<pair<int, int>, string>> all;
        int a, b, x, n;
        cin >> n;
        string s, ans;

        for (int i = 0; i < n; i++)
        {
            cin >> s >> a >> b;
            all.push_back(mp(mp(a, b), s));
        }
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            k = 0;
            cin >> x;
            for (int i = 0; i < all.size(); i++)
            {
                if (x >= all[i].first.first && x <= all[i].first.second)
                {
                    if (k >= 1)
                    {
                        k = 0;
                        break;
                    }
                    k++;
                    ans = all[i].second;
                }
            }
            if (k > 0)
                cout << ans << endl;
            else
                cout << "UNDETERMINED" << endl;
        }
        if (T != 0)
            cout << endl;
    }
}