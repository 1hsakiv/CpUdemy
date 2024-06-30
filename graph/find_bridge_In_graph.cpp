// https://codeforces.com/contest/1986/problem/F
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back


vector<vi> adj;
vi sz;
vi visited;
vi low, discovery;
int ans;
int n;
int timer;

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

void dfs(int node, int parent = -1)
{
    visited[node] = 1;
    sz[node] = 1;
    low[node] = discovery[node] = timer++;

    for (int nbr : adj[node])
    {
        if (nbr == parent)
            continue;
        if (visited[nbr])
        {
            // back edge
            // update the low and discovery value
            low[node] = min(low[node], discovery[nbr]);
        }
        else
        {
            // can be bridge edge
            dfs(nbr, node);
            sz[node] += sz[nbr];
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > discovery[node])
            {
                // this is bridge node
                ans = max(ans, sz[nbr] * (n - sz[nbr]));
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    ans = 0;
    sz.clear();
    sz.assign(n, 0);
    visited.assign(n, 0);
    discovery.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int32_t main()
{
    IOS();
    w(t)
    {
        int m;
        cin >> n >> m;

        adj.clear();
        adj.assign(n + 1, vi(0, 0));

        rep(i, m)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        find_bridges();
        int total = (n * (n - 1)) / 2;
        cout << total - ans << endl;
    }
    return 0;
}