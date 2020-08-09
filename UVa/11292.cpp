#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && (n | m))
    {
        vector<long long> heads(n, 0);
        multiset<long long> knites;
        int gold = 0;
        for (int i = 0; i < n; i++)
            cin >> heads[i];
        for (int i = 0; i < m; i++)
        {
            long long x;
            cin >> x;
            knites.insert(x);
        }

        for (int i = 0; i < n; i++)
        {
            set<long long>::iterator it = knites.lower_bound(heads[i]);
            if (it != knites.end() && *it == heads[i])
            {
                gold += *it;
                knites.erase(it);
                continue;
            }
            it = knites.upper_bound(heads[i]);
            if (it != knites.end())
            {
                gold += *it;
                knites.erase(it);
                continue;
            }
            gold = -1;
            break;
        }
        if (gold == -1)
            cout << "Loowater is doomed!" << endl;
        else
            cout << gold << endl;
    }
}
