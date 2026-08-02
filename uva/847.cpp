#include <bits/stdc++.h>
using namespace std;

bool traverse(long long range, bool result)
{
    if (range == 1)
        return result;
    if (result)
        return traverse(ceil(1.0 * range / 2), false);
    return traverse(ceil(1.0 * range / 9), true);
}

int main()
{
    long long a;
    while (cin >> a)
    {
        if (traverse(ceil(1.0 * a / 9), true))
            cout << "Stan ";
        else
            cout << "Ollie ";
        cout << "wins." << endl;
    }
}
