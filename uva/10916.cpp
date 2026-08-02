#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        int b = (n - 1940) / 10;
        double highest = pow(2, b);
        double fact = 0;
        for (int i = 2;; i++)
        {
            fact += log2(i);
            if (highest <= fact)
            {
                cout << i - 1 << endl;
                break;
            }
        }
    }
}
