#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    vector<int> v;
    while (cin >> x)
        v.push_back(x);

    vector<int> I(v.size() + 1, INT32_MAX);
    I[0] = INT32_MIN;

    vector<int> LIS(v.size(), 0);
    stack<int> pri;

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto it = lower_bound(I.begin(), I.end(), v[i]);
        *it = v[i];
        LIS[i] = it - I.begin();
        ans = max(ans, LIS[i]);
    }
    int temp = ans;
    for (int i = v.size() - 1; i >= 0 && temp; i--)
    {
        if (LIS[i] == temp)
        {
            pri.push(v[i]);
            temp--;
        }
    }
    cout << ans << endl
         << "-" << endl;
    while (pri.size())
    {
        cout << pri.top() << endl;
        pri.pop();
    }
}