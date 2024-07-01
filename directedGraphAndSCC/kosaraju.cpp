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
vector<int> adj1[N];
vector<int> adj2[N];
bool visited1[N];
bool visited2[N];

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
        

        vector<vi> scc;

        for (int x : order)
        {
            if (visited2[x] == 0)
            {
                vi scc_component;
                dfs_on_reverse(x, scc_component);
                scc.pb(scc_component);
            }
        }

        for (vi v : scc)
        {
            for (int x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}