#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, x;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        int n;
        int increasing = 0;
        int decreasing = 0;

        cin >> n;
        vector<int> v;
        vector<int> width;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            width.push_back(x);
        }

        vector<int> inc(v.size(), 0);
        vector<int> dec(v.size(), 0);

        for (int i = 0; i < v.size(); i++)
        {
            inc[i] = width[i];
            dec[i] = width[i];
            for (int j = 0; j < i; j++)
            {
                if (v[i] > v[j])
                    inc[i] = max(inc[i], width[i] + inc[j]);
                if (v[i] < v[j])
                    dec[i] = max(dec[i], width[i] + dec[j]);
            }
            increasing = max(increasing, inc[i]);
            decreasing = max(decreasing, dec[i]);
        }

        cout << "Case " << tt << ". ";
        if (increasing >= decreasing)
            cout << "Increasing (" << increasing << "). Decreasing (" << decreasing << ")." << endl;
        else
            cout << "Decreasing (" << decreasing << "). Increasing (" << increasing << ")." << endl;
    }
}
