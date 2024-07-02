// https://cses.fi/problemset/task/1683
// concept used topo sort , kosaraju , , strongly connected component
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
#define N 200000
const int mod = 1e9 + 7;
vector<int> adj1[N];
vector<int> adj2[N];
bool visited1[N];
bool visited2[N];
bool visited3[N];
bool visited4[N];

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

vi order, condensed_order;
void dfs(int u)
{
    visited1[u] = 1;
    for (auto v : adj1[u])
    {
        if (visited1[v] == 0)
        {
            dfs(v);
        }
    }

    // this this pushing the top recursive stack to the
    // order vector
    order.pb(u);
}

void dfs_on_reverse(int u, vi &scc)
{
    visited2[u] = 1;
    scc.pb(u);
    for (int v : adj2[u])
    {
        if (visited2[v] == 0)
        {
            dfs_on_reverse(v, scc);
        }
    }
}

void dfs_on_condensed(int u, vector<vector<int>> &adj_scc)
{
    visited3[u] = 1;
    for (auto v : adj_scc[u])
    {
        if (visited3[v] == 0)
        {
            dfs_on_condensed(v, adj_scc);
        }
    }

    // this this pushing the top recursive stack to the
    // order vector
    condensed_order.pb(u);
}

void dfs_max_sum(int u, vi &condensed_coin, vector<vi> &adj_scc, int &ans, int currSum)
{
    visited4[u] = 1;
    int sum = currSum + condensed_coin[u];
    for (int v : adj_scc[u])
    {
        if (visited4[v] == 0)
        {
            dfs_max_sum(v, condensed_coin, adj_scc, ans, sum);
        }
    }
    if (adj_scc[u].size() == 0)
    {
        ans = max(ans, sum);
    }
    return;
}

int32_t main()
{
    // IOS();

    int n, m;
    cin >> n >> m;

    vi coin(n + 1, 0);
    rep(i, n) cin >> coin[i + 1];

    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj1[x].pb(y);
        adj2[y].pb(x);
    }

    // doing topo sort
    for (int i = 1; i <= n; i++)
    {
        if (visited1[i] == 0)
        {
            dfs(i);
        }
    }

    reverse(all(order));

    // now applying dfs on reverse graph using topo sort vector

    vector<int> roots(n + 1, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n + 1);
    vector<vector<int>> adj_scc_reverse(n + 1);
    vi condensed_coin(n + 1, 0);

    vector<vi> scc;
    for (int x : order)
    {
        if (visited2[x] == 0)
        {
            vi scc_component;
            dfs_on_reverse(x, scc_component);

            int root = scc_component.front();
            int sum_component = 0;
            for (auto u : scc_component)
            {
                roots[u] = root;
                sum_component += coin[u];
            }
            root_nodes.push_back(root);
            condensed_coin[root] = sum_component;

            scc.pb(scc_component);
        }
    }

    for (int v = 1; v <= n; v++)
        for (auto u : adj1[v])
        {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
            {
                adj_scc[root_v].push_back(root_u);
                // adj_scc_reverse[root_u].push_back(root_v);
            }
        }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (adj_scc[i].size() == 0)
    //         continue;
    //     for (int u : adj_scc[i])
    //     {
    //         cout << i << " " << u << endl;
    //     }
    // }

    for (int i = 0; i < root_nodes.size(); i++)
    {
        if (visited3[root_nodes[i]] == 0)
        {
            dfs_on_condensed(root_nodes[i], adj_scc);
        }
    }
    reverse(all(condensed_order));
    int ans = 0;
    int currSum = 0;
    for (int x : condensed_order)
    {
        if (visited4[x] == 0)
        {
            dfs_max_sum(x, condensed_coin, adj_scc, ans, currSum);
        }
    }
    cout << ans << endl;
    return 0;
}