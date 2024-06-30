// https://www.spoj.com/problems/HOLI/

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

class Triplet
{
public:
    int x, y, z;
};
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int mod = 1e9 + 7;
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

int dfs(int u, int parent, vector<vector<pair<int, int>>> &adj, int &ans, int n)
{
    int res=1;
    for(pii p : adj[u]){
        int v = p.fi;
        int w = p.se;

        if(v != parent){
            int childSize = dfs(v,u,adj,ans,n);
            int contribution = 2*min(childSize,n-childSize)*w;
            ans += contribution;
            res += childSize;
        }
    }
    return res;
}

int solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n, vector<pii>());
    rep(i, n - 1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    int ans = 0;
    int temp = dfs(0, -1, adj, ans, n);
    return ans;
}

int32_t main()
{
    IOS();
    int cnt = 1;
    w(t)
    {
        int Y = solve();
        cout << "Case #" << cnt << ": " << Y << endl;
        cnt++;
    }
    return 0;
}