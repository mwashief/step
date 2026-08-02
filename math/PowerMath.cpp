
#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;

class Number;
ostream &operator<<(ostream &os, Number &rhs);

double taylor(double x)
{
    double ans = 0;
    double term = -1.0;
    for (int i = 1; i <= 30; i++)
    {
        term = -term * x;
        ans += 1.0 / i * term;
    }
    return ans;
}

class Number
{
public:
    bool negative = false;
    double power = -1.79769e+108;

    Number(int x)
    {
        negative = false;
        if (x < 0)
            negative = true;
        if (x == 0)
            power = -1.79769e+108;
        else
            power = log(abs(x));
    }

    Number()
    {
        negative = false;
        power = -1.79769e+108;
    }

    Number operator+(Number &rhs)
    {
        Number temp;
        double ratio = 1.0;
        temp.negative = rhs.negative;
        if (negative ^ rhs.negative)
        {
            ratio *= -1.0;
            if (power >= rhs.power)
                temp.negative = negative;
        }
        if (power >= rhs.power)
            temp.power = power + taylor(ratio * exp(rhs.power - power));
        else
            temp.power = rhs.power + taylor(ratio * exp(power - rhs.power));
        //cout << *this << " + " << rhs << " = " << temp << endl;
        return temp;
    }

    static Number getMin()
    {
        Number temp;
        temp.negative = true;
        temp.power = 1.79769e+108;
        return temp;
    }

    Number operator-(Number &rhs)
    {
        Number temp(rhs);
        temp.negative ^= 1;
        return *this + temp;
    }
    Number operator-()
    {
        Number temp(*this);
        temp.negative ^= 1;
        //cout << "-" << *this << " = " << temp << endl;
        return temp;
    }

    Number operator*(Number &rhs)
    {
        Number res;
        res.negative = negative ^ rhs.negative;
        res.power = power + rhs.power;
        //cout << *this << " * " << rhs << " = " << res << endl;
        return res;
    }

    Number operator/(Number &rhs)
    {
        Number res;
        res.negative = negative ^ rhs.negative;
        res.power = power - rhs.power;
        //cout << *this << " * " << rhs << " = " << res << endl;
        return res;
    }

    bool operator<(Number &rhs)
    {
        if (negative && !rhs.negative)
            return true;
        if (!negative && rhs.negative)
            return false;
        if (!negative && !rhs.negative)
            return power < rhs.power;
        return power > rhs.power;
    }

    static double taylor(double x)
    {
        double ans = 0;
        double term = -1.0;
        for (int i = 1; i <= 30; i++)
        {
            term = -term * x;
            ans += 1.0 / i * term;
        }
        return ans;
    }
};

ostream &operator<<(ostream &os, Number &rhs)
{
    if (rhs.negative)
        os << "-";
    os << exp(rhs.power);
    return os;
}

int main(int argc, char const *argv[])
{
    Number a(-6), b(-9);
    Number add = a + b;
    Number sub = a - b;
    Number mul = a * b;
    Number div = a / b;
    cout << add << endl;
    cout << sub << endl;
    cout << mul << endl;
    cout << div << endl;
    return 0;
}
