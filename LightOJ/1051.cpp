/*
    Washief Hossain Mugdho
    09 August 2020
    LightOJ 1051
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

int memo[60][10][10];
string s;
string p[] = {"", "BAD", "GOOD", "MIXED"};

inline bool isVowel(char c)
{
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int dp(int n, int vowels, int consonents)
{
    if(vowels>=3 || consonents>=5) return 1;
    if(n>=s.size()) return 2;
    if(memo[n][vowels][consonents]) return memo[n][vowels][consonents];
    if(s[n] == '?')
        return memo[n][vowels][consonents] = dp(n+1, vowels+1, 0) | dp(n+1, 0, consonents+1);
    if(isVowel(s[n])) return memo[n][vowels][consonents] = dp(n+1, vowels+1, 0);
    return memo[n][vowels][consonents] = dp(n+1, 0, consonents+1);
}


int main()
{
    int T;
    cin >> T;
    for(int tt=1; tt<=T; tt++)
    {
        ms(memo, 0);
        cin >> s;
        cout << "Case " << tt << ": " << p[dp(0,0,0)] << endl;
    }
}
