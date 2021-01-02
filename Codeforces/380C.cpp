/*
    Washief Hossain Mugdho
    21 December 2020
    Codeforces 380C
*/

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
string s;
int q;
vector<int> leftp;
vector<int> rightp;
vector<int> correct;

void build(int node, int start, int end)
{
    if (start == end)
    {
        leftp[node] = s[start] == '(';
        rightp[node] = s[start] == ')';
        correct[node] = 0;
        return;
    }
    int leftNode = (node << 1) + 1;
    int rightNode = (node << 1) + 2;
    int mid = (start + end) >> 1;
    build(leftNode, start, mid);
    build(rightNode, mid + 1, end);
    int newCorrect = min(leftp[leftNode], rightp[rightNode]);
    correct[node] = correct[leftNode] + correct[rightNode] + newCorrect;
    leftp[node] = leftp[leftNode] + leftp[rightNode] - newCorrect;
    rightp[node] = rightp[leftNode] + rightp[rightNode] - newCorrect;
}

pair<int, pair<int, int>> query(int node, int l, int r, int start, int end)
{
    if (start > r || end < l)
        return {0, {0, 0}};
    if (l <= start && r >= end)
        return {correct[node], {leftp[node], rightp[node]}};
    int leftNode = (node << 1) + 1;
    int rightNode = (node << 1) + 2;
    int mid = (start + end) >> 1;
    auto leftRes = query(leftNode, l, r, start, mid);
    auto rightRes = query(rightNode, l, r, mid + 1, end);
    pair<int, pair<int, int>> res = {0, {0, 0}};
    int newCorrect = min(leftRes.sc.fr, rightRes.sc.sc);
    res.fr = leftRes.fr + rightRes.fr + newCorrect;
    res.sc.fr = leftRes.sc.fr + rightRes.sc.fr - newCorrect;
    res.sc.sc = leftRes.sc.sc + rightRes.sc.sc - newCorrect;
    return res;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> s >> q;
    leftp = vector<int>(s.size() * 4, 0);
    rightp = vector<int>(s.size() * 4, 0);
    correct = vector<int>(s.size() * 4, 0);
    build(0, 0, s.size() - 1);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << query(0, x - 1, y - 1, 0, s.size() - 1).fr * 2 << endl;
    }
}
