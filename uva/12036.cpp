#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        unordered_map<int, int> grid;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int entry;
                cin >> entry;
                grid[entry]++;
            }
        }
        unordered_map<int, int>::iterator it;
        cout << "Case " << t << ": ";
        for (it = grid.begin(); it != grid.end(); it++)
        {
            if (it->second > n)
            {
                cout << "no" << endl;
            }
        }
        if (it == grid.end())
            cout << "yes" << endl;
    }
}
