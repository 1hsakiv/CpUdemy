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

vector<int> adj[N];
int depth[N];
int parent[N];

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

void dfs(int u, int par)
{
    parent[u] = par;
    depth[u] = depth[par] + 1;
    for (auto v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
        }
    }
}

int lca(int u, int v)
{
    if (u == v)
        return u;
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];
    while (diff--)
    {
        u = parent[u];
    }

    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int32_t main()
{
    IOS();
    int n;
    cin >> n;
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    cout << lca(9, 6);

    return 0;
}

// Test case
// 12
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7
// 4 10
// 5 8
// 7 12
// 8 9
// 8 11

// here lcs of 9 and 6 is 2