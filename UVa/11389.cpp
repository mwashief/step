#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, r;
    while (cin >> n >> d >> r && (n || d || r))
    {
        long long overtime = 0;
        int morning[n];
        int evening[n];
        for (int i = 0; i < n; i++)
            cin >> morning[i];

        for (int i = 0; i < n; i++)
            cin >> evening[i];
        sort(morning, morning + n);
        sort(evening, evening + n);
        for (int i = 0; i < n; i++)
        {
            int k = morning[i] + evening[n - 1 - i];
            if (k > d)
                overtime += (k - d) * r;
        }
        cout << overtime << endl;
    }
}
