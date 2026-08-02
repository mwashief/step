#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10005];

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int longest = 1;
        int current = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                current++;
            else
                current = 1;
            longest = max(longest, current);
        }
        vector<set<int>> ans(longest, set<int>());
        for (int i = 0; i < n; i++)
            ans[i % longest].insert(arr[i]);

        cout << longest << endl;
        for (int i = 0; i < longest; i++)
        {
            for (auto it = ans[i].begin(); it != ans[i].end(); it++)
            {
                if (it != ans[i].begin())
                    cout << " ";
                cout << *it;
            }
            cout << endl;
        }
        cout << endl;
    }
}
