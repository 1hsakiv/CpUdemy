#include <bits/stdc++.h>

using namespace std;

const int N = 1e5, M = 20;

vector<int> adj[N];
int depth[N], Parent[N][M];

// O(N*M)
void dfs(int u, int par)
{
    depth[u] = depth[par] + 1;
    Parent[u][0] = par;

    for (int j = 1; j <= M - 1; j++)
    {
        Parent[u][j] = Parent[Parent[u][j - 1]][j - 1];
    }

    for (auto v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
        }
    }
}

// O(M) = logN
int LCA(int u, int v)
{
    if (u == v)
        return u;
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            u = Parent[u][j];
        }
    }

    // on the same level
    for (int j = M - 1; j >= 0; j--)
    {
        if (Parent[u][j] != Parent[v][j])
        {
            u = Parent[u][j];
            v = Parent[v][j];
        }
    }

    return Parent[u][0];
}

// O(1)
int LengthFromUtoV(int u, int v)
{
    int lca = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    // for (int i = 1; i <= 12; i++) {
    // 	cout << i << "-> ";
    // 	for (int j = 0; j < 4; j++) {
    // 		cout << Parent[i][j] << " ";
    // 	} cout << '\n';
    // }

    // for (int i = 1; i <= n; i++) {
    // 	cout << i << " " << depth[i] << '\n';
    // }
    cout << "LCA" << endl;
    cout << LCA(9, 12) << '\n';
    cout << LCA(10, 8) << '\n';
    cout << LCA(9, 11) << '\n';

    cout << "pathLength" << endl;
    cout << LengthFromUtoV(9, 12) << '\n';
    cout << LengthFromUtoV(10, 8) << '\n';

    for (int u = 1; u <= 12; u++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << Parent[u][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Test Case
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

// expected output

// LCA
// 1
// 2
// 8
// pathLength
// 7
// 4
// 0 0 0 0 0 
// 1 0 0 0 0 
// 1 0 0 0 0 
// 2 1 0 0 0 
// 2 1 0 0 0 
// 2 1 0 0 0 
// 3 1 0 0 0 
// 5 2 0 0 0 
// 8 5 1 0 0 
// 4 2 0 0 0 
// 8 5 1 0 0 
// 7 3 0 0 0 
