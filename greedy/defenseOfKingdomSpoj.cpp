// https://www.spoj.com/problems/DEFKIN/
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

int n, m;

void makeWall(vector<vi> &nums, vector<pii> &tow, vector<vi> &visited)
{
    for (pii p : tow)
    {
        for (int i = 0; i < n; i++)
        {
            nums[i][p.se] = 0;
            visited[i][p.se] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            nums[p.fi][i] = 0;
            visited[p.fi][i] = 0;
        }
    }
}

int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    visited[x][y] = 1;
    int res = 1;
    for (int i = 0; i < 4; i++)
    {
        int newx = dx[i] + x;
        int newy = dy[i] + y;
        if (newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() && !visited[newx][newy] && grid[newx][newy] == 0)
        {
            res += dfs(newx, newy, grid, visited);
        }
    }
    return res;
}

int32_t main()
{
    IOS();
    w(t)
    {
        int p;
        cin >> n >> m >> p;
        vi xpoint, ypoint;
        rep(i, p)
        {
            int x, y;
            cin >> x >> y;
            xpoint.pb(x);
            ypoint.pb(y);
        }

        xpoint.pb(0);
        // xpoint.pb(n);

        ypoint.pb(0);
        // ypoint.pb(m);

        sort(all(xpoint));
        sort(all(ypoint));

        // for (int x : xpoint)
        //     cout << x << " ";
        // cout << endl;
        // for (int x : ypoint)
        //     cout << x << " ";
        // cout << endl;

        vi distx, disty;

        for (int i = 1; i < xpoint.size(); i++)
        {
            distx.pb(xpoint[i] - xpoint[i - 1] - 1);
        }

        distx.pb(n - xpoint.back());
        

        for (int i = 1; i < ypoint.size(); i++)
        {
            disty.pb(ypoint[i] - ypoint[i - 1] - 1);
        }

        disty.pb(m - ypoint.back());

        // for(int x : distx) cout<<x<<" ";
        // cout<<endl;

        // for(int x : disty) cout<<x<<" ";
        // cout<<endl;

        int l = *max_element(all(distx));
        int b = *max_element(all(disty));

        cout << (l) * (b) << endl;
    }
    return 0;
}