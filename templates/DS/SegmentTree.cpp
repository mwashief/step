/*
    Washief Hossain Mugdho
    27 March 2021
    Algorithm FST
*/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <class T, class OP>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = OP()(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
    }

    SegmentTree(vector<T> v)
    {
        n = v.size();
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, T value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = OP()(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = OP::initVal;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = OP()(res, t[l++]);
            if (r & 1)
                res = OP()(res, t[--r]);
        }
        return res;
    }
};

template <class T>
class Max
{
public:
    static const T initVal = numeric_limits<T>::min();
    T operator()(T x, T y)
    {
        return max(x, y);
    }
};

template <class T>
class Min
{
public:
    static const T initVal = numeric_limits<T>::max();
    T operator()(T x, T y)
    {
        return min(x, y);
    }
};

template <class T>
class Add
{
public:
    static const T initVal = T(0);
    T operator()(T x, T y)
    {
        return x + y;
    }
};

int main()
{
    vector<int> a = {54, 756, 674, 6, 26, 23, 625, 624, 56, 246, 254, 437, 47};
    SegmentTree<int, Add<int>> ss(a);
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
        {
            cout << i << ", " << j << ": " << ss.query(i, j) << endl;
        }
}
