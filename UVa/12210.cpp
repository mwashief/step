#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, caseNo = 1;
    while (cin >> n >> m && (n || m))
    {
        int lowest = 100;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            lowest = min(lowest, x);
        }
        for (int i = 0; i < m; i++)
            cin >> x;
        cout << "Case " << caseNo << ": ";
        if (n > m)
            cout << n - m
                 << " " << lowest;
        else
            cout << "0";
        cout << endl;
        caseNo++;
    }
}