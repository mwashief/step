#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cout << "PERFECTION OUTPUT\n";
    while (1)
    {
        cin >> d;
        if (!d)
            break;
        int i, total = 0;
        for (i = 2; i * i < d; i++)
        {
            if (d % i == 0)
            {
                total += (i + d / i);
            }
        }
        if (i * i == d)
            total += i;
        total++;
        for (i = 10000; i > 5; i = i / 10)
        {
            if (d < i)
                cout << " ";
        }
        cout << d << " ";
        if (total < d)
            cout << "DEFICIENT\n";
        else if (total == d)
            cout << "PERFECT\n";
        else
            cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT";
}