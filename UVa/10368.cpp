#include <bits/stdc++.h>
using namespace std;

bool traverse(int a, int b)
{
    if (b == 1)
        return true;
    if (b == 0)
        return false;
    if (!traverse(b, a % b))
        return true;
    if (a / b == 1)
        return false;
    return true;
}

int main()
{
    int a, b;
    while (cin >> a >> b && a)
    {
        if (traverse(max(a, b), min(a, b)))
            cout << "Stan ";
        else
            cout << "Ollie ";
        cout << "wins" << endl;
    }
}
