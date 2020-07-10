#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int x;
    while (cin >> x)
    {
        if (x == 0)
            return 0;
        vector<int> all;
        all.push_back(x);
        int minimum = x;
        while (cin >> x)
        {
            if (x == 0)
                break;
            minimum = min(minimum, x);
            all.push_back(x);
        }
        for (int i = 0; i < all.size(); i++)
            all[i] -= minimum;
        int ans = gcd(all[0], all[1]);
        for (int i = 2; i < all.size(); i++)
            ans = gcd(ans, all[i]);
        cout << ans << endl;
    }
    return 0;
}
