#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, pair<int, int> p)
{
    os << p.first << "/" << p.second;
    return os;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    double x = 1.0 * a.first / a.second;
    double y = 1.0 * b.first / b.second;
    return x < y;
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        vector<pair<int, int>> v;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1)
                {
                    v.push_back(make_pair(j, i));
                }
            }
        }
        v.push_back(make_pair(1, 1));
        sort(v.begin(), v.end(), comp);
        cout << v[k - 1] << endl;
        ;
    }
}
