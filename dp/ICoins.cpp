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
#define ld long double
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
string str;
map<int, int> freq;
const double PI = 3.1415926535897;

int n;
ld p[3001];
ld dp[3001][3001];

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

ld calc(int i, int h, int t)
{
    if (i == n)
    {
        return 1.00;
    }

    if (dp[i][h] != -1.00)
    {
        return dp[i][h];
    }

    ld ans = 0.00f;
    if (h)
    {
        ans += calc(i + 1, h - 1, t) * p[i];
    }
    if (t)
    {
        ans += calc(i + 1, h, t - 1) * (1.00 - p[i]);
    }
    return dp[i][h] = ans;
}

int32_t main()
{
    IOS();
    cin >> n;
    rep(i, n)
    {
        cin >> p[i];
    }
    rep(i, 3001)
    {
        rep(j, 3001)
        {
            dp[i][j] = -1.00;
        }
    }
    ld ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += calc(0, i, n - i);
    }
    cout << setprecision(10) << fixed;
    cout << ans;
    return 0;
}