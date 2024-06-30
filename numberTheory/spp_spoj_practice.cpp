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
// #define sz(x) (int)(x).size()
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
int mod = 1e9 + 7;
int sz;
const int M = 20;
// vector <int> adj[N];
// bool visited[N];
// vector<bool> is_prime(N+1, true);
string str;
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

struct Mat
{
    int m[M][M];
    Mat()
    {
        ms(m, 0);
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat &a)
    {
        Mat r;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    r.m[i][j] += (m[i][k] * a.m[k][j]) % mod;
                }
            }
        }
        return r;
    }
};

int solve(int b[], int c[], int e, int n)
{
    // base case
    Mat r, a;
    r.identity();

    a.m[0][0] = 1;
    for (int i = 1; i < sz; i++)
    {
        a.m[0][i] = c[i - 1];
        a.m[1][i] = c[i - 1];
    }

    for (int i = 2; i < sz; i++)
    {
        a.m[i][i - 1] = 1;
    }

    while (e)
    {
        if (e & 1)
            r = r * a;
        a = a * a;
        e = e >> 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += b[i];
    }
    ans = r.m[0][0] * ans;
    ans %= mod;

    for (int i = 1; i < sz; i++)
    {
        ans += r.m[0][i] * b[n - i];
        ans %= mod;
    }
    return ans;
}

int give(int k, int b[], int c[], int n)
{
    if (k < n)
    {
        int ans = 0;
        for (int i = 0; i <= k; i++)
        {
            ans += b[i];
            ans %= mod;
        }
        return ans;
    }
    else
    {
        return solve(b, c, k - n + 1, n);
    }
}

int32_t main()
{
    IOS();
    w(t)
    {
        int n;
        cin >> n;
        int b[n], c[n];
        rep(i, n)
        {
            cin >> b[i];
        }
        rep(i, n)
        {
            cin >> c[i];
        }
        int l, r;
        cin >> l >> r >> mod;
        l--;
        r--;
        sz = n + 1;
        cout << (give(r, b, c, n) - give(l - 1, b, c, n) + mod) % mod << endl;
    }
    return 0;
}