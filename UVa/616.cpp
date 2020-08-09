#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll log2base(ll x)
{
    ll i;
    for (i = 0; x >= 1; x /= 2, i++)
        ;
    return i;
}

bool possible(ll coco, ll person)
{
    for (int i = 1; i <= person; i++)
    {
        coco--;
        if (coco % person != 0)
            return false;
        coco /= person;
        coco *= (person - 1);
    }
    if (coco % person == 0)
        return true;
    return false;
}

int main()
{
    ll x;
    bool flag = false;
    while (1)
    {
        cin >> x;
        if (x < 0)
            break;
        flag = false;
        if (x == 0)
        {
            cout << "0 coconuts, no solution\n";
            continue;
        }
        for (ll i = log2base(x); i >= 2; i--)
        {
            if (possible(x, i))
            {
                cout << x << " coconuts, " << i << " people and 1 monkey\n";
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        cout << x << " coconuts, no solution\n";
    }
}
