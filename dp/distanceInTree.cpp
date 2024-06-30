#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100005; // maximum number of nodes
const int LOG = 17;      // log2(MAXN) rounded up

vector<int> adj[MAXN]; // adjacency list for the tree
int up[MAXN][LOG];     // up[v][j] is the 2^j-th ancestor of node v
int depth[MAXN];       // depth of each node from the root

// Preprocessing function to compute up and depth arrays
void dfs(int v, int parent)
{
    up[v][0] = parent; // the first ancestor of v is its parent
    for (int i = 1; i < LOG; i++)
    {
        if (up[v][i - 1] != -1)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        else
        {
            up[v][i] = -1;
        }
    }
    for (int u : adj[v])
    {
        if (u != parent)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Function to find LCA of nodes u and v
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
    {
        if ((diff >> i) & 1)
        {
            u = up[u][i];
        }
    }

    if (u == v)
        return u;

    // Binary lifting to find LCA
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main()
{
    int n, k;
    cin >> n >> k;

    // Read the edges
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize up array with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < LOG; j++)
        {
            up[i][j] = -1;
        }
    }

    // Preprocess the tree to fill up and depth arrays
    dfs(1, -1); // Assuming 0 is the root of the tree

    // Read the number of queries
    // cin >> m;
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     cout << "LCA of " << u << " and " << v << " is: " << lca(u, v) << endl;
    // }

    int ans = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << depth[i] << " ";
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int d = depth[i] + depth[j] - 2 * depth[lca(i, j)];
            if (d == k)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
