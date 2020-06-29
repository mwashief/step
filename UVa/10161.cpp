#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;
        long long square = ceil(sqrt(n));
        long long distance = square * square - n;
        long long x = square, y = square;
        if (distance < square - 1)
            y = distance + 1;
        else if (distance > square - 1)
            x = 2 * square - 1 - distance;

        if (square & 1)
            cout << y << " " << x << endl;
        else
            cout << x << " " << y << endl;
    }
}