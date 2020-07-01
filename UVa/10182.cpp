#include <bits/stdc++.h>
using namespace std;

int findX(int n)
{
    if (n == 0)
        return 0;
    int stage = ceil(sqrt(n / 3.0) - 1);
    int distance = n - 3 * stage * stage;
    int x = stage * -1;
    x += min(distance, 2 * stage);
    if (distance > 3 * stage + 1)
    {
        x -= min(distance - 3 * stage - 1, 2 * stage + 1);
    }
    return x;
}

int findY(int n)
{
    if (n == 0)
        return 0;
    int stage = ceil((-1.0 + sqrt(1.0 + 3.0 * n)) / 3.0);
    int y = 1 - stage;
    int distance = n - 3 * stage * stage + 4 * stage - 1;
    y += min(distance, 2 * stage - 1);
    if (distance > 3 * stage - 1)
    {
        y -= min(distance - 3 * stage + 1, 2 * stage);
    }
    return y;
}

int main()
{
    int n;
    while (cin >> n)
    {
        n--;
        cout << findX(n) << " " << findY(n) << endl;
    }
}