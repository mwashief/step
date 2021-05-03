/*
    Washief Hossain Mugdho
    05 March 2021
    Algorithm SegmentTree
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class SegmentTree
{
private:
    void propagate(int node, T val, int nodes)
    {
        tree[node] += val * (T)nodes;
        lazy[node] += val;
    }

    T buildUtil(vector<T> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return tree[node];
        }
        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        return tree[node] = buildUtil(a, leftNode, l, mid) + buildUtil(a, rightNode, mid + 1, r);
    }

    T queryUtil(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return (T)0;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0;
        }
        return queryUtil(leftNode, l, mid, ql, qr) + queryUtil(rightNode, mid + 1, r, ql, qr);
    }

    T updateUtil(int node, int l, int r, int ql, int qr, T val)
    {
        if (ql > r || qr < l)
            return tree[node];
        if (l >= ql && r <= qr)
        {
            tree[node] += val * (r - l + 1);
            lazy[node] += val;
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0;
        }
        return tree[node] = updateUtil(leftNode, l, mid, ql, qr, val) + updateUtil(rightNode, mid + 1, r, ql, qr, val);
    }

public:
    int n;
    vector<T> tree;
    vector<T> lazy;
    SegmentTree(int n)
    {
        this->n = n;
        tree = vector<T>(4 * n);
        lazy = vector<T>(4 * n);
    }

    void build(vector<T> &a)
    {
        buildUtil(a, 0, 0, n - 1);
    }

    SegmentTree(vector<T> &a)
    {
        this->n = a.size();
        tree = vector<T>(4 * n);
        lazy = vector<T>(4 * n);
        build(a);
    }

    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(int l, int r, T val)
    {
        updateUtil(0, 0, n - 1, l, r, val);
    }
};

int main()
{

    vector<int> a = {3, 5, 8, 4, 8};
    SegmentTree<int> s(a);
    s.update(4, 4, 25);
    cout << s.query(1, 3);
    cout << s.query(2, 4);
}
