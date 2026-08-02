#include <bits/stdc++.h>
using namespace std;

int traverse(int n, bool evenBad)
{
    if (n <= 1)
        return 1;
    if (evenBad)
    {
        if (n == 2)
        {
            return 1;
        }
        int next;
        if (n & 1)
            next = n / 2 + 1;
        else
            next = n / 2;

        return 2 * traverse(next, n % 2 == 1 ? !evenBad : evenBad) - 1;
    }
    else
    {
        if (n == 2)
        {
            return 2;
        }
        return 2 * traverse(n / 2, n % 2 == 1 ? !evenBad : evenBad);
    }
}

int main()
{
    int x;
    while (1)
    {
        cin >> x;
        if (x <= 0)
            return 0;
        cout << traverse(x, 0) << endl;
    }
}
