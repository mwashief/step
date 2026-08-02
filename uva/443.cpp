#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull arr[] = {7, 5, 3, 2};
vector<ull> v;
int d = 0;

void populate(ull passedPower, ull current, ull currentValue)
{
    if (current == 3)
    {
        ull x = 1;
        for (ull i = 0; i <= passedPower; i++)
        {
            v.push_back(currentValue * x);
            x *= arr[current];
            d++;
        }
        return;
    }
    ull x = 1;
    for (ull i = 0; i <= passedPower; i++)
    {
        populate(passedPower - i, current + 1, currentValue * x);
        x *= arr[current];
    }
}

int main()
{
    populate(30, 0, 1);
    sort(v.begin(), v.end());
    ull x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            return 0;
        cout << "The " << x;
        if (x % 10 == 1 && x % 100 != 11)
            cout << "st";
        else if (x % 10 == 2 && x % 100 != 12)
            cout << "nd";
        else if (x % 10 == 3 && x % 100 != 13)
            cout << "rd";
        else
            cout << "th";
        cout << " humble number is " << v[x - 1] << "." << endl;
    }
}
