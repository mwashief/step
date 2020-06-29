#include <bits/stdc++.h>
#define PI 3.14159265
using namespace std;

int main()
{
    double a, b, v, A, s;
    while (1)
    {
        cin >> a >> b >> v >> A >> s;
        if (a + b + v + A + s == 0.0)
            return 0;

        double va = v * cos(A * PI / 180);
        double vb = v * sin(A * PI / 180);
        double xa = va / 2 * s;
        double xb = vb / 2 * s;
        int bounceA = 0;
        int bounceB = 0;
        if (xa > a / 2)
        {
            bounceA++;
            xa -= a / 2;
        }
        if (xb > b / 2)
        {
            bounceB++;
            xb -= b / 2;
        }
        bounceA += xa / a;
        bounceB += xb / b;
        cout << bounceA << " " << bounceB << endl;
    }
}