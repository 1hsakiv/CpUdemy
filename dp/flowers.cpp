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

int n;
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

int calc(vector<vi> &nums, int flower, int prevHeight, vector<vi> &dp)
{
    if (flower == n)
    {
        return 0;
    }
    if (dp[flower][prevHeight] != -1)
        return dp[flower][prevHeight];
    int ans = 0;
    // when you cannot choose flower
    if (nums[flower][0] <= prevHeight)
    {
        ans += calc(nums, flower + 1, prevHeight, dp);
    }
    else
    {
        // when you can choose flower
        ans += max(nums[flower][1] + calc(nums, flower + 1, nums[flower][0], dp), calc(nums, flower + 1, prevHeight, dp));
    }
    return dp[flower][prevHeight] = ans;
}

int32_t main()
{
    IOS();
    // int n;
    cin >> n;
    vector<vi> nums(n, vi(2, 0));
    rep(i, n)
    {
        cin >> nums[i][0];
    }
    rep(i, n)
    {
        cin >> nums[i][1];
    }
    vector<vi> dp(n + 1, vi(n + 1, -1));
    cout << calc(nums, 0, 0, dp);
    return 0;
}