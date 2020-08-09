/*
    Washief Hossain Mugdho
    09 August 2020
    LightOJ 1033
*/

#pragma GCC optimize("O3")
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
int memo[105][105];

int dp(int start, int finish)
{
    if(start>=finish) return 0;
    if(memo[start][finish] != -1) return memo[start][finish];
    if(s[start] == s[finish]) return memo[start][finish] = dp(start+1, finish-1);
    return memo[start][finish] = 1 + min(dp(start+1, finish), dp(start,finish-1));
}

int main()
{
    int T;
    cin >> T;
    for(int tt=1; tt<=T; tt++)
    {
        cin >> s;
        ms(memo, -1);
        cout << "Case " << tt << ": " << dp(0, s.size()-1) << endl;
    }
}
