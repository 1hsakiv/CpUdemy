#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ms(a, value) memset(a, value, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define N 20000000
const int mod = 1e9 + 7;
vector<int> adj[N];
bool visited[N];

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

vi order;
void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }

    // this this pushing the top recursive stack to the 
    // order vector
    order.pb(u);
}


int32_t main()
{
    IOS();
    w(t)
    {
        int n, m;
        cin >> n >> m;
        rep(i, m)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }

        for (int i = 1; i <= n; i++)
        {
            if(visited[i] == 0){
                dfs(i);
            }
        }

        reverse(all(order));

        for (int x : order)
            cout << x << " ";
    }
    return 0;
}

// for topo sorting graph must be DAG
// directed acyclic graph
// if graph contain any cycle this algo will
// give wrong answer
// for cycle detection use backedge concept

// Test Case

// 1
// 5 6
// 1 5
// 1 2
// 2 4
// 2 5
// 3 1
// 3 2

// 3 1 2 4 5 