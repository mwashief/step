/*
    Washief Hossain Mugdho
    25 February 2021
    Leetcode 23
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print()
    {
        cout << val;
        if (next == 0)
        {
            cout << endl;
            return;
        }
        cout << " ";
        next->print();
    }
};

ListNode *makeList(int l, int r)
{
    if (l == r)
        return new ListNode(l);
    return new ListNode(l, makeList(l + 1, r));
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = 0;
        ListNode *cur = 0;
        while (1)
        {
            int curVal = INT32_MAX;
            int index = -1;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] == 0)
                    continue;
                if (lists[i]->val <= curVal)
                {
                    curVal = lists[i]->val;
                    index = i;
                }
            }
            if (index == -1)
                return head;
            if (cur == 0)
            {
                cur = new ListNode(curVal);
                head = cur;
            }
            else
            {
                cur->next = new ListNode(curVal);
                cur = cur->next;
            }
            lists[index] = lists[index]->next;
        }
        return head;
    }
};

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    vector<ListNode *> vv;
    for (int i = 5; i <= 7; i++)
        vv.push_back(makeList(1, i));
    Solution s;
    ListNode *temp = s.mergeKLists(vv);
    temp->print();
}
