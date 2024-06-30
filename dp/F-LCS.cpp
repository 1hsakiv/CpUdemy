#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define sp << " " <<
#define ms(a, value) memset(a, value, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define N 20000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng used to shuffle syntax below
// shuffle(arr , arr+n , rng);
class Triplet
{
public:
    int x, y, z;
};
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// indexed_set s;
// s.insert(value);
// auto p = s.find_by_order(idx);
// int q = s.order_of_key(value);

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int mod = 1e9 + 7;
// vector <int> adj[N];
// bool visited[N];
// vector<bool> is_prime(N+1, true);
string str = "";
map<int, int> freq;
const double PI = 3.1415926535897;

void IOS()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lcs(string &s, int sl, string &t, int tl, vector<vi> &dp)
{
    if (sl <= 0 || tl <= 0)
        return 0;

    int ans = dp[sl - 1][tl - 1]; 
    if (ans != -1)
        return ans;

    if (s[sl - 1] != t[tl - 1])
    {
        ans = max(lcs(s, sl - 1, t, tl, dp), lcs(s, sl, t, tl - 1, dp));
    }
    else
    {
        ans = 1 + lcs(s, sl - 1, t, tl - 1, dp);
    }
    return dp[sl-1][tl-1] = ans;
}

void traceBack(string &s, string &t, int i, int j, vector<vi> &dp)
{
    if (i <= 0 || j <= 0)
        return;
    if (s[i - 1] == t[j - 1])
    {
        traceBack(s, t, i - 1, j - 1, dp);
        str += s[i - 1];
    }
    else
    {
        if (lcs(s, i - 1, t, j, dp) == lcs(s,i,t,j,dp))
        {
            traceBack(s, t, i - 1, j, dp);
        }
        else
        {
            traceBack(s, t, i, j - 1, dp);
        }
    }
}

int32_t main()
{
    IOS();
    string s, t;
    cin >> s >> t;
    int sl = s.length();
    int tl = t.length();
    vector<vi> dp(sl, vi(tl, -1));
    int maxLength = lcs(s, sl, t, tl, dp);
    traceBack(s, t, sl, tl, dp);
    cout << str;
    return 0;
}