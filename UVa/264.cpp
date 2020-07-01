#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    while (cin >> x)
    {
        long long c = ceil((-1 + sqrt(1 + 8 * x)) / 2);
        long long distance = x - (c - 1) * c / 2;
        cout << "TERM " << x << " IS ";
        if (c & 1)
        {
            cout << c - distance + 1 << "/" << distance;
        }
        else
        {
            cout << distance << "/" << c - distance + 1;
        }
        cout << endl;
    }
}