// https://cses.fi/problemset/task/1686/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rsz resize

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define R0F(i, a) for (int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for (int i = (b); i >= a; i--)
#define trav(a, x) for (auto &a : x)

/* SCC from BenQ */
struct SCC
{
    int N;
    vector<vi> adj, radj;
    vi order, comps, comp;
    vector<bool> visited;

    void init(int _N)
    {
        N = _N;
        adj.rsz(N), radj.rsz(N), comp = vi(N, -1), visited.rsz(N);
    }

    void addEdge(int x, int y)
    {
        // adjecency list
        adj[x].pb(y);
        // reverse adjecency list
        radj[y].pb(x);
    }

    void dfs(int x)
    {
        visited[x] = 1;
        trav(y, adj[x]) if (!visited[y]) dfs(y);
        order.pb(x);
    }

    void dfs2(int x, int v)
    {
        comp[x] = v;
        trav(y, radj[x]) if (comp[y] == -1) dfs2(y, v);
    }

    void gen(int _N)
    { // fills allComp
        FOR(i, 1, _N)
        if (!visited[i])
            dfs(i);
        reverse(all(order));
        trav(x, order) if (comp[x] == -1)
        {
            dfs2(x, x);
            comps.pb(x);
        }
    }
};

const int maxn = 1e5 + 5;

int n, m;
SCC scc;            // scc
int coin[maxn];     // coin of each room
ll GroupCoin[maxn]; // coin in each SCC
vi rgraph[maxn];    // reverse graph
ll dp[maxn];

// calculates dp[i]
ll DP(int i)
{
    if (dp[i])
        return dp[i];
    // start at i
    dp[i] = GroupCoin[i];
    // simulate traveling from another SCC to this SCC
    trav(j, rgraph[i]) dp[i] = max(dp[i], DP(j) + GroupCoin[i]);
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    scc.init(n + 1);
    FOR(i, 1, n)
    cin >> coin[i];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        scc.addEdge(a, b);
    }

    // generate SCC
    scc.gen(n);
    // set dp to 0
    fill(dp + 1, dp + n + 1, 0);
    // precompute GroupCoin coin for each SCC
    FOR(i, 1, n)
    GroupCoin[scc.comp[i]] += coin[i];
    // create reverse edges for SCC
    FOR(i, 1, n)
    trav(j, scc.adj[i])
    {
        if (scc.comp[i] == scc.comp[j])
            continue;
        rgraph[scc.comp[j]].pb(scc.comp[i]);
    }
    // find dp coin for each SCC
    ll ans = 0;
    trav(i, scc.comps) ans = max(ans, DP(i));

    cout << ans << '\n';
}