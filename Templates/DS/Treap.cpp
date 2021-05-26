#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, 1000000000);
/** Taken from SecondThread
 */
class Treap
{
public:
    int data, priority;
    array<Treap *, 2> kids;
    int subtreeSize, sum, toProp;

    Treap(int data);
};

int size(Treap *me)
{
    return me == NULL ? 0 : me->subtreeSize;
}

void recalc(Treap *me)
{
    if (me == NULL)
        return;
    me->subtreeSize = 1;
    me->sum = me->data + me->toProp * size(me);
    for (Treap *t : me->kids)
        if (t != NULL)
            me->subtreeSize += t->subtreeSize;
    for (Treap *t : me->kids)
        if (t != NULL)
            me->sum += t->sum + t->toProp * size(t);
}

void prop(Treap *me)
{
    if (me == NULL)
        return;
    if (me->toProp == 0)
        return;
    for (Treap *t : me->kids)
        if (t != NULL)
            t->toProp += me->toProp;
    me->data += me->toProp;
    me->toProp = 0;
    recalc(me);
}

Treap *merge(Treap *l, Treap *r)
{
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    prop(l);
    prop(r);
    if (l->priority < r->priority)
    {
        l->kids[1] = merge(l->kids[1], r);
        recalc(l);
        return l;
    }
    else
    {
        r->kids[0] = merge(l, r->kids[0]);
        recalc(r);
        return r;
    }
}

array<Treap *, 2> split(Treap *me, int nInLeft)
{
    if (me == NULL)
        return {NULL, NULL};
    prop(me);
    if (size(me->kids[0]) >= nInLeft)
    {
        array<Treap *, 2> leftRes = split(me->kids[0], nInLeft);
        me->kids[0] = leftRes[1];
        recalc(me);
        return {leftRes[0], me};
    }
    else
    {
        nInLeft = nInLeft - size(me->kids[0]) - 1;
        array<Treap *, 2> rightRes = split(me->kids[1], nInLeft);
        me->kids[1] = rightRes[0];
        recalc(me);
        return {me, rightRes[1]};
    }
    return {NULL, NULL};
}

Treap::Treap(int data)
{
    kids = {NULL, NULL};
    this->data = data;
    recalc(this);
    priority = uid(rng);
}

Treap *rangeAdd(Treap *t, int l, int r, int toAdd)
{
    array<Treap *, 2> a = split(t, l), b = split(a[1], r - l + 1);
    b[0]->toProp += toAdd;
    return merge(a[0], merge(b[0], b[1]));
}

int main()
{
    return 0;
}
